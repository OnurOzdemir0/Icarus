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
	IsAttacking = true;
	if (OpponentGladiator)
	{
		Aim();
		if (OpponentGladiator->IsDodging)  //Miss: dodged already
		{
			_missCount++;
			OpponentGladiator->IsDodging = false;
			return;
		}
		
		if(FMath::RandRange(1, 20)<5) //Miss: malfunction
		{
			Malfunction = true;
			_missCount++;
			return;	
		}
		
		//Shoot():
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
			if (HitGladiator)  // if we hit a gladiator
			{
				GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, FString::Printf(TEXT("Hit: %s Health %f"), *HitGladiator->GetName(), HitGladiator->Health), true, FVector2D(3.f, 3.f));
				HitGladiator->Health -= Damage;
				if (HitGladiator->Health <= 0)
					HitGladiator->Destroy();
				
				_hitCount++;
			}
		}
		
	}
	
	PlayAnimMontage(AttackMontage, 1.3f);
	IsAttacking = false;
	
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Gladiator: %s Hit: %d, Miss: %d"),*this->GetName(), _hitCount, _missCount), true, FVector2D(3.f, 3.f)); 
}

void ABaseGladiator::Move(float Direction, float Speed)
{
	IsDodging = true;
	AddMovementInput(FVector(0.f, Direction, 0.f), Speed, true);
	GetCharacterMovement()->AddImpulse(FVector(0.f, Direction*Speed*3000, 0.f));
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