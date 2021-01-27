// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Types.h"

#include "BaseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MASHEDPOTATOES_API UBaseGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FString GetNickname() const { return Profile.Name; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool HasProfile() const { return !Profile.Name.IsEmpty(); }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FEmployeeProfile GetProfile() const { return Profile; }

	UFUNCTION(BlueprintCallable)
	void SetProfile(const FEmployeeProfile& NewProfile) { Profile = NewProfile; }

protected:
	FEmployeeProfile Profile;
};
