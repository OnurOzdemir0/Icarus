// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseGladiator.generated.h"

class UMyGameInstance;
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

	UMyGameInstance* GameInstance;
	
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

	UPROPERTY(	EditAnywhere, BlueprintReadWrite, Category = "Robot Debug")
	bool bIsAlive = true;

protected:
	virtual void BeginPlay() override;
	void Aim();
	void Reload();

private:	
	float TimeSinceLastMove;
	const float MoveCooldown = 1.0f; 

	int _hitCount;
	int _missCount;
	
};
