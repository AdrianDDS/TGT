// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TGTController.generated.h"


UCLASS(BlueprintType, Blueprintable)
class ANIMATIONTESTS_API  ATGTController : public APlayerController
{
	GENERATED_BODY()

public:
	ATGTController();

	/*virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;*/

	void Initialize();
};


