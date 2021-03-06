// Copyright © 2013 - 2016 Truing Co.,Ltd All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "ItemComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALRPG_API UItemComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemComponentBase();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

};
