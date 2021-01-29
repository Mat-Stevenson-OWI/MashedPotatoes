// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"

void ABasePlayerController::ToggleCharacterVisibility()
{
	bIsCharacterVisible = !bIsCharacterVisible;
	Server_SetCharacterVisibility(bIsCharacterVisible);
}

void ABasePlayerController::Server_SetCharacterVisibility_Implementation(bool bNewVisible)
{
	bIsCharacterVisible = bNewVisible;
	BP_SetCharacterVisibility(bNewVisible);
}

bool ABasePlayerController::Server_SetCharacterVisibility_Validate(bool bNewVisible)
{
	return true;
}
