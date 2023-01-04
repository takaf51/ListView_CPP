// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KawaiiDataManager.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

#include "KawaiiItemView.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class LISTVIEW_CPP_API UKawaiiItemView : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta=(BindWidget))
	UTextBlock* IconName;

	UPROPERTY(meta=(BindWidget))
	UImage* IconImage;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	
};
