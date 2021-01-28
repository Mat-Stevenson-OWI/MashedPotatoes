// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "JiraTicketComponent.h"
#include "Components/ActorComponent.h"
#include "JiraTicketInteraction.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FTicketFound, UJiraTicketComponent*, TicketComponent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MASHEDPOTATOES_API UJiraTicketInteraction : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UJiraTicketInteraction();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void StartInteraction();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InteractionRadius = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassFilter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTicketFound OnTicketFound;
	
};
