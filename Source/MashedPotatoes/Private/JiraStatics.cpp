// Fill out your copyright notice in the Description page of Project Settings.


#include "JiraStatics.h"

UJiraSubsystem* UJiraStatics::GetJira(UWorld* World)
{
	UJiraSubsystem* Jira = nullptr;
	if(nullptr != World)
	{
		UGameInstance* GameInst = World->GetGameInstance();
		if(nullptr != GameInst)
		{
			Jira = GameInst->GetSubsystem<UJiraSubsystem>();
		}
	}
	return Jira;
}
