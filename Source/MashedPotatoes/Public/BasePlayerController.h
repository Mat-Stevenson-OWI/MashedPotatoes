// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MASHEDPOTATOES_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void ToggleCharacterVisibility();

	UFUNCTION(Reliable, Server, WithValidation)
	void Server_SetCharacterVisibility(bool bNewVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetCharacterVisibility(bool bNewVisible);

private:
	bool bIsCharacterVisible = true;
	
};
