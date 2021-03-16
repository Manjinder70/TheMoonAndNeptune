// Fill out your copyright notice in the Description page of Project Settings.


#include "Moon.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

// Sets default values
AMoon::AMoon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MoonBase"));

	MoonSprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("MoonSprite"));
	UPaperFlipbook* FlipbookAsset = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, TEXT("PaperFlipbook'/Game/Flipbooks/Moon.Moon'")));
	MoonSprite->SetFlipbook(FlipbookAsset);
	MoonSprite->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	MoonSprite->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ParticleSystemAsset = Cast<UParticleSystem>(StaticLoadObject(UParticleSystem::StaticClass(), NULL, TEXT("ParticleSystem'/Game/Particles/Star.Star'")));
}

// Called when the game starts or when spawned
void AMoon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMoon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMoon::FireParticle()
{
	FVector loc = GetActorLocation();
	loc.Z += 10.0f;
	StarParticle = UGameplayStatics::SpawnEmitterAttached(ParticleSystemAsset, RootComponent, NAME_None, loc, FRotator::ZeroRotator, EAttachLocation::KeepWorldPosition, false);
	StarParticle->ActivateSystem(true);
}
