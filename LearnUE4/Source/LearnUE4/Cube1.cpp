// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube1.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ACube1::ACube1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Cube1Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	Cube1Mesh->SetSimulatePhysics(true);
	Cube1Mesh->SetupAttachment(RootComponent);
	Cube1Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere1->SetSimulatePhysics(true);
	Sphere1->InitSphereRadius(Radius);
	Sphere1->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	RootComponent = Sphere1;

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ACube1::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ACube1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACube1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACube1::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
	Destroy();
}

