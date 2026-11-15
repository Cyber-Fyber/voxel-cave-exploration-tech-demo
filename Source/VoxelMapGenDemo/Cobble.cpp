// Fill out your copyright notice in the Description page of Project Settings.


#include "Cobble.h"

ACobble::ACobble()
{

	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>CobbleMaterial(TEXT("/Game/Voxel/M_CobbleMaterial"));

	if (CobbleMaterial.Succeeded())
	{
		CobbleMat = CobbleMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, CobbleMat);
	}
}
