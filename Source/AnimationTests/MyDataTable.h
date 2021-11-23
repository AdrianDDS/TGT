// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MyDataTable.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct  ANIMATIONTESTS_API FLevelUpData : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float start;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float end;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString word;
	
};
