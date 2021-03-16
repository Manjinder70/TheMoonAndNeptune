// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMenu.h"
#include "Kismet/GameplayStatics.h"
#include "GameStatics.h"
#include "CustomPlayerController.h"
#include "Components/TextRenderComponent.h"
#include "Components/DirectionalLightComponent.h"
#include "Game.h"

// Sets default values
AGameMenu::AGameMenu()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("GameMenuBase"));

	TitleText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TitleText"));
	TitleText->SetText(FText::FromString(TEXT("T  H  E  -  M  O  O  N  -  A  N  D  -  N  E  P  T  U  N  E")));
	TitleText->SetTextRenderColor(FColor::White);
	TitleText->SetXScale(1.0f);
	TitleText->SetYScale(1.0f);
	TitleText->SetWorldSize(80.0f);
	TitleText->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	TitleText->SetRelativeLocation(FVector(0.0f, -300.0f, -100.0f));
	TitleText->SetRelativeRotation(FRotator(90.0f, 90.0f, 0.0f));
	TitleText->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	PlayText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("PlayText"));
	PlayText->SetText(FText::FromString(TEXT("Press ENTER to play ...")));
	PlayText->SetTextRenderColor(FColor::Red);
	PlayText->SetXScale(1.0f);
	PlayText->SetYScale(1.0f);
	PlayText->SetWorldSize(40.0f);
	PlayText->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	PlayText->SetRelativeLocation(FVector(0.0f, -100.0f, -100.0f));
	PlayText->SetRelativeRotation(FRotator(90.0f, 90.0f, 0.0f));
	PlayText->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	UDirectionalLightComponent* Light = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Light"));
	Light->SetIntensity(10000.0f);
	Light->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AGameMenu::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine->IsEditor())
	{
		APlayerController* pc = UGameplayStatics::GetPlayerController(this, 0);
		if (pc)
			pc->Possess(this);
	}
	else
	{
		ACustomPlayerController* pc = UGameStatics::GetPlayerController();
		if (pc)
			pc->Possess(this);
	}
}

// Called every frame
void AGameMenu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameMenu::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Enter", EInputEvent::IE_Pressed, this, &AGameMenu::SpawnGame);
}

void AGameMenu::SpawnGame()
{
	if (GEngine->IsEditor())
	{
		APlayerController* pc = UGameplayStatics::GetPlayerController(this, 0);
		if (pc)
			pc->UnPossess();
	}
	else
	{
		ACustomPlayerController* pc = UGameStatics::GetPlayerController();
		if (pc)
			pc->UnPossess();
	}

	UWorld* const World = GetWorld();
	if (World)
		World->SpawnActor(AGame::StaticClass());

	Destroy();
}
