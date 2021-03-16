// Fill out your copyright notice in the Description page of Project Settings.


#include "CPUAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

// Sets default values
ACPUAIController::ACPUAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	CPUBehaviourTree = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("CPUBehaviourTree"));
	BehaviourTreeAsset = Cast<UBehaviorTree>(StaticLoadObject(UBehaviorTree::StaticClass(), NULL, TEXT("BehaviorTree'/Game/AI/CPU_BT.CPU_BT'")));

	CPUBlackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("CPUBlackboard"));
}

// Called when the game starts or when spawned
void ACPUAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ACPUAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunBehaviorTree(BehaviourTreeAsset);
	CPUBehaviourTree->StartTree(*BehaviourTreeAsset);

	CPUBlackboard->InitializeBlackboard(*BehaviourTreeAsset->BlackboardAsset);
}
