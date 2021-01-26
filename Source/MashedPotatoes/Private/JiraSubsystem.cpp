// Fill out your copyright notice in the Description page of Project Settings.


#include "JiraSubsystem.h"


FName UJiraSubsystem::GetProjectName() const
{
	return TEXT("Jira Project");
}

int UJiraSubsystem::GetTicketCount() const
{
	return 10;
}

TArray<FName> UJiraSubsystem::GetTicketIds(int Start, int End) const
{
	return TArray<FName>();
}

FJiraTicket UJiraSubsystem::GetTicket(const FName& TicketId) const
{
	return FJiraTicket();
}
