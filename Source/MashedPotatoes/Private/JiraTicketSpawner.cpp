// Fill out your copyright notice in the Description page of Project Settings.


#include "JiraTicketSpawner.h"


#include "JiraStatics.h"
#include "JiraSubsystem.h"

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
	for(const FName& Id : Ids)
	{
		const FJiraTicket& Ticket = Jira->GetTicket(Id);
		SpawnParams.Name = Ticket.Id;
		UClass* TicketClass = GetTicketClass(Ticket.Type);
		if(nullptr != TicketClass)
		{
			World->SpawnActor(TicketClass, &Location, &Rotation, SpawnParams);
		}
		
		Location.X += XOffset;
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

