// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "Subsystems/EngineSubsystem.h"
#include "JiraSubsystem.generated.h"

USTRUCT()
struct FJiraTicket
{
	GENERATED_BODY()

	UPROPERTY()
	FName Id;

	UPROPERTY()
	FName Description;

	UPROPERTY()
	FName State;

	UPROPERTY()
	FName AssignedTo;

	UPROPERTY()
	FName Reporter;
	
};

/**
 * 
 */
UCLASS()
class MASHEDPOTATOES_API UJiraSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

	UFUNCTION()
	FName GetProjectName() const;

	UFUNCTION()
    int GetTicketCount() const;

	UFUNCTION()
	TArray<FName> GetTicketIds(int Start, int End) const;

	UFUNCTION()
	FJiraTicket GetTicket(const FName& TicketId) const;
};
