// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "Leap_NoPI.h"
#include "StaticMeshResources.h"
#include "ParticleDefinitions.h"
#include "ObjExport/ObjExporter.h"
#include "PaintBrushComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PAINTSPACE_API UPaintBrushComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPaintBrushComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, Category = "Painting")
	void SwitchStyle();

	UFUNCTION(BlueprintCallable, Category = "Painting")
	void ClearAllStrokes();

	UFUNCTION(BlueprintCallable, Category = "Painting")
	void ClearLastStroke();

	UFUNCTION(BlueprintCallable, Category = "Painting")
	void ChangeColors();

	UFUNCTION(BlueprintCallable, Category = "Export")
	void ExportObjBP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class APaintMaterial> PaintMaterial; // template for PaintMaterialInstance

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* SprayPaintFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* PenFX; // experimental pen-like drawing
	
private:
	void ProcessLeapFrame(Leap::Frame Frame, float DeltaSeconds);
	void Paint();
	void MeshPaint();
	void SprayPaint(bool Enable);
	void GenerateProceduralMesh(FInstancedStaticMeshInstanceData PrevMesh, FInstancedStaticMeshInstanceData CurrentMesh);
	void ExportObj();

	Leap::Controller LeapController;
	int64_t PrevFrameID;
	float Delay;
	float DelayWait;
	int PaintStyle;
	TArray<APaintMaterial*> PaintMaterialInstances;
	APaintMaterial* PaintMaterialInstance;
	UMaterialInstanceDynamic* MeshDynamicMat;
	FStaticMeshLODResources* LODModel;
	FPositionVertexBuffer* VertexBuffer;
	FVector PreviousLocation;
	FVector ScaleVector;
	float InterpolationUnitFactor;
	bool StrokeStart;
	TArray<int32> LastStrokes;
	int32 LastStrokeCount;
	int64_t ProceduralSectionIndex;
	UParticleSystemComponent* SprayPaintComponent;
	//UMaterialInstanceDynamic* ParticleDynamicMat;
	bool SprayPainting;
	UParticleSystemComponent* PenComponent;
	ObjExporter* ObjExporterInstance;
	float RefractoryWait;
	float RefractoryPeriod;

};
