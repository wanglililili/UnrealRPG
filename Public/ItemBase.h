// Copyright © 2013 - 2016 Truing Co.,Ltd All Rights Reserved.

#pragma once

#include "ItemBase.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EItemType : uint8
{
	IT_Voxel 	UMETA(DisplayName = "Voxel"),
	IT_Equipt 	UMETA(DisplayName = "Equiptment"),
	IT_Edible	UMETA(DisplayName = "Edible"),
	IT_Usable	UMETA(DisplayName = "Usable"),
	IT_Special	UMETA(DisplayName = "Special"),
	IT_Skill	UMETA(DisplayName = "Skill"),
	IT_Other	UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EItemQuality : uint8
{
	IQ_Poor		   	UMETA(DisplayName = "Poor"),
	IQ_Common		UMETA(DisplayName = "Common"),
	IQ_Uncommon	UMETA(DisplayName = "Uncommon"),
	IQ_Rare			UMETA(DisplayName = "Rare"),
	IQ_Epic			UMETA(DisplayName = "Epic"),
	IQ_Legendary		UMETA(DisplayName = "Legendary"),
	IQ_Count
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct UNREALRPG_API FItemBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 maxAmount;

	// type
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	EItemQuality Quality;

	// icon index in 2D
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UTexture2D* Icon;

	// mesh actor index  3D
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	AActor* Actor;

	FItemBase()
		: id(0)
		, amount(1)
		, maxAmount(1)
		, ItemType(EItemType::IT_Voxel)
		, Icon(nullptr)
		, Actor(nullptr)
	{}

	int32 RemainAmount();

	virtual bool IsBind();
	bool IsValid();

	static FItemBase None;
};
