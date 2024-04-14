// Copyright 2024 Spyridon Zervos


#include "Modules/ModuleManager.h"

class FNotificationSystemModule : public IModuleInterface
{
	
public:

	FNotificationSystemModule();
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

FNotificationSystemModule::FNotificationSystemModule() {}

void FNotificationSystemModule::StartupModule() {}

void FNotificationSystemModule::ShutdownModule() {}

IMPLEMENT_MODULE(FNotificationSystemModule, NotificationSystem)