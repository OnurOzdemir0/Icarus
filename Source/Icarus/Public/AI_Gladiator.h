#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Gladiator.generated.h"

class ABaseGladiator;

UCLASS()
class ICARUS_API AAI_Gladiator : public AAIController
{
	GENERATED_BODY()
	
public:
	AAI_Gladiator();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void ChooseNextAction();

	ABaseGladiator* ControlledGladiator;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "AI")
	int Action;
	
	float TimeSinceLastAction;
	float ActionCooldown = 2.5f;

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "AI Round")
	int Round = 0;
};
