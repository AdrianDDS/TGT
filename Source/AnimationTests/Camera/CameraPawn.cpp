#include "CameraPawn.h"

#include "GameFramework/SpringArmComponent.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

ACameraPawn::ACameraPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent->AddWorldOffset(FVector(-50.f, 0.f, 50.f));
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	
}

void ACameraPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SolveMovement(DeltaSeconds);
}

void ACameraPawn::SetupPlayerInputComponent(UInputComponent*)
{
	
	Super::SetupPlayerInputComponent(InputComponent);
	
	InputComponent->BindAxis(TEXT("MoveForward"), this, &ACameraPawn::MoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &ACameraPawn::MoveRight);
	InputComponent->BindAxis(TEXT("MoveUp"), this, &ACameraPawn::OnMoveZ);
	
	InputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput); 
	InputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
}

void ACameraPawn::SolveMovement(float _deltaSeconds)
{
	if (!m_direction.IsNearlyZero())
	{
		m_direction.Normalize();
		const FVector displacement = m_direction * MovementSpeed *_deltaSeconds;
		AddActorLocalOffset(displacement);

		m_direction = FVector::ZeroVector;
		//DrawDebugSphere(GetWorld(), GetActorLocation(), 50.f, 50, FColor::Red);
	}
	
}

void ACameraPawn::MoveForward(float _value)
{
	if (abs(_value) > 0.0f)
	{
		m_direction += FVector(_value, 0.f, 0.f);
	}
}

void ACameraPawn::MoveRight(float _value)
{
	if (abs(_value) > 0.0f)
	{
		m_direction += FVector( 0.f, _value, 0.f);
	}
}

void ACameraPawn::OnMoveZ(float _value)
{
	if (abs(_value) > 0.0f)
	{
		m_direction += FVector( 0.f, 0.f, -_value);
	}
}

