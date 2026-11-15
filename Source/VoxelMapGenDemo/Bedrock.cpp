// Fill out your copyright notice in the Description page of Project Settings.


#include "Bedrock.h"

ABedrock::ABedrock()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>BedrockMaterial(TEXT("/Game/Voxel/M_BedrockMaterial"));

	if (BedrockMaterial.Succeeded())
	{
		BedrockMat = BedrockMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, BedrockMat);
	}
}

void ABedrock::PlayerInteract()
{
	// overwrite interaction
}
