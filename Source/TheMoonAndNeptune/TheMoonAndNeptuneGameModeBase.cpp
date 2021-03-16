// Copyright Epic Games, Inc. All Rights Reserved.


#include "TheMoonAndNeptuneGameModeBase.h"
#include "Engine/World.h"
#include "GameStatics.h"
#include "CustomPlayerController.h"
#include "BuildNumber.h"
#include "StaticCamera.h"
#include "GameMenu.h"
#include "Engine.h"

// Sets default values
ATheMoonAndNeptuneGameModeBase::ATheMoonAndNeptuneGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultPawnClass = ABuildNumber::StaticClass();
	PlayerControllerClass = ACustomPlayerController::StaticClass();
}

// Called when the game starts or when spawned
void ATheMoonAndNeptuneGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();
	if (World)
	{
		// Spawn and set camera
		FVector loc {0.0f, 0.0f, 127.0f};
		AActor* StaticCamera = World->SpawnActor(AStaticCamera::StaticClass(), &loc);
		if (PlayerController)
		{
			PlayerController->SetViewTarget(StaticCamera);
			// Prevent player controller from automatically managing the view target
			PlayerController->bAutoManageActiveCameraTarget = false;

			UGameStatics::SetPlayerController(PlayerController);
		}

		loc = FVector(0.0f, 0.0f, -200.0f);
		World->SpawnActor(AGameMenu::StaticClass(), &loc);
	}
}

// Called every frame
void ATheMoonAndNeptuneGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APlayerController* ATheMoonAndNeptuneGameModeBase::SpawnPlayerController(ENetRole InRemoteRole, const FString& Options)
{
	APlayerController* pc = Super::SpawnPlayerController(InRemoteRole, Options);

	// Try to cast to our PC Type
	PlayerController = Cast<ACustomPlayerController>(pc);

	return pc;
}
