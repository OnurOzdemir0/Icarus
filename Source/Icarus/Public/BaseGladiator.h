// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseGladiator.generated.h"

// Forward declarations
class UAnimMontage;

UCLASS()
class ICARUS_API ABaseGladiator : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseGladiator();
	void FindOpponent();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Attributes
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Attributes")
	bool IsAttacking;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Attributes")
	bool CanMove;
	
	// Robot Stats
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float FireRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Accuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Armor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Agility;
	
	// Actions
	UFUNCTION(BlueprintCallable, Category = "Robot Actions")
	void Attack();

	UFUNCTION(BlueprintCallable, Category = "Robot Actions")
	void Move(float Direction, float Speed);

	// Upgrades
	UFUNCTION(BlueprintCallable, Category = "Robot Upgrades")
	void UpgradeFireRate();

	UFUNCTION(BlueprintCallable, Category = "Robot Upgrades")
	void UpgradeAccuracy();

	UFUNCTION(BlueprintCallable, Category = "Robot Upgrades")
	void UpgradeArmor();

	UFUNCTION(BlueprintCallable, Category = "Robot Upgrades")
	void UpgradeAgility();

	UFUNCTION(BlueprintCallable, Category = "Robot Upgrades")
	void UpgradeDamage();

	//Anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Animations")
	UAnimMontage* AttackMontage;

	//Opponent
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Opponent")
	ABaseGladiator* OpponentGladiator;
protected:
	virtual void BeginPlay() override;
	void Aim();

private:	
	float TimeSinceLastMove;
	const float MoveCooldown = 1.0f; //not used

	int _hitCount;
	int _missCount;
};
