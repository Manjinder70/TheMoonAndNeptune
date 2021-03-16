// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cursor.generated.h"

UCLASS()
class THEMOONANDNEPTUNE_API ACursor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACursor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(int dir);
	int GetPosition() const;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cursor", meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* CursorSprite;

	int position {4};	// middle
	bool moving {};
	int direction {};
	int moveCount {};

	void UpdateMove();
};
