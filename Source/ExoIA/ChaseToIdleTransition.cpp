// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseToIdleTransition.h"
#include "IdleState.h"
#include "IACharacter.h"
#include "FSM.h"

bool UChaseToIdleTransition::IsValid()
{
    if (!sight)
        return false;

    return !sight->IsInSight();
}

void UChaseToIdleTransition::CallNext()
{
    Super::CallNext();

    owner->SetNext<UIdleState>();
}

void UChaseToIdleTransition::InitTransition(UFSM* _owner)
{
    Super::InitTransition(_owner);

    sight = Cast<AIACharacter>(_owner->GetOwner())->GetSightComponent();
}
