// Fill out your copyright notice in the Description page of Project Settings.


#include "Dirt.h"

ADirt::ADirt()
{
	PrimaryActorTick.bCanEverTick = false;


	static ConstructorHelpers::FObjectFinder<UMaterial>DirtMaterial(TEXT("/Game/Voxel/M_DirtMaterial"));

	if (DirtMaterial.Succeeded())
	{
		DirtMat = DirtMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, DirtMat);
	}

}
