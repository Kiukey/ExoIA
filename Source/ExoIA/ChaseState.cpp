// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseState.h"
#include "ChaseToIdleTransition.h"

void UChaseState::OnEnter(UFSM* _owner)
{

	transitions.Add(NewObject<UChaseToIdleTransition>(this));
	Super::OnEnter(_owner);
	InitTransitions();
	UE_LOG(LogTemp, Warning, TEXT("ENTER DETECT STATE"));
}

void UChaseState::OnUpdate()
{
	Super::OnUpdate();
	
}

void UChaseState::OnExit()
{
	Super::OnExit();
	
	UE_LOG(LogTemp, Warning, TEXT("EXIT DETECT STATE"));
}

void UChaseState::DebugState()
{
	Super::DebugState();
	if (!owner)
		return;
	DrawDebugSphere(GetWorld(), owner->GetOwner()->GetActorLocation(), 100, 50, FColor::Yellow);
}

void UChaseState::InitTransitions()
{
	for (int i = 0; i < transitions.Num(); i++)
	{
		transitions[i]->InitTransition(owner);
	}
}
