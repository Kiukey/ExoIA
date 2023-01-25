// Fill out your copyright notice in the Description page of Project Settings.


#include "Waypoint.h"

AWaypoint::AWaypoint()
{
	PrimaryActorTick.bCanEverTick = true;

	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;
}

void AWaypoint::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(50), FColor::Red);
}

