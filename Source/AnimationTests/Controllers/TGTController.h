// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TGTController.generated.h"


class ACameraPawn;
UCLASS(BlueprintType, Blueprintable)
class ANIMATIONTESTS_API  ATGTController : public APlayerController
{
	GENERATED_BODY()

	//Data Members:
	
public:
	ATGTController();

	/*virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;*/
private:
	UPROPERTY(Transient)
	ACameraPawn* m_cameraPawn;

	//Member Functions:
	
public:
	void Initialize();

private:
	void InitInputController();

	void OnLeftClick();
	void OnRightClick();
	
};


