// Copyright Noa Second 2026. All Rights Reserved.
#pragma once

#include "Modules/ModuleManager.h"

class FBlueprintProjectSettingsModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};