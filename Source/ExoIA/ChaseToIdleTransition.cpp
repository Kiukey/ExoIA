// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseToIdleTransition.h"
#include "IdleState.h"
#include "FSM.h"

bool UChaseToIdleTransition::IsValid()
{
    if (!detector)
        return true;

    return detector->GetDistance() > 250;
}

void UChaseToIdleTransition::CallNext()
{
    Super::CallNext();

    owner->SetNext<UIdleState>();
}

void UChaseToIdleTransition::InitTransition(UFSM* _owner)
{
    Super::InitTransition(_owner);

    detector = Cast<UEnnemyDetector>(_owner->GetOwner()->GetComponentByClass(UEnnemyDetector::StaticClass()));
}
