// Fill out your copyright notice in the Description page of Project Settings.


#include "Coal.h"

ACoal::ACoal()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial>CoalMaterial(TEXT("/Game/Voxel/M_CoalMaterial"));

	if (CoalMaterial.Succeeded())
	{
		CoalMat = CoalMaterial.Object;
		VoxelCubeMesh->SetMaterial(0, CoalMat);
	}
}
