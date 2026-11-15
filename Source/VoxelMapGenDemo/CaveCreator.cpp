// Fill out your copyright notice in the Description page of Project Settings.


#include "CaveCreator.h"
#include "Voxel.h"

// Sets default values
ACaveCreator::ACaveCreator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

	CaveCreatorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cave Creator Mesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>CaveMesh(TEXT("/Game/Voxel/CaveCreatorMesh.CaveCreatorMesh"));


	if (CaveMesh.Succeeded())
	{
		CaveCreatorMesh->SetStaticMesh(CaveMesh.Object);
	}

}


// Called when the game starts or when spawned
void ACaveCreator::BeginPlay()
{
	Super::BeginPlay();
	
	int RandSizeX = FMath::RandRange(20, 40);
	int RandSizeY = FMath::RandRange(20, 40);
	int RandSizeZ = FMath::RandRange(5, 12);

	SetActorScale3D(FVector(RandSizeX, RandSizeY, RandSizeZ));

	CaveCreatorMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	CaveCreatorMesh->SetGenerateOverlapEvents(true);

	FTimerHandle DelayHandle;

	GetWorldTimerManager().SetTimer(DelayHandle, this, &ACaveCreator::DestroySelf , 3.0f, false);

	CaveCreatorMesh->SetVisibility(false);
	CaveCreatorMesh->SetCastShadow(false);

}

void ACaveCreator::DestroySelf()
{
	Destroy();
}

// Called every frame
void ACaveCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

