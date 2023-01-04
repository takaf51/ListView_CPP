// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "MyGameEditor_UtilityWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYGAMEEDITOR_API UMyGameEditor_UtilityWidget : public UEditorUtilityWidget
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
	
};
