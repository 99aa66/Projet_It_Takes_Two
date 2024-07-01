// Copyright Epic Games, Inc. All Rights Reserved.

#include "SplitScreen_Manu.h"

#define LOCTEXT_NAMESPACE "FSplitScreen_ManuModule"

void FSplitScreen_ManuModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSplitScreen_ManuModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSplitScreen_ManuModule, SplitScreen_Manu)