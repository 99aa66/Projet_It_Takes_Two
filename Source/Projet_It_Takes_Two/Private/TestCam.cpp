// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCam.h"

// Sets default values
ATestCam::ATestCam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestCam::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestCam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

