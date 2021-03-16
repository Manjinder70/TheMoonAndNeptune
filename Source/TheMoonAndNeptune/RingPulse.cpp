// Fill out your copyright notice in the Description page of Project Settings.


#include "RingPulse.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
ARingPulse::ARingPulse()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RingPulseBase"));

	RingPulse = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RingPulse"));
	UStaticMesh* Mesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("StaticMesh'/Game/Meshes/RingPulse.RingPulse'")));
	MaterialAsset = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Materials/RingPulse.RingPulse'"));
	RingPulse->SetStaticMesh(Mesh);
	RingPulse->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ARingPulse::BeginPlay()
{
	Super::BeginPlay();

	MaterialInstance = UMaterialInstanceDynamic::Create(MaterialAsset, nullptr);
	if (MaterialInstance)
		RingPulse->SetMaterial(0, MaterialInstance);
}

// Called every frame
void ARingPulse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MaterialInstance)
		MaterialInstance->SetScalarParameterValue(TEXT("PulseSize"), size);
	size += 0.2f;

	if (frame++ == 120)
		Destroy();
}
