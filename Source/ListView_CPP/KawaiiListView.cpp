// Fill out your copyright notice in the Description page of Project Settings.


#include "KawaiiListView.h"
#include "KawaiiDataManager.h"
#include "Components/ListView.h"
// #include "Engine/DataTable.h"

void UKawaiiListView::NativeConstruct()
{
	Super::NativeConstruct();
	if(KawaiiAssetData) UE_LOG(LogTemp, Warning, TEXT("KawaiiDataAsset is not null"));
	for(int i = 0; i < NumOfImage; i++)
	{
		UKawaiiDataEntry* Entry = NewObject<UKawaiiDataEntry>();
		// Entry->KawaiiData = *CreateKawaiiDataFromDataTable();
		Entry->KawaiiData = GetRandomDataFromAsset();
		ListView->AddItem(Entry);
	}
}


FKawaiiStruct UKawaiiListView::GetRandomDataFromAsset()
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


// FKawaiiStruct* UKawaiiListView::CreateKawaiiDataFromDataTable() const
// {
// 	FKawaiiStruct* KData = nullptr;
// 	if(KawaiiDataTable)
// 	{
// 		TArray<FKawaiiStruct*> KawaiiDataArray;
// 		KawaiiDataTable->GetAllRows("", KawaiiDataArray);
// 		if(!KawaiiDataArray.IsEmpty())
// 		{
// 			const int32 Max = KawaiiDataArray.Num() - 1;
// 			KData =  KawaiiDataArray[FMath::RandRange(0, Max)];
// 		}
// 	}
// 	return KData;
// }
