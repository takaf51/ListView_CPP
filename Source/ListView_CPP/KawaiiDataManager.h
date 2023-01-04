// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EditorAssetLibrary.h"
#include "Misc/MessageDialog.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"
#include "KawaiiDataManager.generated.h"


// Kawaii Structure
USTRUCT()	// BlueprintType
struct FKawaiiStruct //: public FTableRowBase <-for Datatable
{
	GENERATED_BODY()
	
	FKawaiiStruct(){}
	FKawaiiStruct(const FName Name, const FSlateBrush Image): IconName(Name), IconImage(Image){}
	
	UPROPERTY(EditAnywhere)
	FName IconName;

	UPROPERTY(EditAnywhere)
	FSlateBrush IconImage;
};


// Kawaii Data Entry
UCLASS()	// Blueprintable
class LISTVIEW_CPP_API UKawaiiDataEntry : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY()	// BlueprintReadWrite
	FKawaiiStruct KawaiiData;
};

// Kawaii Data Asset Model
UCLASS()	// BlueprintType
class LISTVIEW_CPP_API UKawaiiAssetDataModel : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)	// EditAnywhere, BlueprintReadOnly, Category="Data Setting"
	TArray<FKawaiiStruct> KawaiiData;

	UPROPERTY(EditAnywhere, Category="Data Setting", meta=(RelativeToGameContentDir))
	FDirectoryPath ImagePath;

	UFUNCTION(CallInEditor)
	void LoadData();
};


// load asset into Asset Data 
inline void UKawaiiAssetDataModel::LoadData()
{
	KawaiiData.Empty();
	const FString Path = FPaths::Combine("/Game/", ImagePath.Path);
	TArray<FString> Assets = UEditorAssetLibrary::ListAssets(Path, false);
	uint32 counter = 0;
	for(FString &Asset:Assets)
	{
		FAssetData AssetData = UEditorAssetLibrary::FindAssetData(Asset);
		if(AssetData.AssetClass.ToString() == "Texture2D")
		{
			FSlateBrush IconImage;
			IconImage.ImageSize = FVector2d(100.f, 100.f);
			IconImage.SetResourceObject(AssetData.GetAsset());
			KawaiiData.Add(FKawaiiStruct(AssetData.AssetName, IconImage));
			++counter;
			UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *AssetData.AssetClass.ToString());
		}
	}
	if(counter == 0)
	{
		const FText Title = FText::FromString("Warning");
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Select a Directory that has Images"), &Title);
	} else
	{
		FNotificationInfo NotifyInfo(FText::FromString(FString::FromInt(counter) + " Assets were Stored."));
		NotifyInfo.bUseLargeFont = true;
		NotifyInfo.FadeOutDuration = 7.f;
		FSlateNotificationManager::Get().AddNotification(NotifyInfo);
	}
}
