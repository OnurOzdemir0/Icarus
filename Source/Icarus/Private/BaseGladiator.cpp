// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseGladiator.h"
#include "Animation/AnimMontage.h"
#include "AI_Gladiator.h"


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
}

// Called when the game starts or when spawned
void ABaseGladiator::BeginPlay()
{
	Super::BeginPlay();

	CanMove = true;

	RandomDirection = FMath::RandRange(-1.f, 1.f);
	DodgeDirection = FVector(0.f, RandomDirection, 0.f);
	
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

void ABaseGladiator::Attack()
{
	IsAttacking = true;
	
	// PlayAnimMontage(AttackMontage, 1.f);

}

void ABaseGladiator::Move(float Direction, float Speed)
{
	AddMovementInput(FVector(0.f, Direction, 0.f), Speed);
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


