// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ICARUS_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMyGameInstance();

	UFUNCTION( BlueprintCallable )
	void PlayBackgroundMusic(USoundBase* Music);

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Player" )
	class UAudioComponent* AudioComponent;
	
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Player" )
	int32 Health = 20;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Player" )
	int32 Damage = 5;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Player" )
	int32 Ammo = 2;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Player" )
	float Agility = 0.8f;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Player" )
	int32 UpgradePoints = 10;

	UPROPERTY(EditAnywhere , BlueprintReadWrite, Category = "Enemy")
	FVector4 EnemyStats = FVector4(20, 5, 2, 0.8f);

	UFUNCTION( BlueprintCallable )
	void OnGladiatorDeath(class ABaseGladiator* Gladiator);

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Game Variables" )
	int32 Round = 1;
};