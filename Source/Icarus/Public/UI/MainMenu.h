// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class ICARUS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* StartButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ExitButton;

	UFUNCTION()
	void OnStartClicked();

	UFUNCTION()
	void OnExitClicked();
	
};
