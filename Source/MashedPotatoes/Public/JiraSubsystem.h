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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName Id;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName Description;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName State;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName AssignedTo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName Reporter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EJiraTicketType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Progress = 0.0f;
	
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
