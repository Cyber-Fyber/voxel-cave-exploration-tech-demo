// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Voxel.h"
#include "Bedrock.generated.h"

/**
 * 
 */
UCLASS()
class VOXELMAPGENDEMO_API ABedrock : public AVoxel
{
	GENERATED_BODY()
	

public:

	ABedrock();

private:

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	TObjectPtr<UMaterial> BedrockMat;

protected:

	virtual void PlayerInteract() override;

};
