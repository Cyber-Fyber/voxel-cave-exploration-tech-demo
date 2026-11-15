// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Voxel.h"
#include "Chunk.generated.h"

constexpr int ChunkX = 24;
constexpr int ChunkY = 24;
constexpr int ChunkZ = 24;

UCLASS()
class VOXELMAPGENDEMO_API AChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// would not compile if this was a bool
	UPROPERTY(BlueprintReadWrite, Category = "Chunk")
	int32 LoadingComplete = 0;


	AVoxel* Chunk[ChunkX][ChunkY][ChunkZ];

	int ChunkAmount = 2;

	void SpawnChunk();
	void SpawnCave();

	FVector ChunkSpawnLoc;
	FRotator SpawnRot;
	FActorSpawnParameters SpawnParams;

	float  BaseVoxelMeasurement = 1;

	int VoxelCount;






public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
