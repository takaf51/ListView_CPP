// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KawaiiListView.generated.h"


UCLASS(Abstract)
class LISTVIEW_CPP_API UKawaiiListView : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta=(BindWidget))
	class UListView *ListView;

	virtual void NativeConstruct() override;
	
	UPROPERTY( EditAnywhere, meta = (AllowedClasses = "KawaiiAssetDataModel") )
	FSoftObjectPath KawaiiDataAssetPath;
	
	UPROPERTY(EditAnywhere)
	int32 NumOfImage = 30;

private:

	UPROPERTY()
	TSoftObjectPtr<class UKawaiiAssetDataModel> KawaiiAssetData;

	struct FKawaiiStruct GetRandomDataFromAsset(); 

protected:
	// UPROPERTY(EditAnywhere, Category="Data Table")
	// class UDataTable* KawaiiDataTable;

private:
	// struct FKawaiiStruct* CreateKawaiiDataFromDataTable() const;
};
