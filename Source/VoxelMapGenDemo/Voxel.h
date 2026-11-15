// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "Voxel.generated.h"

UCLASS()
class VOXELMAPGENDEMO_API AVoxel : public AActor, public::IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVoxel();

	virtual void SwitchTextureDirt();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh");
	TObjectPtr<UStaticMeshComponent> VoxelCubeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh");
	TObjectPtr<UMaterial> VoxelCubeMaterial;


	virtual void PlayerInteract() override;


	FActorSpawnParameters VoxelSpawnParams;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
