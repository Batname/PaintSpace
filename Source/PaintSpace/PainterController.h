// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
//#include "Runtime/UMG/Public/UMG.h"
#include "Leap_NoPI.h"
#include "PainterController.generated.h"

/**
 * 
 */
UCLASS()
class PAINTSPACE_API APainterController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	APainterController();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	//TSubclassOf<class UHandMenuWidget> HandMenuWidgetTemplate;

	virtual void BeginPlay() override;

private:
	//UPROPERTY()
	//UHandMenuWidget* HandMenuWidgetInstance;

	Leap::Controller LeapController;
	int64_t PrevFrameID;
	
};
