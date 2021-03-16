// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPUAIController.generated.h"

/**
 * 
 */
UCLASS()
class THEMOONANDNEPTUNE_API ACPUAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this controller's properties
	ACPUAIController(const FObjectInitializer& OBjectInitializer);

protected:
	// Sets default values for this controller's properties
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CPUBehaviour", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* CPUBehaviourTree;

	class UBehaviorTree* BehaviourTreeAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CPUBehaviour", meta = (AllowPrivateAccess = "true"))
	class UBlackboardComponent* CPUBlackboard;
};
