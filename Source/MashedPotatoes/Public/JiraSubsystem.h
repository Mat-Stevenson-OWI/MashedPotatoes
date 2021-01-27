// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "Subsystems/EngineSubsystem.h"
#include "JiraSubsystem.generated.h"

UENUM()
enum class EJiraTicketType : uint8
{
	Unknown,
	Bug,
	Task,
	Story,
	Epic
};

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

	UPROPERTY()
	EJiraTicketType Type;
	
};

/**
 * 
 */
UCLASS()
class MASHEDPOTATOES_API UJiraSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	const FName& GetProjectName() const;

	UFUNCTION()
    int GetTicketCount() const;

	UFUNCTION()
	TArray<FName> GetTicketIds(int Start, int End) const;

	UFUNCTION()
	const FJiraTicket& GetTicket(const FName& TicketId) const;

public:

	FName ProjectName;
	TMap<FName, FJiraTicket> Tickets;
	TArray<FName> States;
	
};
