// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TheMoonAndNeptuneGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class THEMOONANDNEPTUNE_API ATheMoonAndNeptuneGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATheMoonAndNeptuneGameModeBase(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Override SpawnPlayerController
	virtual APlayerController* SpawnPlayerController(ENetRole InRemoteRole, const FString& Options) override;

private:
	class ACustomPlayerController* PlayerController {};
};
