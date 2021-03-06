// Fill out your copyright notice in the Description page of Project Settings.


#include "JiraTicketComponent.h"

#include "Net/UnrealNetwork.h"

#include "JiraStatics.h"
#include "JiraSubsystem.h"

// Sets default values for this component's properties
UJiraTicketComponent::UJiraTicketComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicatedByDefault(true);
	// ...
}

void UJiraTicketComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UJiraTicketComponent, Ticket);
}

// Called when the game starts
void UJiraTicketComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UJiraTicketComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UJiraTicketComponent::OnRep_Ticket()
{
	BP_OnRepTicket();
}

