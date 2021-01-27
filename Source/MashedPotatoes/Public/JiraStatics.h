// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "JiraSubsystem.h"
#include "JiraStatics.generated.h"

/**
 * 
 */
UCLASS()
class MASHEDPOTATOES_API UJiraStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Analytics)
    static UJiraSubsystem* GetJira(UWorld* World);
};
