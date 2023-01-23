// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardFSM.h"
#include "IdleState.h"

void UGuardFSM::OnEnter()
{
	Super::OnEnter();

	SetNext<UIdleState>();
}
