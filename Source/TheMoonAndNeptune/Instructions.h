// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Instructions.generated.h"

UCLASS()
class THEMOONANDNEPTUNE_API AInstructions : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInstructions();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Text", meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* KeysText;
};
