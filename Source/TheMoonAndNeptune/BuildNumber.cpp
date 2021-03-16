// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildNumber.h"

// Sets default values
ABuildNumber::ABuildNumber()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABuildNumber::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABuildNumber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABuildNumber::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

