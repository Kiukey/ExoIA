#include "PatrolState.h"
#include "IdleState.h"
#include "PatrolToIdleTransition.h"
#include "PatrolToChaseTransition.h"
#include "IACharacter.h"

void UPatrolState::OnEnter(UFSM* _owner)
{
	transitions.Add(NewObject<UPatrolToChaseTransition>(this));
	transitions.Add(NewObject<UPatrolToIdleTransition>(this));
	Super::OnEnter(_owner);
	movementComponent = Cast<AIACharacter>(_owner->GetOwner())->GetMovementComponent();
	if (!movementComponent)
		return;
	InitTransitions();
	
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

}

void UPatrolState::OnExit()
{
	Super::OnExit();
	movementComponent->StopMoving();
	UE_LOG(LogTemp, Warning, TEXT("EXIT PATROL"))
}

void UPatrolState::DebugState()
{
	Super::DebugState();
	DrawDebugSphere(GetWorld(), owner->GetOwner()->GetActorLocation(), 100, 50, FColor::Green);
}

void UPatrolState::InitTransitions()
{
	for (int i = 0; i < transitions.Num(); i++)
	{
		transitions[i]->InitTransition(owner);
	}
}
