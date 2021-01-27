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

USTRUCT(BlueprintType)
struct FJiraTicket
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	FName Id;

	UPROPERTY(VisibleAnywhere)
	FName Description;

	UPROPERTY(VisibleAnywhere)
	FName State;

	UPROPERTY(VisibleAnywhere)
	FName AssignedTo;

	UPROPERTY(VisibleAnywhere)
	FName Reporter;

	UPROPERTY(VisibleAnywhere)
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
