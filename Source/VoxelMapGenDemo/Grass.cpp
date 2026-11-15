// Fill out your copyright notice in the Description page of Project Settings.


#include "Grass.h"

AGrass::AGrass()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>GrassMaterial(TEXT("/Game/Voxel/M_GrassMaterial"));

	if (GrassMaterial.Succeeded())
	{
		GrassMat = GrassMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, GrassMat);
	}
}
