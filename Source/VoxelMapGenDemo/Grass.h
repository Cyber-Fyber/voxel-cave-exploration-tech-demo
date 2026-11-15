// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Voxel.h"
#include "Grass.generated.h"

/**
 * 
 */
UCLASS()
class VOXELMAPGENDEMO_API AGrass : public AVoxel
{
	GENERATED_BODY()
	
private:

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	TObjectPtr<UMaterial> GrassMat;

public:

	AGrass();

};
