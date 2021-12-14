#include "TGTController.h"


#include "AnimationTests/GameModes/TGTGameModeBase.h"
#include "Kismet/GameplayStatics.h"

ATGTController::ATGTController()
{
}

void ATGTController::Initialize()
{
	EnableInput(this);

	ATGTGameModeBase* gameMode = Cast<ATGTGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (gameMode)
	{
		UE_LOG(LogTemp, Display, TEXT("Initialized!!!"));
		//gameMode->
		/*	if (gameMode->CameraPawn)
		{
			Possess(gameMode->CameraPawn);
		}*/
	}
}
