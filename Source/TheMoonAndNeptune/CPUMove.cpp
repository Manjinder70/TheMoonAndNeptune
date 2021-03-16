// Fill out your copyright notice in the Description page of Project Settings.


#include "CPUMove.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CPU.h"
#include "Game.h"

UCPUMove::UCPUMove(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = TEXT("CPU Move");

	bNotifyTick = true;
}

EBTNodeResult::Type UCPUMove::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	FinishLatentTask(OwnerComp, EBTNodeResult::InProgress);

	return EBTNodeResult::InProgress;
}

void UCPUMove::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	ACPU* CPU = Cast<ACPU>(OwnerComp.GetAIOwner()->GetPawn());

	if (!CPU->IsTurn())
		return;

	FRandomStream Stream(FMath::Rand());
	Stream.GenerateNewSeed();
	int pos;

	do
	{
		pos = Stream.RandRange(0, 8);
	}
	while (CPU->GetGridInfo()[pos].status != -1);

	CPU->UpdateGrid(pos);
}
