// Fill out your copyright notice in the Description page of Project Settings.


#include "Iron.h"

AIron::AIron()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>IronMaterial(TEXT("/Game/Voxel/M_IronMaterial"));

	if (IronMaterial.Succeeded())
	{
		IronMat = IronMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, IronMat);
	}
}
