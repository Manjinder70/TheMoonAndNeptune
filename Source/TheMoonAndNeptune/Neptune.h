// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Neptune.generated.h"

UCLASS()
class THEMOONANDNEPTUNE_API ANeptune : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ANeptune();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void FireParticle();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Neptune", meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* NeptuneSprite;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Neptune", meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* StarParticle;

	class UParticleSystem* ParticleSystemAsset;
};
