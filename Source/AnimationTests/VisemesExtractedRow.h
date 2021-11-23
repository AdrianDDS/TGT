// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "VisemesExtractedRow.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct ANIMATIONTESTS_API FVisemesExtractedRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Time;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Value;
};


