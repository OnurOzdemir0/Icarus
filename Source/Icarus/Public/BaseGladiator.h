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
	int32 Ammo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	int32 AmmoLeft;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Armor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Agility;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	bool IsDodging;

	// Actions
	UFUNCTION(BlueprintCallable, Category = "Robot Actions")
	void Attack();

	UFUNCTION(BlueprintCallable, Category = "Robot Actions")
	void Move(float Direction, float Speed);

	// Upgrades

	UFUNCTION(BlueprintCallable, Category = "Robot Upgrades")
	void UpgradeArmor();

	UFUNCTION(BlueprintCallable, Category = "Robot Upgrades")
	void UpgradeAgility();

	UFUNCTION(BlueprintCallable, Category = "Robot Upgrades")
	void UpgradeDamage();

	// RANDOM
	UFUNCTION(BlueprintCallable, Category = "Robot Random")
	void RandomizeStats();

	//Anim
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Animations")
	UAnimMontage* AttackMontage;

	//Opponent
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Opponent")
	ABaseGladiator* OpponentGladiator;

	//_bonus
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Bonus")
	int _bonus =0;

	//Debug, UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Debug")
	FString stringAction = "None";
	
	//Debug, UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Debug")
	int dice;
	
	bool Malfunction = false;
protected:
	virtual void BeginPlay() override;
	void Aim();
	void Reload();

private:	
	float TimeSinceLastMove;
	const float MoveCooldown = 1.0f; //not used

	int _hitCount;
	int _missCount;
	
};
