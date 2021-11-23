// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "DataTableRow.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct ANIMATIONTESTS_API FDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Visemas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 frame;
};


