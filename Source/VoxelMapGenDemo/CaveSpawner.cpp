// Fill out your copyright notice in the Description page of Project Settings.


#include "CaveSpawner.h"
#include "CaveCreator.h"
#include "Chunk.h"

// Sets default values
ACaveSpawner::ACaveSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;



	SpawnLoc = FVector(0, 0, 0);
	SpawnRot = FRotator::ZeroRotator;
	SpawnParams.OverrideLevel = GetLevel();
}

// Called when the game starts or when spawned
void ACaveSpawner::BeginPlay()
{
	Super::BeginPlay();

}



// Called every frame
void ACaveSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


