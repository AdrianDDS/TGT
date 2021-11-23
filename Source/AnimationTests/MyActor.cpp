// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "DataTableRow.h"
#include "VisemesExtractedRow.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "Engine/DataTable.h"
#include "Misc/Paths.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::SetFrame(FString _stringToSearch)
{
	for (int i{ 0 }; i < m_visemesData.Num(); i++)
	{
		if (m_visemesData[i])
		{
			TArray<FString> visemes = m_visemesData[i]->Visemas;
			if (testing)
			{
				if(visemes.Contains(VisemeTest))
				{
					m_frame = m_visemesData[i]->frame;
					break;
				}
			}
			else
			{
				if (visemes.Contains(_stringToSearch))
				{
					if(m_frame != m_visemesData[i]->frame)
					{
						m_frame = m_visemesData[i]->frame;
						const float Dice = FMath::RandRange(0.f, 1.f);
						if(Dice>SkipProbability)
						{
							FlipbookComponent->SetPlaybackPositionInFrames(m_frame, false);
						}
					}
					break;
				}
				
			}
			
		}
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<UPaperFlipbookComponent*> comps;

	this->GetComponents(comps);

	
	if(comps.Num()>0 && DataTableVisemes)
	{
		DataTableVisemes->GetAllRows(FString("Error getting data from Visemes Data Table"), m_visemesData);
		DataTableDialog->GetAllRows(FString("Error getting data from Dialog Data Table"), m_dialogData);
		
		FlipbookComponent = comps[0];

		if(FlipbookComponent)
		{
			FlipbookComponent->SetPlayRate(0.0f);

			if (testing && m_visemesData.Num() > 0)
			{
				if (m_frame >= FlipbookComponent->GetFlipbookLengthInFrames())
				{
					m_frame = 0;
				}
			}
		}
	}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!m_silenced)
	{
		m_sigmaSeconds += DeltaTime * DialogSpeed * 1000;

		if(!m_talking && Dialog)
		{
			Dialog->AddPlayingSource();
		}

		if(m_dialogIndex <m_dialogData.Num())			
		{
			if( m_dialogData[m_dialogIndex] && m_sigmaSeconds >= m_dialogData[m_dialogIndex]->Time)
			{
				SetFrame(m_dialogData[m_dialogIndex]->Value);
				
				m_dialogIndex++;
			}
		}
		else
		{
			if (FlipbookComponent)
			{
				FlipbookComponent->SetPlaybackPositionInFrames(0, false);
			}
			
			m_dialogIndex = 0;
			m_sigmaSeconds = 0.f;
			m_silenced = true;
		}

	}
}

