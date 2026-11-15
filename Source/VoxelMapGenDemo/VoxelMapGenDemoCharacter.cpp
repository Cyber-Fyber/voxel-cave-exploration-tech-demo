// Copyright Epic Games, Inc. All Rights Reserved.

#include "VoxelMapGenDemoCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "VoxelMapGenDemo.h"

AVoxelMapGenDemoCharacter::AVoxelMapGenDemoCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	// Create the first person mesh that will be viewed only by this character's owner
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));

	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));

	// Create the Camera Component	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(FirstPersonMesh, FName("head"));
	FirstPersonCameraComponent->SetRelativeLocationAndRotation(FVector(-2.8f, 5.89f, 0.0f), FRotator(0.0f, 90.0f, -90.0f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->bEnableFirstPersonFieldOfView = true;
	FirstPersonCameraComponent->bEnableFirstPersonScale = true;
	FirstPersonCameraComponent->FirstPersonFieldOfView = 70.0f;
	FirstPersonCameraComponent->FirstPersonScale = 0.6f;

	// configure the character comps
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;

	GetCapsuleComponent()->SetCapsuleSize(34.0f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;
}

void AVoxelMapGenDemoCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AVoxelMapGenDemoCharacter::DoJumpStart);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AVoxelMapGenDemoCharacter::DoJumpEnd);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVoxelMapGenDemoCharacter::MoveInput);

		// Looking/Aiming
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AVoxelMapGenDemoCharacter::LookInput);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AVoxelMapGenDemoCharacter::LookInput);

		EnhancedInputComponent->BindAction(MineAction, ETriggerEvent::Started, this, &AVoxelMapGenDemoCharacter::DoMineStart);
		EnhancedInputComponent->BindAction(MineAction, ETriggerEvent::Completed, this, &AVoxelMapGenDemoCharacter::DoMineEnd);

	}
	else
	{
		UE_LOG(LogVoxelMapGenDemo, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void AVoxelMapGenDemoCharacter::MoveInput(const FInputActionValue& Value)
{
	// get the Vector2D move axis
	FVector2D MovementVector = Value.Get<FVector2D>();

	// pass the axis values to the move input
	DoMove(MovementVector.X, MovementVector.Y);

	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(1, 10.0f, FColor::Green, FString::Printf(TEXT("I'm Moving")));
	//}

}

void AVoxelMapGenDemoCharacter::LookInput(const FInputActionValue& Value)
{
	// get the Vector2D look axis
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// pass the axis values to the aim input
	DoAim(LookAxisVector.X, LookAxisVector.Y);

	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(2, 10.0f, FColor::Blue, FString::Printf(TEXT("I'm Looking")));
	//}

}

void AVoxelMapGenDemoCharacter::DoAim(float Yaw, float Pitch)
{
	if (GetController())
	{
		// pass the rotation inputs
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AVoxelMapGenDemoCharacter::DoMove(float Right, float Forward)
{
	if (GetController())
	{
		// pass the move inputs
		AddMovementInput(GetActorRightVector(), Right);
		AddMovementInput(GetActorForwardVector(), Forward);
	}
}

void AVoxelMapGenDemoCharacter::DoJumpStart()
{
	// pass Jump to the character
	Jump();

	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(3, 10.0f, FColor::Red, FString::Printf(TEXT("I'm Jumping")));
	//}
}

void AVoxelMapGenDemoCharacter::DoJumpEnd()
{
	// pass StopJumping to the character
	StopJumping();
}

void AVoxelMapGenDemoCharacter::DoMineStart()
{

	if (GEngine)
	{
	//	GEngine->AddOnScreenDebugMessage(4, 10.0f, FColor::Yellow, FString::Printf(TEXT("Start Mining")));

		LineTrace();
	}


}

void AVoxelMapGenDemoCharacter::DoMineEnd()
{

	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(4, 10.0f, FColor::Yellow, FString::Printf(TEXT("Stop Mining")));
	//}

}

void AVoxelMapGenDemoCharacter::LineTrace()
{

	FVector PlayerLocation;
	FRotator PlayerRotation;

	GetController()->GetPlayerViewPoint(PlayerLocation, PlayerRotation);

	FVector LineTraceStart = PlayerLocation;
	FVector LineTraceEnd = LineTraceStart + (PlayerRotation.Vector() * MineDistance);

	FCollisionQueryParams TraceParams;
	FHitResult HitByLineTrace;
	bool bHit;


	bHit = GetWorld()->LineTraceSingleByChannel(HitByLineTrace, LineTraceStart, LineTraceEnd, ECC_Visibility, TraceParams);

	//DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor::Red, false, 2.0f);



	if (bHit)
	{
		//DrawDebugBox(GetWorld(), HitByLineTrace.ImpactPoint, FVector(5, 5, 5), FColor::Red, false, 2);

		//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("You have hit: %s"), *HitByLineTrace.GetActor()->GetName()));

		if (HitByLineTrace.GetActor()->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
		{
			Cast<IInteractionInterface>(HitByLineTrace.GetActor())->PlayerInteract();
		}
	}





}
