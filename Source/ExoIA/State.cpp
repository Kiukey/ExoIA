// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"

void UState::OnEnter(UFSM* _owner)
{
	owner = _owner;
	InitTransitions();
}

void UState::OnUpdate()
{
	CheckForTransition();
	DebugState();
}

void UState::OnExit()
{
	for (int i = 0; i < transitions.Num(); i++)
		transitions[i] = nullptr;
	
	transitions.Empty();
}

void UState::DebugState()
{
}

void UState::InitTransitions()
{
}

void UState::CheckForTransition()
{
	for (int i = 0; i < transitions.Num(); i++)
	{
		if (transitions[i]->IsValid())
		{
			transitions[i]->CallNext();
			return;
		}
	}
}
