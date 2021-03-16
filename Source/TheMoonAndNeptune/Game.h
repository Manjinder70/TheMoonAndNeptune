// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Game.generated.h"

struct GridEntry
{
	class AActor* body;
	int status;	// -1=empty, 0=moon and 1=neptune
};

UCLASS()
class THEMOONANDNEPTUNE_API AGame : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool IsCPUTurn();
	GridEntry* GetGridInfo();
	void UpdateGridWithNeptune(int pos);

private:
	class AInstructions* instructions {};
	class AGrid* grid {};
	class ACursor* cursor {};
	class ACPU* CPU {};

	GridEntry gridinfo[9] =
	{
		{nullptr, -1},
		{nullptr, -1},
		{nullptr, -1},
		{nullptr, -1},
		{nullptr, -1},
		{nullptr, -1},
		{nullptr, -1},
		{nullptr, -1},
		{nullptr, -1}
	};

	bool humanTurn {true};
	bool complete {};
	int frame {};

	template <typename T> T* SpawnGameActor(FVector loc);
	void SpawnInstructions();
	void SpawnGrid();
	void SpawnCursor();
	void SpawnCPU();
	void SpawnBody(enum class Body body, int pos);

	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
	void PlaceMoon();
	void CheckForWinner();
	bool Check3InARow(enum class Body body, int& pos1, int& pos2, int& pos3);
	void SpawnMenu();
};

enum class Body
{
	Moon,
	Neptune
};
