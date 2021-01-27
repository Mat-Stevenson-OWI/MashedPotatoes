// Fill out your copyright notice in the Description page of Project Settings.


#include "JiraSubsystem.h"


void UJiraSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	ProjectName = TEXT("Mashed Potatoes");
	States = { "Todo", "InProgress", "InTest", "Completed" };
	
	Tickets.Empty(3);

	const FJiraTicket Ticket01 =
	{
		TEXT("MP-1234"),
		TEXT("Kill this ticket"),
		States[1],
		TEXT("Mat"),
		TEXT("Aslan"),
		EJiraTicketType::Bug,
    };
	Tickets.Add(Ticket01.Id, Ticket01);

	const FJiraTicket Ticket02 =
	{
		TEXT("MP-4321"),
        TEXT("Kill this ticket"),
        States[1],
        TEXT("Isabella"),
        TEXT("Mat"),
		EJiraTicketType::Bug,
    };
	Tickets.Add(Ticket02.Id, Ticket02);

	const FJiraTicket Ticket03 =
	{
		TEXT("MP-987"),
        TEXT("Kill this ticket"),
        States[1],
        TEXT("Brendan"),
        TEXT("Andrew"),
		EJiraTicketType::Bug,
    };
	Tickets.Add(Ticket03.Id, Ticket03);
}

const FName& UJiraSubsystem::GetProjectName() const
{
	return ProjectName;
}

int UJiraSubsystem::GetTicketCount() const
{
	return Tickets.Num();
}

TArray<FName> UJiraSubsystem::GetTicketIds(int Start, int End) const
{
	TArray<FName> Keys;
	Tickets.GenerateKeyArray(Keys);
	return Keys;
}

const FJiraTicket& UJiraSubsystem::GetTicket(const FName& TicketId) const
{
	return Tickets[TicketId];
}
