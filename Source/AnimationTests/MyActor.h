// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"




#include "GameFramework/Actor.h"

#include "MyActor.generated.h"

struct FVisemesExtractedRow;
struct FDataTableRow;
class UDataTable;
class UPaperFlipbookComponent;
class UPaperFlipbook;

UCLASS()
class ANIMATIONTESTS_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	

	UPaperFlipbookComponent* FlipbookComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TGT")
	UDataTable* DataTableVisemes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TGT")
	UDataTable* DataTableDialog;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TGT")
	USoundWave* Dialog;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TGT", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float SkipProbability=0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TGT", meta = (ClampMin = "0.0", ClampMax = "2.0"))
	float DialogSpeed = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TGT|testing")
	bool testing=false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TGT|testing", meta = (EditCondition = "testing", EditConditionHides))
	FString VisemeTest;

private:

	bool m_talking = false;
	
	int32 m_frame = 0;

	int32 m_dialogIndex = 0;

	int32 m_sigmaSeconds = 0;

	bool m_silenced = false;

	TArray<const FDataTableRow*> m_visemesData;

	TArray<const FVisemesExtractedRow*> m_dialogData;
	
public:
	// Sets default values for this actor's properties
	AMyActor();

private:
	void SetFrame(FString _stringToSearch);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
