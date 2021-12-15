// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "CameraPawn.generated.h"


UCLASS(BlueprintType, Blueprintable)
class ANIMATIONTESTS_API  ACameraPawn : public APawn
{
	GENERATED_BODY()

	//Member Variables:
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 100;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 50;
	
private:
	UPROPERTY()
	FVector m_direction;

	UPROPERTY()
	FRotator m_rotateDirection;
	
	//Member Functions:
public:
	ACameraPawn();

	virtual void Tick(float DeltaSeconds) override;
	void SetupInput();

	
private:
	void SolveMovement(float _deltaSeconds);
	
	void MoveForward(float _value);
	void MoveRight(float _value);
	void OnMoveZ(float _value);
	
};


