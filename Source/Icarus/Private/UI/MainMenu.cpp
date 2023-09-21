// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(StartButton != nullptr)) return false;
	StartButton->OnClicked.AddDynamic(this, &UMainMenu::OnStartClicked);

	if (!ensure(ExitButton != nullptr)) return false;
	ExitButton->OnClicked.AddDynamic(this, &UMainMenu::OnExitClicked);

	return true;
}

void UMainMenu::OnStartClicked()
{
	UGameplayStatics::OpenLevel(this, "Colosseum", true);
}

void UMainMenu::OnExitClicked()
{
	// Close the game
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

