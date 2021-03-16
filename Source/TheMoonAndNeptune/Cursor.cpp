// Fill out your copyright notice in the Description page of Project Settings.


#include "Cursor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
ACursor::ACursor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CursorBase"));

	CursorSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("CursorSprite"));
	UPaperSprite* SpriteAsset = Cast<UPaperSprite>(StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("PaperSprite'/Game/Sprites/Image_Sprite_8.Image_Sprite_8'")));
	CursorSprite->SetSprite(SpriteAsset);
	CursorSprite->SetRelativeRotation(FRotator(180.0f, -180.0f, 90.0f));
	CursorSprite->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ACursor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACursor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMove();
}

void ACursor::Move(int dir)
{
	if (moving)
		return;

	if (dir == -1 && (position == 0 || position == 3 || position == 6))
		return;
	else if (dir == 1 && (position == 2 || position == 5 || position == 8))
		return;
	else if (dir == -2 && (position == 0 || position == 1 || position == 2))
		return;
	else if (dir == 2 && (position == 6 || position == 7 || position == 8))
		return;

	direction = dir;
	moving = true;
	moveCount = 0;
}

int ACursor::GetPosition() const
{
	return position;
}

void ACursor::UpdateMove()
{
	if (!moving)
		return;

	FVector loc = GetActorLocation();
	if (direction == -1)
		loc.X -= 6.0f;
	else if (direction == 1)
		loc.X += 6.0f;
	else if (direction == -2)
		loc.Y -= 6.0f;
	else if (direction == 2)
		loc.Y += 6.0f;
	SetActorLocation(loc);

	if (moveCount++ == 38)
	{
		if (direction == -1 || direction == 1)
			position += direction;
		else if (direction == -2)
			position -= 3;
		else if (direction == 2)
			position += 3;

		moving = false;
	}
}
