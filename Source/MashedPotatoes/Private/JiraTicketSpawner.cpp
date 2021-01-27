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

	UWorld* World = GetWorld();

	UJiraSubsystem* Jira = UJiraStatics::GetJira(World);
	TArray<FName> Ids = Jira->GetTicketIds(0, 0);
	FVector Location;
	FRotator Rotation;
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	const int GridSize = FMath::CeilToInt(FMath::Max(Ids.Num(), 2) / 2.0f);
	for(int Index = 0; Index < Ids.Num(); Index++)
	{
		const FJiraTicket& Ticket = Jira->GetTicket(Ids[Index]);
		SpawnParams.Name = Ticket.Id;
		UClass* TicketClass = GetTicketClass(Ticket.Type);
		if(nullptr != TicketClass)
		{
			Location = GetCellPosition(Index, GridSize);
			LOG_INFO("Creating jira ticket at x=%f y=%f", Location.X, Location.Y)
			AActor* TicketActor = World->SpawnActor(TicketClass, &Location, &Rotation, SpawnParams);
			if(nullptr == TicketActor)
			{
				LOG_WARNING("Failed to created jira ticket at x=%f y=%f", Location.X, Location.Y)
			}

			// TODO: Add Jira tick info into Jira component
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

FVector AJiraTicketSpawner::GetCellPosition(int Index, int GridSize) const
{
	ensure(GridSize > 0);
	
	const int Row = (Index % GridSize) + 1;
	const int Col = (FMath::FloorToInt(Index / static_cast<float>(GridSize))) + 1;

	const float PhysicalGridSize = GridSize * GridCellSize;

	LOG_INFO("Row=%i, Col=%i, GridSize=%i", Row, Col, GridSize);

	float X = Row * GridCellSize;
	X = X - (PhysicalGridSize / 2.0f);
	float Y = Col * GridCellSize;
	Y = Y - (PhysicalGridSize / 2.0f);

	return { X, Y, 0.0f };
}

