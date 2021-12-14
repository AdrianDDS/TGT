#include "CameraPawn.h"

#include "GameFramework/SpringArmComponent.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

ACameraPawn::ACameraPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	
}

void ACameraPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SolveMovement(DeltaSeconds);
}

void ACameraPawn::SetupInput()
{
	InputComponent->BindAxis(TEXT("MoveForward"), this, &ACameraPawn::OnMoveX);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &ACameraPawn::OnMoveY);
	InputComponent->BindAxis(TEXT("MoveUp"), this, &ACameraPawn::OnMoveZ);

	InputComponent->BindAxis(TEXT("Turn"), this, &ACameraPawn::OnRotateCameraX); 
	InputComponent->BindAxis(TEXT("LookUp"), this, &ACameraPawn::OnRotateCameraY); 
}

void ACameraPawn::SolveMovement(float _deltaSeconds)
{
	//Solve Location
	if (!m_direction.IsNearlyZero())
	{
		m_direction.Normalize();
		const FVector displacement = m_direction * MovementSpeed *_deltaSeconds;
		AddActorLocalOffset(displacement);

		UE_LOG(LogTemp, Display, TEXT("Displaced (%f, %f, %f)"), displacement.X, displacement.Y, displacement.Z);
		m_direction = FVector::ZeroVector;
		DrawDebugSphere(GetWorld(), GetActorLocation(), 50.f, 50, FColor::Red);
		
	}

	//Solve Rotation
	if (!m_rotateDirection.IsNearlyZero())
	{
		m_rotateDirection.Normalize();
		FRotator rotator = m_rotateDirection * RotationSpeed * _deltaSeconds;
		//AddActorLocalRotation(rotator);

		//SpringArmComponent.Pitch = FRotator::NormalizeAxis(m_rotateDirection.Pitch);
		RootComponent->AddLocalRotation(FRotator(rotator.Pitch, 0, 0));
		SpringArmComponent->AddRelativeRotation(FRotator(0, rotator.Yaw,0));
		//SpringArmComponent->AddRelativeRotation(rotator);
		m_rotateDirection = FRotator::ZeroRotator;

		
	}
	
}

void ACameraPawn::OnMoveX(float _value)
{
	if (abs(_value) > 0.0f)
	{
		m_direction += FVector(_value, 0.f, 0.f);
	}
}

void ACameraPawn::OnMoveY(float _value)
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

void ACameraPawn::OnRotateCameraX(float _value)
{
	m_rotateDirection += FRotator(0.f, _value, 0.f);
}

void ACameraPawn::OnRotateCameraY(float _value)
{
	m_rotateDirection += FRotator(_value, 0.f,  0.f);
	//m_rotateDirection.Pitch = FRotator::NormalizeAxis(m_rotateDirection.Pitch);
}