// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "AnimationTests/Camera/CameraPawn.h"
#include "TGTGameModeBase.generated.h"

/**
 * 
 */
UCLASS(HideCategories = (Cooking, LOD, Game))
class ANIMATIONTESTS_API ATGTGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game Settings|Gameplay")
	TSubclassOf<class ACameraPawn> CameraPawnClass;

private:
	UPROPERTY()
	ACameraPawn* CameraPawn;

public:
	ACameraPawn* GetCameraPawn() const;
};


