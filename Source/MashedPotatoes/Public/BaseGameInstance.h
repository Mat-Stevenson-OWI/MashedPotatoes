// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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
	FORCEINLINE bool HasNickname() const { return Nickname.IsSet(); }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FString GetNickname() const { return Nickname.Get(TEXT("No name")); }

	UFUNCTION(BlueprintCallable)
	void SetNickname(const FString& NewNickname) { Nickname = NewNickname; }

protected:
	TOptional<FString> Nickname;
};
