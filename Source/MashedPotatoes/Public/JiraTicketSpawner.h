// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JiraTicketSpawner.generated.h"

enum class EJiraTicketType : uint8;
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

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jira")
	UClass* BugTicketClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jira")
	UClass* TaskTicketClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jira")
	float XOffset = 100.0f;

};
