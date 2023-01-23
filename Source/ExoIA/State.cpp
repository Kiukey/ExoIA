// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"

void UState::OnEnter(UFSM* _owner)
{
	owner = _owner;
}

void UState::OnUpdate()
{
}

void UState::OnExit()
{
	transition = nullptr;
}

void UState::DebugState()
{
}
