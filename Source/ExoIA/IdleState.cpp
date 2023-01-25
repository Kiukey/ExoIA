// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleState.h"
#include "IdleToPatrolTransition.h"
#include "PatrolToChaseTransition.h"
#include "PatrolState.h"

void UIdleState::OnEnter(UFSM* _owner)
{
	transitions.Add(NewObject<UPatrolToChaseTransition>(this));
	transitions.Add(NewObject<UIdleToPatrolTransition>(this));
	Super::OnEnter(_owner);
	
	UE_LOG(LogTemp, Warning, TEXT("ENTER IDLE"))
}

void UIdleState::OnUpdate()
{
	Super::OnUpdate();
}

void UIdleState::OnExit()
{
	Super::OnExit();
	UE_LOG(LogTemp, Warning, TEXT("EXIT IDLE"))
}

void UIdleState::DebugState()
{
	Super::DebugState();
	DrawDebugSphere(GetWorld(), owner->GetOwner()->GetActorLocation(), 100, 50, FColor::Blue);
}

void UIdleState::InitTransitions()
{
	for (int i = 0; i < transitions.Num(); i++)
	{
		transitions[i]->InitTransition(owner);
	}
}
