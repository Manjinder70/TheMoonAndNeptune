// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStatics.h"
#include "CustomPlayerController.h"

ACustomPlayerController* UGameStatics::PlayerController {};

void UGameStatics::SetPlayerController(ACustomPlayerController* pc)
{
	PlayerController = pc;
}

ACustomPlayerController* UGameStatics::GetPlayerController()
{
	return PlayerController;
}
