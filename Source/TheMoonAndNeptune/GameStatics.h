// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameStatics.generated.h"

/**
 * 
 */
UCLASS()
class THEMOONANDNEPTUNE_API UGameStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void SetPlayerController(class ACustomPlayerController* pc);
	static class ACustomPlayerController* GetPlayerController();

private:
	static class ACustomPlayerController* PlayerController;
};
