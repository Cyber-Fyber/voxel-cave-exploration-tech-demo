// Fill out your copyright notice in the Description page of Project Settings.


#include "Voxel.h"
#include "Bedrock.h"

// Sets default values
AVoxel::AVoxel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	VoxelCubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Voxel Cube Mesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>VoxelMesh(TEXT("/Game/Voxel/VoxelCubeMesh.VoxelCubeMesh"));
	static ConstructorHelpers::FObjectFinder<UMaterial>VoxelMaterial(TEXT("/Game/Voxel/M_VoxelCubeMaterial.M_VoxelCubeMaterial"));

	if (VoxelMesh.Succeeded())
	{
		VoxelCubeMesh->SetStaticMesh(VoxelMesh.Object);
	}
	if (VoxelMaterial.Succeeded())
	{
		VoxelCubeMaterial = VoxelMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, VoxelCubeMaterial);
	}

	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));

	VoxelCubeMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	VoxelCubeMesh->SetGenerateOverlapEvents(true);

}





// Called when the game starts or when spawned
void AVoxel::BeginPlay()
{
	Super::BeginPlay();
	

	VoxelSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;

}





void AVoxel::PlayerInteract()
{
	Destroy();
}



void AVoxel::SwitchTextureDirt()
{
	static ConstructorHelpers::FObjectFinder<UMaterial>VoxelMaterial(TEXT("//Game/Voxel/M_DirtMaterial.M_DirtMaterial"));

	if (VoxelMaterial.Succeeded())
	{
		VoxelCubeMaterial = VoxelMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, VoxelCubeMaterial);
	}
}

// Called every frame
void AVoxel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

