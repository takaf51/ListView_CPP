// Fill out your copyright notice in the Description page of Project Settings.


#include "KawaiiItemView.h"

#include "KawaiiDataManager.h"

void UKawaiiItemView::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UKawaiiDataEntry* Entry = Cast<UKawaiiDataEntry>(ListItemObject);

	IconName->SetText(FText::FromName(Entry->KawaiiData.IconName));
	IconImage->SetBrush(Entry->KawaiiData.IconImage);
}
