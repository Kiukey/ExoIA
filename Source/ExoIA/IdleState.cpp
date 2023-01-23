// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleState.h"
#include "IdleToPatrolTransition.h"
#include "PatrolState.h"

void UIdleState::OnEnter(UFSM* _owner)
{
	Super::OnEnter(_owner);
	//transition = NewObject<UIdleToPatrolTransition>(this);
	//transition->InitTransition(_owner);
	transitions.Add(NewObject<UIdleToPatrolTransition>(this));
	for (int i = 0; i < transitions.Num(); i++)
	{
		transitions[i]->InitTransition(_owner);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("ENTER IDLE"))
}

void UIdleState::OnUpdate()
{
	Super::OnUpdate();
	//if (!transition)
	//	return;
	//if (transition->IsValid())
	//	transition->CallNext();
	for (int i = 0; i < transitions.Num(); i++)
	{
		if (transitions[i]->IsValid())
		{
			transitions[i]->CallNext();
			return;
		}
	}

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
