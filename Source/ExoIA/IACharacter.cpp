// Fill out your copyright notice in the Description page of Project Settings.


#include "IACharacter.h"
#include "GuardFSM.h"

AIACharacter::AIACharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	iaFSM = CreateDefaultSubobject<UGuardFSM>("iaFSM");
	iaMovement = CreateDefaultSubobject<UIAMovementComponent>("Movements");
	sight = CreateDefaultSubobject<UDetectSightsComponent>("Sight");
	AddOwnedComponent(iaFSM);
	AddOwnedComponent(sight);
	AddOwnedComponent(iaMovement);

}

void AIACharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AIACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

