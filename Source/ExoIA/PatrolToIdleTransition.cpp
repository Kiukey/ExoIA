// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolToIdleTransition.h"
#include "FSM.h"
#include "IdleState.h"

bool UPatrolToIdleTransition::IsValid()
{
	if (!iaMovementComponent)
		return true;
	
	return iaMovementComponent->IsAtDestination();
}

void UPatrolToIdleTransition::CallNext()
{
	Super::CallNext();

	owner->SetNext<UIdleState>();
}

void UPatrolToIdleTransition::InitTransition(UFSM* _owner)
{
	Super::InitTransition(_owner);

	iaMovementComponent = Cast<UIAMovementComponent>(_owner->GetOwner()->GetComponentByClass(UIAMovementComponent::StaticClass()));
}
