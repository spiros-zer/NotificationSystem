// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "NotificationActionContext.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "NotificationSystem.generated.h"

class UNotificationDescriptor;

/**
 * Delegate to be fired when the player interacts with the notification. It passes the
 * ENotificationActionContext that the player chose.
 */
DECLARE_DELEGATE_OneParam(FNotificationActionDelegate, ENotificationActionContext);

/**
 * Core of the notification system plugin. Responsible for (de)initialization and displaying notifications. Must
 * be subclassed to work properly.
 */
UCLASS(Abstract)
class NOTIFICATIONSYSTEM_API UNotificationSystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	
	UNotificationSystem() {}

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	/**
	 * Manages the display of a notification of type NotificationType the callback to be triggered. Must be
	 * overriden by the child classes. It should be the point where the notification is shown to the player.
	 */
	virtual void ShowNotification(UNotificationDescriptor* NotificationType,
		FNotificationActionDelegate ResultCallback = FNotificationActionDelegate());
};

inline void UNotificationSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

inline void UNotificationSystem::Deinitialize()
{
	Super::Deinitialize();
}

inline void UNotificationSystem::ShowNotification(UNotificationDescriptor* NotificationType,
	FNotificationActionDelegate ResultCallback) {}
