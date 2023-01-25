// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolToChaseTransition.h"
#include "FSM.h"
#include "IACharacter.h"
#include "ChaseState.h"

bool UPatrolToChaseTransition::IsValid()
{
	return sight ? sight->IsInSight() : false;
}

void UPatrolToChaseTransition::InitTransition(UFSM* _owner)
{
	Super::InitTransition(_owner);
	sight = Cast<AIACharacter>(_owner->GetOwner())->GetSightComponent();

}

void UPatrolToChaseTransition::CallNext()
{
	Super::CallNext();
	owner->SetNext<UChaseState>();
}
