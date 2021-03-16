// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RingPulse.generated.h"

UCLASS()
class THEMOONANDNEPTUNE_API ARingPulse : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARingPulse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RingPulse", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* RingPulse;

	class UMaterial* MaterialAsset;
	class UMaterialInstanceDynamic* MaterialInstance;

	int frame {};
	float size {};
};
