// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dirt.h"
#include "Diamond.generated.h"

/**
 * 
 */
UCLASS()
class VOXELMAPGENDEMO_API ADiamond : public ADirt
{
	GENERATED_BODY()
	
public:

	ADiamond();

private:

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	TObjectPtr<UMaterial> DiamondMat;
};
