// Fill out your copyright notice in the Description page of Project Settings.


#include "TGTGameModeBase.h"

#include "AnimationTests/Controllers/TGTController.h"

void ATGTGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	UGameInstance* GameInstance = GetWorld()->GetGameInstanceChecked<UGameInstance>();

	if (!GameInstance)
	{
		UE_LOG(LogTemp,Fatal, TEXT("FATAL ERROR: Something happened starting the game."));
		return;
	}
	UWorld* world = GetWorld();
	 
	if(world)
	{
		ATGTController* Controller = Cast<ATGTController>(world->GetFirstPlayerController());
		Controller->Initialize();
	}
	
	
}
