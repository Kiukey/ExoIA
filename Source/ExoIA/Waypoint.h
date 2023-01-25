// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "Waypoint.generated.h"

UCLASS()
class EXOIA_API AWaypoint : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		UBillboardComponent* icon = nullptr;

public:	
	AWaypoint();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
