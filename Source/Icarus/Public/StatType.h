#pragma once

#include "CoreMinimal.h"
#include "StatType.generated.h"

UENUM(BlueprintType)
enum class EStatType : uint8
{
	EST_Ammo UMETA(DisplayName = "Ammo"),
	EST_AmmoLeft UMETA(DisplayName = "Ammo Left"),
	EST_Damage UMETA(DisplayName = "Damage"),
	EST_Health UMETA(DisplayName = "Health"),
	EST_Armor UMETA(DisplayName = "Armor"),
	EST_Agility UMETA(DisplayName = "Agility"),
	EST_FireRate UMETA(DisplayName = "Fire Rate"),
	EST_Accuracy UMETA(DisplayName = "Accuracy")
};