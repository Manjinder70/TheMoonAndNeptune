// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
AGrid::AGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("GridBase"));

	GridSprite1 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite1"));
	UPaperSprite* SpriteAsset1 = Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("PaperSprite'/Game/Sprites/Image_Sprite_4.Image_Sprite_4'")));
	GridSprite1->SetSprite(SpriteAsset1);
	GridSprite1->SetRelativeLocation(FVector(-220.0f, -217.0f, 0.0f));
	GridSprite1->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	GridSprite2 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite2"));
	UPaperSprite* SpriteAsset2 = Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("PaperSprite'/Game/Sprites/Image_Sprite_5.Image_Sprite_5'")));
	GridSprite2->SetSprite(SpriteAsset2);
	GridSprite2->SetRelativeLocation(FVector(0.0f, -225.0f, 2.0f));
	GridSprite2->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	GridSprite3 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite3"));
	UPaperSprite* SpriteAsset3 = Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("PaperSprite'/Game/Sprites/Image_Sprite_6.Image_Sprite_6'")));
	GridSprite3->SetSprite(SpriteAsset3);
	GridSprite3->SetRelativeLocation(FVector(235.0f, -234.0f, 4.0f));
	GridSprite3->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite3->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	GridSprite4 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite4"));
	GridSprite4->SetSprite(SpriteAsset3);
	GridSprite4->SetRelativeLocation(FVector(-220.0f, -7.0f, 6.0f));
	GridSprite4->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite4->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	GridSprite5 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite5"));
	UPaperSprite* SpriteAsset4 = Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("PaperSprite'/Game/Sprites/Image_Sprite_7.Image_Sprite_7'")));
	GridSprite5->SetSprite(SpriteAsset4);
	GridSprite5->SetRelativeLocation(FVector(18.0f, 0.0f, 8.0f));
	GridSprite5->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite5->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	GridSprite6 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite6"));
	GridSprite6->SetSprite(SpriteAsset1);
	GridSprite6->SetRelativeLocation(FVector(237.0f, 8.0f, 10.0f));
	GridSprite6->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite6->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	GridSprite7 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite7"));
	GridSprite7->SetSprite(SpriteAsset1);
	GridSprite7->SetRelativeLocation(FVector(-220.0f, 235.0f, 12.0f));
	GridSprite7->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite7->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	GridSprite8 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite8"));
	GridSprite8->SetSprite(SpriteAsset2);
	GridSprite8->SetRelativeLocation(FVector(0.0f, 227.0f, 14.0f));
	GridSprite8->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite8->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	GridSprite9 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("GridSprite9"));
	GridSprite9->SetSprite(SpriteAsset3);
	GridSprite9->SetRelativeLocation(FVector(235.0f, 219.0f, 16.0f));
	GridSprite9->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	GridSprite9->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AGrid::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
