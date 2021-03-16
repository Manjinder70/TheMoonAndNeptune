// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticCamera.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AStaticCamera::AStaticCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("StaticCameraBase"));

	USpringArmComponent* Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Arm->TargetArmLength = 0.0f;
	Arm->bEnableCameraLag = true;
	Arm->bEnableCameraRotationLag = false;
	Arm->bUsePawnControlRotation = false;
	Arm->CameraLagSpeed = 2.0f;
	Arm->bDoCollisionTest = false;
	Arm->SetWorldLocationAndRotation(FVector::ZeroVector, FRotator::ZeroRotator);
	Arm->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	StaticCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("StaticCamera"));
	StaticCamera->bUsePawnControlRotation = false;
	StaticCamera->ProjectionMode = ECameraProjectionMode::Orthographic;
	StaticCamera->OrthoWidth = 1920.0f;
	StaticCamera->AspectRatio = 9.0f / 16.0f;
	StaticCamera->SetWorldLocationAndRotation(FVector::ZeroVector, FRotator(-90.0f, 0.0f, -90.0f));
	StaticCamera->PostProcessSettings.bOverride_BloomIntensity = true;
	StaticCamera->PostProcessSettings.BloomIntensity = 0.0f;
	StaticCamera->PostProcessSettings.bOverride_VignetteIntensity = true;
	StaticCamera->PostProcessSettings.VignetteIntensity = 0.0f;

	// This post process pass-through negates the need for tonemapper/AA/bloom/vignette/auto exposure settings!
	UMaterial* Material = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Materials/PostProcess.PostProcess'"));
	UMaterialInstanceDynamic* MaterialInst = UMaterialInstanceDynamic::Create(Material, nullptr);
	if (MaterialInst)
		StaticCamera->AddOrUpdateBlendable(MaterialInst);

	StaticCamera->AttachToComponent(Arm, FAttachmentTransformRules::KeepRelativeTransform, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void AStaticCamera::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AStaticCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
