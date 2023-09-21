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
	
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Player" )	
	class ABaseGladiator *Player;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Player" )
	int32 UpgradePoints = 10;
};