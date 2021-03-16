// Fill out your copyright notice in the Description page of Project Settings.


#include "Game.h"
#include "Kismet/GameplayStatics.h"
#include "GameStatics.h"
#include "CustomPlayerController.h"
#include "RingPulse.h"
#include "Instructions.h"
#include "Grid.h"
#include "Cursor.h"
#include "Moon.h"
#include "Neptune.h"
#include "CPU.h"
#include "GameMenu.h"

// TODO: move cursor with mouse from player controller

template <typename T>
T* AGame::SpawnGameActor(FVector loc)
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.Instigator = GetInstigator();

	UWorld* const World = GetWorld();
	if (World)
		return World->SpawnActor<T>(T::StaticClass(), loc, FRotator::ZeroRotator, SpawnInfo);

	return nullptr;
}

// Sets default values
AGame::AGame()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGame::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine->IsEditor())
	{
		APlayerController* pc = UGameplayStatics::GetPlayerController(this, 0);
		if (pc)
			pc->Possess(this);
	}
	else
	{
		ACustomPlayerController* pc = UGameStatics::GetPlayerController();
		if (pc)
			pc->Possess(this);
	}

	SpawnInstructions();
	SpawnGrid();
	SpawnCursor();
	SpawnCPU();
}

// Called every frame
void AGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckForWinner();
}

// Called to bind functionality to input
void AGame::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveX", this, &AGame::MoveX);
	PlayerInputComponent->BindAxis("MoveY", this, &AGame::MoveY);
	PlayerInputComponent->BindAction("Enter", EInputEvent::IE_Pressed, this, &AGame::PlaceMoon);
}

bool AGame::IsCPUTurn()
{
	return !humanTurn && !complete;
}

GridEntry* AGame::GetGridInfo()
{
	return gridinfo;
}

void AGame::UpdateGridWithNeptune(int pos)
{
	SpawnBody(Body::Neptune, pos);
	gridinfo[pos].status = 1;
	humanTurn = true;
}

void AGame::SpawnInstructions()
{
	instructions = SpawnGameActor<AInstructions>(FVector(630.0f, -200.0f, -220.0f));
}

void AGame::SpawnGrid()
{
	grid = SpawnGameActor<AGrid>(FVector(0.0f, 0.0f, -220.0f));
}

void AGame::SpawnCursor()
{
	cursor = SpawnGameActor<ACursor>(FVector(11.0f, 0.0f, -180.0f));
}

void AGame::SpawnCPU()
{
	CPU = SpawnGameActor<ACPU>(FVector::ZeroVector);
	CPU->SetGameActor(this);
}

void AGame::SpawnBody(Body body, int pos)
{
	const float start_x = 11.0f;
	const float size = 228.0f;
	float x = 0.0f, y = 0.0f;

	switch (pos)
	{
	case 0:
		x = start_x - size;
		y = 0.0f - size;
		break;
	case 1:
		x = start_x;
		y = 0.0f - size;
		break;
	case 2:
		x = start_x + size;
		y = 0.0f - size;
		break;
	case 3:
		x = start_x - size;
		y = 0.0f;
		break;
	case 4:
		x = start_x;
		y = 0.0f;
		break;
	case 5:
		x = start_x + size;
		y = 0.0f;
		break;
	case 6:
		x = start_x - size;
		y = 0.0f + size;
		break;
	case 7:
		x = start_x;
		y = 0.0f + size;
		break;
	case 8:
		x = start_x + size;
		y = 0.0f + size;
		break;
	}

	if (body == Body::Moon)
		gridinfo[pos].body = SpawnGameActor<AMoon>(FVector(x, y, -200.0f));
	else
		gridinfo[pos].body = SpawnGameActor<ANeptune>(FVector(x, y, -200.0f));

	UWorld* const World = GetWorld();
	if (World)
	{
		FVector loc = FVector(x, y, -180.0f);
		World->SpawnActor(ARingPulse::StaticClass(), &loc);
	}
}

void AGame::MoveX(float AxisValue)
{
	if (cursor)
	{
		if (AxisValue == -1.0f)
			cursor->Move(-1);
		else if (AxisValue == 1.0f)
			cursor->Move(1);
	}
}

void AGame::MoveY(float AxisValue)
{
	if (cursor)
	{
		if (AxisValue == -1.0f)
			cursor->Move(-2);
		else if (AxisValue == 1.0f)
			cursor->Move(2);
	}
}

void AGame::PlaceMoon()
{
	if (cursor && !complete)
	{
		int pos = cursor->GetPosition();
		if (humanTurn && gridinfo[pos].status == -1)
		{
			SpawnBody(Body::Moon, pos);
			gridinfo[pos].status = 0;
			humanTurn = false;
			CheckForWinner();
		}
			
	}
}

void AGame::CheckForWinner()
{
	int pos1, pos2, pos3;
	bool done;

	if (complete)
	{
		if (frame++ == 120)
			SpawnMenu();
	}
	else
	{
		done = Check3InARow(Body::Moon, pos1, pos2, pos3);
		if (done)
		{
			Cast<AMoon>(gridinfo[pos1].body)->FireParticle();
			Cast<AMoon>(gridinfo[pos2].body)->FireParticle();
			Cast<AMoon>(gridinfo[pos3].body)->FireParticle();
		}
		else
		{
			done = Check3InARow(Body::Neptune, pos1, pos2, pos3);
			if (done)
			{
				Cast<ANeptune>(gridinfo[pos1].body)->FireParticle();
				Cast<ANeptune>(gridinfo[pos2].body)->FireParticle();
				Cast<ANeptune>(gridinfo[pos3].body)->FireParticle();
			}
			else
			{
				done = true;
				for (int i = 0; i < 9; i++)
				{
					if (gridinfo[i].status == -1)
						done = false;
				}
			}
		}

		complete = done;
	}
}

bool AGame::Check3InARow(Body body, int& pos1, int& pos2, int& pos3)
{
	int status = body == Body::Moon ? 0 : 1;

	if (gridinfo[0].status == status && gridinfo[1].status == status && gridinfo[2].status == status)
	{
		pos1 = 0;
		pos2 = 1;
		pos3 = 2;

		return true;
	}

	if (gridinfo[3].status == status && gridinfo[4].status == status && gridinfo[5].status == status)
	{
		pos1 = 3;
		pos2 = 4;
		pos3 = 5;

		return true;
	}

	if (gridinfo[6].status == status && gridinfo[7].status == status && gridinfo[8].status == status)
	{
		pos1 = 6;
		pos2 = 7;
		pos3 = 8;

		return true;
	}

	if (gridinfo[0].status == status && gridinfo[3].status == status && gridinfo[6].status == status)
	{
		pos1 = 0;
		pos2 = 3;
		pos3 = 6;

		return true;
	}


	if (gridinfo[1].status == status && gridinfo[4].status == status && gridinfo[7].status == status)
	{
		pos1 = 1;
		pos2 = 4;
		pos3 = 7;

		return true;
	}

	if (gridinfo[2].status == status && gridinfo[5].status == status && gridinfo[8].status == status)
	{
		pos1 = 2;
		pos2 = 5;
		pos3 = 8;

		return true;
	}

	if (gridinfo[0].status == status && gridinfo[4].status == status && gridinfo[8].status == status)
	{
		pos1 = 0;
		pos2 = 4;
		pos3 = 8;

		return true;
	}

	if (gridinfo[2].status == status && gridinfo[4].status == status && gridinfo[6].status == status)
	{
		pos1 = 2;
		pos2 = 4;
		pos3 = 6;

		return true;
	}

	return false;
}

void AGame::SpawnMenu()
{
	if (GEngine->IsEditor())
	{
		APlayerController* pc = UGameplayStatics::GetPlayerController(this, 0);
		if (pc)
			pc->UnPossess();
	}
	else
	{
		ACustomPlayerController* pc = UGameStatics::GetPlayerController();
		if (pc)
			pc->UnPossess();
	}

	UWorld* const World = GetWorld();
	if (World)
	{
		FVector loc = FVector(0.0f, 0.0f, -200.0f);
		World->SpawnActor(AGameMenu::StaticClass(), &loc);
	}

	if (CPU)
		CPU->Destroy();
	if (cursor)
		cursor->Destroy();
	if (grid)
		grid->Destroy();
	for (int i = 0; i < 9; i++)
		if (gridinfo[i].body)
			gridinfo[i].body->Destroy();
	if (instructions)
		instructions->Destroy();

	Destroy();
}
