#include "TGTController.h"


#include "AnimationTests/GameModes/TGTGameModeBase.h"
#include "AnimationTests/Camera/CameraPawn.h"
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
		UE_LOG(LogTemp, Display, TEXT("Controller Initialized"));

		m_cameraPawn = gameMode->GetCameraPawn();
		if (m_cameraPawn)
		{
			Possess(m_cameraPawn);
			InitInputController();
		}
	}
}

void ATGTController::InitInputController()
{

	InputComponent->BindAction(TEXT("LeftClick"), IE_Pressed, this, &ATGTController::OnLeftClick);
	InputComponent->BindAction(TEXT("RightClick"), IE_Pressed, this, &ATGTController::OnRightClick);

	if(m_cameraPawn)
	{
		m_cameraPawn->SetupInput();
	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("WARNING: There is no Camera Pawn."));
	}
		
		
}

void ATGTController::OnLeftClick()
{
	UE_LOG(LogTemp, Display, TEXT("Left Clicked"));
}

void ATGTController::OnRightClick()
{
	UE_LOG(LogTemp, Display, TEXT("Right Clicked"));
}

