// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "JiraTicketSpawner.generated.h"

enum class EJiraTicketType : uint8;

USTRUCT(BlueprintType)
struct FJiraTicketSpawnInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jira")
	AActor* Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jira")
	float Radius = 100;
};

UCLASS()
class MASHEDPOTATOES_API AJiraTicketSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJiraTicketSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UClass* GetTicketClass(EJiraTicketType Type) const;

	FVector GetSpawnPosition(int Index) const;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jira")
	UClass* BugTicketClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jira")
	UClass* TaskTicketClass;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jira")
	TArray<FJiraTicketSpawnInfo> SpawnPoints;

};
