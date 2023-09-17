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
	Health = 300.0f;
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

	//Shoot():
		FVector RayStart = GetActorLocation();
		FVector ForwardVector = GetActorForwardVector();
		FVector RayEnd = ((ForwardVector * 2000.f) + RayStart); 
		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
	
		bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, RayStart, RayEnd, ECC_Pawn, CollisionParams);
		if(bHit)
		{
			DrawDebugLine(GetWorld(), RayStart, RayEnd, FColor::Green, false, 1, 0, 1);
			AActor* ActorHit = HitResult.GetActor();

			if (ActorHit)
			{
				ABaseGladiator* HitGladiator = Cast<ABaseGladiator>(ActorHit);
				if (HitGladiator)
				{
					HitGladiator->Health -= Damage;
					if (HitGladiator->Health <= 0)
					{
						HitGladiator->Health = 0;
						HitGladiator->Destroy();
					}
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%s health: %f"), *HitGladiator->GetName(), HitGladiator->Health));
					_hitCount++;
				}
			}
			else
			{
				_missCount++;
			}
		}
		else
		{
			DrawDebugLine(GetWorld(), RayStart, RayEnd, FColor::Red, false, 1, 0, 1);
			_missCount++;
		}
	}
	
	PlayAnimMontage(AttackMontage, 1.3f);
	IsAttacking = false;
	
}

void ABaseGladiator::Move(float Direction, float Speed)
{
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