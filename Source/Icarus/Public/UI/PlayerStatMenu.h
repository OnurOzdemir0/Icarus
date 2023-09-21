// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatMenu.generated.h"

/**
 * 
 */

class UButton;
class UTextBlock;
class UProgressBar;


UCLASS()
class ICARUS_API UPlayerStatMenu : public UUserWidget
{
	GENERATED_BODY()
public:

	class UMyGameInstance *gameInst;

	UFUNCTION()
	
	virtual bool Initialize() override;

	UFUNCTION( BlueprintCallable )   //health
	void OnHIncreaseClicked();

	UFUNCTION( BlueprintCallable )
	void OnHDecreaseClicked();

	UFUNCTION( BlueprintCallable )	//damage
	void OnDIncreaseClicked();

	UFUNCTION( BlueprintCallable )
	void OnDDecreaseClicked();

	UFUNCTION( BlueprintCallable )  //ammo
	void OnAIncreaseClicked();

	UFUNCTION( BlueprintCallable )
	void OnADecreaseClicked();

	UFUNCTION( BlueprintCallable )  //agility
	void OnAGIncreaseClicked();

	UFUNCTION( BlueprintCallable )
	void OnAGDecreaseClicked();
	

	UButton *HBI, *HBD;   // Health		I: increase,  D:decrease 
 	UButton *DBI, *DBD;   // Damage
	UButton *ABI, *ABD;   // Ammo
	UButton *AGBI, *AGBD; // Agility

	UTextBlock *HBT, *DBT, *ABT, *AGBT; // Health, Damage, Ammo, Agility Text
	UProgressBar *HBP, *DBP, *ABP, *AGBP; // Health, Damage, Ammo, Agility Progress Bar
};
