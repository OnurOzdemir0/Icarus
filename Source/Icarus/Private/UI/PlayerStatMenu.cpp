// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerStatMenu.h"

#include "BaseGladiator.h"
#include "MyGameInstance.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

bool UPlayerStatMenu::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	gameInst = Cast<UMyGameInstance>(GetGameInstance());

	// Health buttons
	HBI = Cast<UButton>(GetWidgetFromName(TEXT("HBI")));
	HBD = Cast<UButton>(GetWidgetFromName(TEXT("HBD")));
	if (HBI && HBD)
	{
		HBI->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnHIncreaseClicked);
		HBD->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnHDecreaseClicked); // You'd implement this function
	}

	// Damage buttons
	DBI = Cast<UButton>(GetWidgetFromName(TEXT("DBI")));
	DBD = Cast<UButton>(GetWidgetFromName(TEXT("DBD")));
	if (DBI && DBD)
	{
		DBI->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnDIncreaseClicked); // You'd implement this function
		DBD->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnDDecreaseClicked); // You'd implement this function
	}

	// Ammo buttons
	ABI = Cast<UButton>(GetWidgetFromName(TEXT("ABI")));
	ABD = Cast<UButton>(GetWidgetFromName(TEXT("ABD")));
	if (ABI && ABD)
	{
		ABI->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnAIncreaseClicked); // You'd implement this function
		ABD->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnADecreaseClicked); // You'd implement this function
	}

	// Agility buttons
	AGBI = Cast<UButton>(GetWidgetFromName(TEXT("AGBI")));
	AGBD = Cast<UButton>(GetWidgetFromName(TEXT("AGBD")));
	if (AGBI && AGBD)
	{
		AGBI->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnAGIncreaseClicked); // You'd implement this function
		AGBD->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnAGDecreaseClicked); // You'd implement this function
	}
	
	return true;
}

//On Button clicked
void UPlayerStatMenu::OnHIncreaseClicked()
{
	if(!(gameInst->Player))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Player->Health < 100 && gameInst->UpgradePoints > 0)
	{
		gameInst->Player->Health+=10;
		gameInst->UpgradePoints-=1;
	}
}

void UPlayerStatMenu::OnHDecreaseClicked()
{
	if(!(gameInst->Player))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	
	if (gameInst->Player->Health > 10)
	{
		gameInst->Player->Health-=10;
		gameInst->UpgradePoints+=1;
	}
}

void UPlayerStatMenu::OnDIncreaseClicked()
{
	if(!(gameInst->Player))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Player->Damage < 100 && gameInst->UpgradePoints > 0)
	{
		gameInst->Player->Damage+=10;
		gameInst->UpgradePoints-=1;
	}
}

void UPlayerStatMenu::OnDDecreaseClicked()
{
	if(!(gameInst->Player))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Player->Damage > 10)
	{
		gameInst->Player->Damage-=10;
		gameInst->UpgradePoints+=1;
	}
}

void UPlayerStatMenu::OnAIncreaseClicked()
{
	if(!(gameInst->Player))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Player->Ammo < 100 && gameInst->UpgradePoints > 0)
	{
		gameInst->Player->Ammo+=2;
		gameInst->UpgradePoints-=1;
	}
}
void UPlayerStatMenu::OnADecreaseClicked()
{
	if(!(gameInst->Player))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Player->Ammo > 3)
	{
		gameInst->Player->Ammo -= 2;
		gameInst->UpgradePoints += 1;
	}
}

void UPlayerStatMenu::OnAGIncreaseClicked()
{
	if(!(gameInst->Player))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Player->Agility < 100 && gameInst->UpgradePoints > 0)
	{
		gameInst->Player->Agility += 0.2;
		gameInst->UpgradePoints -= 1;
	}
}

void UPlayerStatMenu::OnAGDecreaseClicked()
{
	if(!(gameInst->Player))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Player->Agility > 1)
	{
		gameInst->Player->Agility -= 0.2;
		gameInst->UpgradePoints += 1;
	}
}










