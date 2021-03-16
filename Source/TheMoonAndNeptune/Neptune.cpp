// Fill out your copyright notice in the Description page of Project Settings.


#include "Neptune.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

// Sets default values
ANeptune::ANeptune()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("NeptuneBase"));

	NeptuneSprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("NeptuneSprite"));
	UPaperFlipbook* FlipbookAsset = Cast<UPaperFlipbook>(StaticLoadObject(UPaperFlipbook::StaticClass(), NULL, TEXT("PaperFlipbook'/Game/Flipbooks/Neptune.Neptune'")));
	NeptuneSprite->SetFlipbook(FlipbookAsset);
	NeptuneSprite->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	NeptuneSprite->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ParticleSystemAsset = Cast<UParticleSystem>(StaticLoadObject(UParticleSystem::StaticClass(), NULL, TEXT("ParticleSystem'/Game/Particles/Star.Star'")));
}

// Called when the game starts or when spawned
void ANeptune::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ANeptune::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANeptune::FireParticle()
{
	FVector loc = GetActorLocation();
	loc.Z += 10.0f;
	StarParticle = UGameplayStatics::SpawnEmitterAttached(ParticleSystemAsset, RootComponent, NAME_None, loc, FRotator::ZeroRotator, EAttachLocation::KeepWorldPosition, false);
	StarParticle->ActivateSystem(true);
}
