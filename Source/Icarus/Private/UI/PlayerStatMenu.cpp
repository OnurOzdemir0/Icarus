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
		HBD->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnHDecreaseClicked); 
	}

	// Damage buttons
	DBI = Cast<UButton>(GetWidgetFromName(TEXT("DBI")));
	DBD = Cast<UButton>(GetWidgetFromName(TEXT("DBD")));
	if (DBI && DBD)
	{
		DBI->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnDIncreaseClicked); 
		DBD->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnDDecreaseClicked); 
	}

	// Ammo buttons
	ABI = Cast<UButton>(GetWidgetFromName(TEXT("ABI")));
	ABD = Cast<UButton>(GetWidgetFromName(TEXT("ABD")));
	if (ABI && ABD)
	{
		ABI->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnAIncreaseClicked); 
		ABD->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnADecreaseClicked); 
	}

	// Agility buttons
	AGBI = Cast<UButton>(GetWidgetFromName(TEXT("AGBI")));
	AGBD = Cast<UButton>(GetWidgetFromName(TEXT("AGBD")));
	if (AGBI && AGBD)
	{
		AGBI->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnAGIncreaseClicked); 
		AGBD->OnClicked.AddDynamic(this, &UPlayerStatMenu::OnAGDecreaseClicked); 
	}
	
	return true;
}

//On Button clicked
void UPlayerStatMenu::OnHIncreaseClicked()
{
	if(!(gameInst->Health))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Health < 120 && gameInst->UpgradePoints > 0)
	{
		gameInst->Health+=10;
		gameInst->UpgradePoints-=1;
	}
}

void UPlayerStatMenu::OnHDecreaseClicked()
{
	if(!(gameInst->Health))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	
	if (gameInst->Health > 10)
	{
		gameInst->Health-=10;
		gameInst->UpgradePoints+=1;
	}
}

void UPlayerStatMenu::OnDIncreaseClicked()
{
	if(!(gameInst->Damage))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Damage < 60 && gameInst->UpgradePoints > 0)
	{
		gameInst->Damage+=5;
		gameInst->UpgradePoints-=1;
	}
}

void UPlayerStatMenu::OnDDecreaseClicked()
{
	if(!(gameInst->Damage))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Damage > 10)
	{
		gameInst->Damage-=5;
		gameInst->UpgradePoints+=1;
	}
}

void UPlayerStatMenu::OnAIncreaseClicked()
{
	if(!(gameInst->Ammo))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Ammo < 7 && gameInst->UpgradePoints > 0)
	{
		gameInst->Ammo+=2;
		gameInst->UpgradePoints-=1;
	}
}
void UPlayerStatMenu::OnADecreaseClicked()
{
	if(!(gameInst->Ammo))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Ammo > 3)
	{
		gameInst->Ammo -= 2;
		gameInst->UpgradePoints += 1;
	}
}

void UPlayerStatMenu::OnAGIncreaseClicked()
{
	if(!(gameInst->Agility))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Agility < 1.6 && gameInst->UpgradePoints > 0)
	{
		gameInst->Agility += 0.2;
		gameInst->UpgradePoints -= 1;
	}
}

void UPlayerStatMenu::OnAGDecreaseClicked()
{
	if(!(gameInst->Agility))
	{
		UE_LOG(LogTemp, Warning, TEXT("gameInst->Player is null"));
		return;
	}
	if (gameInst->Agility > 0.6)
	{
		gameInst->Agility -= 0.2;
		gameInst->UpgradePoints += 1;
	}
}










