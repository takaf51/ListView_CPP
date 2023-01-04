#include "MyGameEditor.h"

#define LOCTEXT_NAMESPACE "FMyGameEditorModule"

void FMyGameEditorModule::StartupModule()
{
}

void FMyGameEditorModule::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FMyGameEditorModule, MyGameEditor)