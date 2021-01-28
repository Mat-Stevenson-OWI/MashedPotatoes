// Fill out your copyright notice in the Description page of Project Settings.


#include "JiraTicketInteraction.h"


#include "JiraTicketComponent.h"
#include "MashedPotatoesPrivate.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UJiraTicketInteraction::UJiraTicketInteraction()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJiraTicketInteraction::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UJiraTicketInteraction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UJiraTicketInteraction::StartInteraction()
{
	const FVector& Location = GetOwner()->GetActorLocation();

	static const TArray<AActor*> ActorsToIgnore;
	TArray<AActor*> FoundActors;
	const bool Found = UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Location, InteractionRadius, ObjectTypes, ActorClassFilter, ActorsToIgnore, FoundActors);
	if(Found)
	{
		for(auto Actor : FoundActors)
		{
			UActorComponent* Comp = Actor->GetComponentByClass(UJiraTicketComponent::StaticClass());
			if(nullptr != Comp)
			{
				UJiraTicketComponent* TicketComp = Cast<UJiraTicketComponent>(Comp);
				if(nullptr != TicketComp)
				{
					LOG_INFO("Found Jira ticket %s", *TicketComp->Ticket.Id.ToString())
					OnTicketFound.Execute(TicketComp);
					break;
				}
			}
			else
			{
				LOG_INFO("Found actor %s with no JiraTicketComponent", *Actor->GetName())
			}
		}
	}
	else
	{
		LOG_INFO("No actors found")
	}
}

