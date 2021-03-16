// Fill out your copyright notice in the Description page of Project Settings.


#include "Instructions.h"
#include "Components/TextRenderComponent.h"
#include "Components/DirectionalLightComponent.h"

// Sets default values
AInstructions::AInstructions()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("InstructionsBase"));

	KeysText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("KeysText"));
	KeysText->SetText(FText::FromString(TEXT("Use the Arrow and Enter keys\nto place your moon")));
	KeysText->SetTextRenderColor(FColor::White);
	KeysText->SetXScale(1.0f);
	KeysText->SetYScale(1.0f);
	KeysText->SetWorldSize(40.0f);
	KeysText->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	KeysText->SetRelativeRotation(FRotator(90.0f, 90.0f, 0.0f));
	KeysText->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	UDirectionalLightComponent* Light = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Light"));
	Light->SetIntensity(10000.0f);
	Light->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AInstructions::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AInstructions::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
