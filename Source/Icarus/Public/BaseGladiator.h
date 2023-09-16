// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseGladiator.generated.h"

UCLASS()
class ICARUS_API ABaseGladiator : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseGladiator();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float FireRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Accuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Armor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot Stats")
	float Agility;

	// Actions
	UFUNCTION(BlueprintCallable, Category = "Robot Actions")
	void Attack();

	UFUNCTION(BlueprintCallable, Category = "Robot Actions")
	void Dodge();

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

protected:
	virtual void BeginPlay() override;
};
