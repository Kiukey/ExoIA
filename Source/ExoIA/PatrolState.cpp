#include "PatrolState.h"
#include "IdleState.h"
#include "PatrolToIdleTransition.h"
#include "PatrolToChaseTransition.h"

void UPatrolState::OnEnter(UFSM* _owner)
{
	Super::OnEnter(_owner);

	//transition = NewObject<UPatrolToIdleTransition>(this);
	//transition->InitTransition(_owner);
	transitions.Add(NewObject<UPatrolToIdleTransition>(this));
	transitions.Add(NewObject<UPatrolToChaseTransition>(this));

	movementComponent = Cast<UIAMovementComponent>(_owner->GetOwner()->GetComponentByClass(UIAMovementComponent::StaticClass()));
	if (!movementComponent)
		return;
	for (int i = 0; i < transitions.Num(); i++)
	{
		transitions[i]->InitTransition(_owner);
	}
	movementComponent->StartMoving();
	UE_LOG(LogTemp,Warning,TEXT("ENTER PATROL"))
}

void UPatrolState::OnUpdate()
{
	Super::OnUpdate();
	
	//if (!transition)
	//	return;
	//if (transition->IsValid())
	//	transition->CallNext();

	for (int i = 0; i < transitions.Num(); i++)
	{
		if (transitions[i]->IsValid())
		{
			transitions[i]->CallNext();
			return;
		}
	}
}

void UPatrolState::OnExit()
{
	Super::OnExit();

	UE_LOG(LogTemp, Warning, TEXT("EXIT PATROL"))
}

void UPatrolState::DebugState()
{
	Super::DebugState();
	DrawDebugSphere(GetWorld(), owner->GetOwner()->GetActorLocation(), 100, 50, FColor::Green);
}
