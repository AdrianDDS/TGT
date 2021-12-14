// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "TGTGameModeBase.generated.h"

/**
 * 
 */
UCLASS(HideCategories = (Cooking, LOD, Game))
class ANIMATIONTESTS_API ATGTGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	void BeginPlay() override;
};


