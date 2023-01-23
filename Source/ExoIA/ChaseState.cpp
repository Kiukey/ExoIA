// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseState.h"

void UChaseState::OnEnter(UFSM* _owner)
{
	Super::OnEnter(_owner);

	UE_LOG(LogTemp, Warning, TEXT("ENTER CHASE STATE"));
}

void UChaseState::OnUpdate()
{
	Super::OnUpdate();
}

void UChaseState::OnExit()
{
	Super::OnExit();
}

void UChaseState::DebugState()
{
	Super::DebugState();
}
