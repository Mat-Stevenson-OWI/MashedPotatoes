// Fill out your copyright notice in the Description page of Project Settings.


#include "JiraTicketSpawner.h"


#include "JiraStatics.h"
#include "JiraSubsystem.h"
#include "JiraTicketComponent.h"
#include "MashedPotatoesPrivate.h"

// Sets default values
AJiraTicketSpawner::AJiraTicketSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AJiraTicketSpawner::BeginPlay()
{
	Super::BeginPlay();

	if(SpawnPoints.Num() <= 0)
	{
		LOG_WARNING("No spawn points defined")
		return;
	}

	UWorld* World = GetWorld();
	if (!IsValid(World) || !World->IsServer())
	{
		return;
	}

	UJiraSubsystem* Jira = UJiraStatics::GetJira(World);
	TArray<FName> Ids = Jira->GetTicketIds(0, 0);
	FVector Location;
	FRotator Rotation;
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	for(int Index = 0; Index < Ids.Num(); Index++)
	{
		const FJiraTicket& Ticket = Jira->GetTicket(Ids[Index]);
		SpawnParams.Name = Ticket.Id;
		UClass* TicketClass = GetTicketClass(Ticket.Type);
		if(IsValid(TicketClass))
		{
			Location = GetSpawnPosition(Index);
			LOG_INFO("Creating jira ticket %s at x=%f y=%f", *Ticket.Id.ToString(), Location.X, Location.Y);
			AActor* TicketActor = World->SpawnActor(TicketClass, &Location, &Rotation, SpawnParams);
			if(nullptr == TicketActor)
			{
				LOG_WARNING("Failed to created jira ticket at x=%f y=%f", Location.X, Location.Y)
			}
			else
			{
				TicketActor->Rename(*Ticket.Id.ToString());
				UJiraTicketComponent* JiraComp = TicketActor->FindComponentByClass<UJiraTicketComponent>();
				if(nullptr != JiraComp)
				{
					JiraComp->Ticket = Ticket;
				}
				else
				{
					LOG_WARNING("Failed to add ticket info to jira ticket")
                }
			}
		}
	}
}

// Called every frame
void AJiraTicketSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UClass* AJiraTicketSpawner::GetTicketClass(EJiraTicketType Type) const
{
	switch(Type)
	{
		case EJiraTicketType::Bug: return BugTicketClass;
		case EJiraTicketType::Task: return TaskTicketClass;
		default: return nullptr;
	}
}

FVector AJiraTicketSpawner::GetSpawnPosition(int Index) const
{
	ensure(SpawnPoints.Num() > 0);
	
	const int SpawnIndex = Index % SpawnPoints.Num();
	const FJiraTicketSpawnInfo& Spawn = SpawnPoints[SpawnIndex];

	const FVector Location = Spawn.Location->GetActorLocation();

	return Location;
}

