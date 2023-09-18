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

	UPROPERTY( BlueprintReadOnly, EditAnywhere, Category = "AI")
	FString str_Action;
	
	float TimeSinceLastAction;
	const float ActionCooldown = 1.0f;
};
