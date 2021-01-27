// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Types.generated.h"

UENUM(BlueprintType)
enum class EGuild : uint8
{
	Art,
	Engineering,
	HumanResources
};

USTRUCT(BlueprintType)
struct FEmployeeProfile
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString Name;

	UPROPERTY(BlueprintReadWrite)
	EGuild Guild;
};