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
	
	// Initialize attributes
	FireRate = 1.0f;
	Accuracy = 0.5f;
	Armor = 0.2f;
	Agility = 10.3f;
	TimeSinceLastMove = 0.0f;
	Health = 30.0f;
	Damage = 10.0f;

	TargetGladiator = GetTargetGladiator();
}

// Called when the game starts or when spawned
void ABaseGladiator::BeginPlay()
{
	Super::BeginPlay();
	CanMove = true;
}

// Called every frame
void ABaseGladiator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector TargetLocation = TargetGladiator->GetActorLocation();
	FVector Direction = TargetLocation - GetActorLocation();
	Direction.Normalize();

	FRotator TargetRotation = Direction.Rotation();
	TargetRotation.Pitch = 0.0f; 
	TargetRotation.Roll = 0.0f;

	FRotator CurrentRotation = GetActorRotation();
	FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, 2.0f); 

	SetActorRotation(NewRotation);
	
}

// Called to bind functionality to input
void ABaseGladiator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseGladiator::Attack()
{
	IsAttacking = true;
	TargetGladiator = GetTargetGladiator();
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
		// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("hit")));
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
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Damaged Gladiator")));
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Hit something else")));
			}
		}
	}
	else
	{
		DrawDebugLine(GetWorld(), RayStart, RayEnd, FColor::Red, false, 1, 0, 1);
		// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("no")));
	}
	
	PlayAnimMontage(AttackMontage, 1.3f);
	IsAttacking = false;
	
}

void ABaseGladiator::Move(float Direction, float Speed)
{
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Direction: %f"), Direction));
	// GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, FString::Printf(TEXT("Speed: %f"), Speed));
	
	AddMovementInput(FVector(0.f, Direction, 0.f), Speed, true);
	GetCharacterMovement()->AddImpulse(FVector(0.f, Direction*Speed*1000, 0.f));
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

ABaseGladiator* ABaseGladiator::GetTargetGladiator()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseGladiator::StaticClass(), FoundActors);
    
	if(FoundActors.Num() > 1)  // 1 is this Gladiator already
		{
		int32 RandomIndex = FMath::RandRange(0, FoundActors.Num() - 1); 
		ABaseGladiator* RandomGladiator = Cast<ABaseGladiator>(FoundActors[RandomIndex]);
        
		if(RandomGladiator != Cast<ABaseGladiator>(this))
			return RandomGladiator;
		else
			return GetTargetGladiator();  // Recursive approach
		}
	else
	{
		return nullptr;  // Return null if no target found
	}
}
