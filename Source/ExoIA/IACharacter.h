// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IAMovementComponent.h"
#include "DetectSightsComponent.h"
#include "IACharacter.generated.h"


class UGuardFSM;

UCLASS()
class EXOIA_API AIACharacter : public ACharacter
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<UGuardFSM> iaFSM = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UIAMovementComponent> iaMovement = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UDetectSightsComponent> sight = nullptr;

public:
	AIACharacter();

	FORCEINLINE UGuardFSM* GetIAFSM() { return iaFSM; }
	FORCEINLINE UIAMovementComponent* GetMovementComponent() { return iaMovement; }
	FORCEINLINE UDetectSightsComponent* GetSightComponent() { return sight; }

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
