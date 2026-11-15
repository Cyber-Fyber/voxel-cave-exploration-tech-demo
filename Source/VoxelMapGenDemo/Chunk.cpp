// Fill out your copyright notice in the Description page of Project Settings.


#include "Chunk.h"
#include "Cobble.h"
#include "Dirt.h"
#include "Grass.h"
#include "Diamond.h"
#include "Iron.h"
#include "Coal.h"
#include "Bedrock.h"
#include "CaveCreator.h"




//SpawnChunk()


// Sets default values
AChunk::AChunk()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ChunkSpawnLoc = FVector(0, 0, 0);
	SpawnRot = FRotator::ZeroRotator;
	SpawnParams.OverrideLevel = GetLevel();

}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();

	FVector VoxelScale = FVector(BaseVoxelMeasurement, BaseVoxelMeasurement, BaseVoxelMeasurement);

	FTimerHandle DelayHandle;

	SpawnCave();

	GetWorldTimerManager().SetTimer(DelayHandle, this, &AChunk::SpawnChunk, 0.5f, false);


	
}

void AChunk::SpawnChunk()
{

	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;

	ChunkSpawnLoc.Y = 0;
	ChunkSpawnLoc.X = 0;

	for (int ChunkLoopX = 0; ChunkLoopX < ChunkAmount; ChunkLoopX++)
	{
		for (int ChunkLoopY = 0; ChunkLoopY < ChunkAmount; ChunkLoopY++)
		{
			for (int z = 0; z < ChunkZ; z++)
			{
				for (int y = 0; y < ChunkY; y++)
				{
					for (int x = 0; x < ChunkX; x++)
					{
						int DiamondChance = FMath::RandRange(1, 300);
						int CoalChance = FMath::RandRange(1, 50);
						int IronChance = FMath::RandRange(1, 80);

						ChunkSpawnLoc.X += BaseVoxelMeasurement * 100;


						if (z == ChunkZ - 1)
						{
							Chunk[x][y][z] = GetWorld()->SpawnActor<AGrass>(ChunkSpawnLoc, SpawnRot, SpawnParams);
						}
						else if (z > 75.0f * (ChunkZ / 100.0f))
						{
							Chunk[x][y][z] = GetWorld()->SpawnActor<ADirt>(ChunkSpawnLoc, SpawnRot, SpawnParams);
						}
						else if (z > 60.0f * (ChunkZ / 100.0f))
						{
							int DirtChance = FMath::RandRange(1, 10);
							{
								if (DirtChance > 2)
								{
									Chunk[x][y][z] = GetWorld()->SpawnActor<ADirt>(ChunkSpawnLoc, SpawnRot, SpawnParams);
								}
							}
							Chunk[x][y][z] = GetWorld()->SpawnActor<ACobble>(ChunkSpawnLoc, SpawnRot, SpawnParams);
						}
						else if (z == 0)
						{
							Chunk[x][y][z] = GetWorld()->SpawnActor<ABedrock>(ChunkSpawnLoc, SpawnRot, SpawnParams);
						}
						else
						{
							if (DiamondChance == 1)
							{
								Chunk[x][y][z] = GetWorld()->SpawnActor<ADiamond>(ChunkSpawnLoc, SpawnRot, SpawnParams);
							}
							if (CoalChance == 1)
							{
								Chunk[x][y][z] = GetWorld()->SpawnActor<ACoal>(ChunkSpawnLoc, SpawnRot, SpawnParams);
							}
							if (IronChance == 1)
							{
								Chunk[x][y][z] = GetWorld()->SpawnActor<AIron>(ChunkSpawnLoc, SpawnRot, SpawnParams);
							}

							Chunk[x][y][z] = GetWorld()->SpawnActor<ACobble>(ChunkSpawnLoc, SpawnRot, SpawnParams);
						}

					}

					ChunkSpawnLoc.X -= ChunkX * (BaseVoxelMeasurement * 100);
					ChunkSpawnLoc.Y += (BaseVoxelMeasurement * 100);

				}

				ChunkSpawnLoc.Y -= ChunkY * (BaseVoxelMeasurement * 100);
				ChunkSpawnLoc.Z += (BaseVoxelMeasurement * 100);

			}

			ChunkSpawnLoc.Y += 2400;
			ChunkSpawnLoc.Z = 0;

		}

		ChunkSpawnLoc.X += 2400;
		ChunkSpawnLoc.Y = 0;

	}

	LoadingComplete = 1;
}

void AChunk::SpawnCave()
{
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;


	for (int ChunksX = 0; ChunksX < ChunkAmount; ChunksX++)
	{
		for (int ChunksY = 0; ChunksY < ChunkAmount; ChunksY++)
		{
			for (int i = 0; i < 10; i++)
			{
				int CaveChance = FMath::RandRange(1, 10);

				if (CaveChance > 2)
				{
					FVector SpawnOffset = FVector(FMath::RandRange(0, 3000), FMath::RandRange(0, 3000), FMath::RandRange(800, 1500));

					ACaveCreator* CaveCreator = GetWorld()->SpawnActor<ACaveCreator>(ChunkSpawnLoc + SpawnOffset, SpawnRot, SpawnParams);
				}
			}
			ChunkSpawnLoc.Y += 2400;
		}
		
		ChunkSpawnLoc.X += 2400;
		ChunkSpawnLoc.Y = 0;
	}
	
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

