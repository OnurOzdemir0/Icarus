// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGladiator.h"
#include "Animation/AnimMontage.h"
#include "AI_Gladiator.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h" 
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseGladiator::ABaseGladiator()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	FireRate = 1.0f;
	Accuracy = 0.5f;
	Armor = 0.2f;
	Agility = 10.3f;
	TimeSinceLastMove = 0.0f;
	Health = 50.0f;
	Damage = 10.0f;

	//hit miss ratio for debug purposes
	_hitCount = 0;
	_missCount = 0;
	
}

void ABaseGladiator::BeginPlay()
{
	Super::BeginPlay();
	CanMove = true;
	
	FindOpponent();
}

void ABaseGladiator::Attack()
{
	_bonus = 0;
	IsAttacking = true;
	if (OpponentGladiator)
	{
		int dice = FMath::RandRange(1, 20); //20 sided dice, 1-5 malfunction, 6-10 hit, 10-20 +bonus
		if(dice<5) //Miss: malfunction
		{
		Malfunction = true;
		_missCount++;

		stringAction = "Malfunction";	
		return;	
		}
		else if(dice>10)
		{
			_bonus = (dice - 10);
		}
		
		Aim();
		if (OpponentGladiator->IsDodging)  //Miss: shot dodged
		{
			_missCount++;
			OpponentGladiator->IsDodging = false;  //already dodged 1, can't dodge again, without moving again

			stringAction = "Missed";
			return;
		}
		FVector RayStart = GetActorLocation();
		FVector ForwardVector = GetActorForwardVector();
		FVector RayEnd = ((ForwardVector * 3000.f) + RayStart); 
		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
	
		bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, RayStart, RayEnd, ECC_Pawn, CollisionParams);
		if(bHit)
		{
			DrawDebugLine(GetWorld(), RayStart, RayEnd, FColor::Red, false, 1, 0, 3);
			AActor* ActorHit = HitResult.GetActor();
			
			ABaseGladiator* HitGladiator = Cast<ABaseGladiator>(ActorHit);
			if (HitGladiator)  // if we hit a ABaseGladiator type actor
			{
				HitGladiator->Health -= Damage+ _bonus;
				if (HitGladiator->Health <= 0)
				{
					HitGladiator->Destroy();
					stringAction = "Won";
				}
				_hitCount++;
				stringAction = "shot successful";
			}
		}
		
	}
	
	PlayAnimMontage(AttackMontage, 1.3f);
	IsAttacking = false;
}

void ABaseGladiator::Move(float Direction, float Speed)
{
	IsDodging = true;
	AddMovementInput(FVector(0.f, Direction, 0.f), Speed, true);
	GetCharacterMovement()->AddImpulse(FVector(0.f, Direction*200000, 0.f));
}

void ABaseGladiator::FindOpponent()
{
	TArray<AActor*> FoundGladiators;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseGladiator::StaticClass(), FoundGladiators);
	for (AActor* FoundActor : FoundGladiators)
	{
		if (FoundActor != this)  
		{
			OpponentGladiator = Cast<ABaseGladiator>(FoundActor);
			break;
		}
	}
}

void ABaseGladiator::Aim()
{
	FVector TargetLocation = OpponentGladiator->GetActorLocation();
	FVector Direction = TargetLocation - GetActorLocation();
	Direction.Normalize();
	FRotator TargetRotation = Direction.Rotation();
	TargetRotation.Pitch = 0.0f;  
	TargetRotation.Roll = 0.0f;
	SetActorRotation(TargetRotation);
}

void ABaseGladiator::UpgradeFireRate()
{
	FireRate += 0.1f;
}

void ABaseGladiator::UpgradeAccuracy()
{
	Accuracy += 0.05f;
}

void ABaseGladiator::UpgradeArmor() 
{
	Armor += 0.05f;
}

void ABaseGladiator::UpgradeAgility()
{
	Agility += 0.05f;
}

void ABaseGladiator::UpgradeDamage()
{
	Damage += 0.05f;
}

// Called every frame
void ABaseGladiator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ABaseGladiator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}