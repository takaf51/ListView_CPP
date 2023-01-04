// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameEditor_UtilityWidget.h"
#include "Components/ListView.h"
#include "ListView_CPP/KawaiiDataManager.h"

void UMyGameEditor_UtilityWidget::NativeConstruct()
{
	Super::NativeConstruct();

	for(int i = 0; i < NumOfImage; i++)
	{
		UKawaiiDataEntry* Entry = NewObject<UKawaiiDataEntry>();
		Entry->KawaiiData = GetRandomDataFromAsset();
		ListView->AddItem(Entry);
	}
}

FKawaiiStruct UMyGameEditor_UtilityWidget::GetRandomDataFromAsset()
{
	FKawaiiStruct KData;
	if(KawaiiAssetData == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("KawaiiDataAssetPath: %s"), *KawaiiDataAssetPath.ToString());
		if(KawaiiDataAssetPath.IsNull()) return KData;
		KawaiiAssetData = Cast<UKawaiiAssetDataModel>(StaticLoadObject(UKawaiiAssetDataModel::StaticClass(), nullptr, *KawaiiDataAssetPath.ToString()));
		if(KawaiiAssetData == nullptr) return KData;
	}
	const int32 Max = KawaiiAssetData->KawaiiData.Num() - 1;
	KData = KawaiiAssetData->KawaiiData[FMath::RandRange(0, Max)];
	return  KData;
}
