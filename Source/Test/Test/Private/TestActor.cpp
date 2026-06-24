// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	SetRootComponent(CubeMesh); 

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(
		TEXT("/Engine/BasicShapes/Cube.Cube") // 큐브 스태틱 메쉬 코드에서 추가
	);

	if (CubeAsset.Succeeded())
	{
		CubeMesh->SetStaticMesh(CubeAsset.Object);
		CubeMesh->SetWorldScale3D(FVector(1.0f));
	}
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	// TestActor가 실제 월드에 스폰되어 BeginPlay까지 실행되었는지 확인하기 위한 로그
	UE_LOG(LogTemp, Warning, TEXT("Test Actor Beginplay"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Test Actor Beginplay"));
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

