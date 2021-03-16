// Fill out your copyright notice in the Description page of Project Settings.


#include "CPU.h"
#include "CPUAIController.h"
#include "Game.h"

// Sets default values
ACPU::ACPU()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AIControllerClass = ACPUAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void ACPU::BeginPlay()
{
	Super::BeginPlay();

	SpawnDefaultController();	
}

// Called every frame
void ACPU::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPU::SetGameActor(AGame* gameActor)
{
	game = gameActor;
}

bool ACPU::IsTurn()
{
	return game->IsCPUTurn();
}

GridEntry* ACPU::GetGridInfo()
{
	return game->GetGridInfo();
}

void ACPU::UpdateGrid(int pos)
{
	game->UpdateGridWithNeptune(pos);
}

// Called to bind functionality to input
void ACPU::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
