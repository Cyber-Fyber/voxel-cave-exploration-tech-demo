// Fill out your copyright notice in the Description page of Project Settings.


#include "Diamond.h"

ADiamond::ADiamond()
{

	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>DiamondMaterial(TEXT("/Game/Voxel/M_DiamondMaterial"));

	if (DiamondMaterial.Succeeded())
	{
		DiamondMat = DiamondMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, DiamondMat);
	}
}
