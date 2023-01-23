// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseState.h"
#include "ChaseToIdleTransition.h"

void UChaseState::OnEnter(UFSM* _owner)
{
	Super::OnEnter(_owner);

	detector = Cast<UEnnemyDetector>(_owner->GetOwner()->GetComponentByClass(UEnnemyDetector::StaticClass()));

	transitions.Add(NewObject<UChaseToIdleTransition>(this));

	if (!detector)
		return;

	for (int i = 0; i < transitions.Num(); i++)
	{
		transitions[i]->InitTransition(owner);
	}
	detector->MovingState(true);

	UE_LOG(LogTemp, Warning, TEXT("ENTER CHASE STATE"));
}

void UChaseState::OnUpdate()
{
	Super::OnUpdate();
	
	for (int i = 0; i < transitions.Num(); i++)
	{
		if (transitions[i]->IsValid())
			transitions[i]->CallNext();
	}
}

void UChaseState::OnExit()
{
	Super::OnExit();

	if (!detector)
		return;
	detector->MovingState(false);
}

void UChaseState::DebugState()
{
	Super::DebugState();
}
