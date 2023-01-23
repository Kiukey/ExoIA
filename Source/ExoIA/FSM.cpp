// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM.h"
#include "State.h"

UFSM::UFSM()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UFSM::BeginPlay()
{
	Super::BeginPlay();
	OnEnter();
}


void UFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	OnUpdate();
}

void UFSM::OnEnter()
{
}

void UFSM::OnUpdate()
{
	if (currentState)
		currentState->OnUpdate();
}

void UFSM::OnExit()
{

}