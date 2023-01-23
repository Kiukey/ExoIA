// Fill out your copyright notice in the Description page of Project Settings.


#include "Transition.h"
#include "State.h"

bool UTransition::IsValid()
{
	return false;
}

void UTransition::CallNext()
{

}

void UTransition::InitTransition(UFSM* _owner)
{
	owner = _owner;
}
