// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "NotificationSystem.h"
#include "NotificationWidget.generated.h"

class UNotificationDescriptor;

/**
 * The notification itself. 
 */
UCLASS()
class NOTIFICATIONSYSTEM_API UNotificationWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:

	/**
	 * Sets up the notification based on the input NotificationDescriptor and decides when the ResultCallback
	 * will be fired.
	 */
	virtual void SetupNotification(UNotificationDescriptor* NotificationDescriptor,
	                               FNotificationActionDelegate ResultCallback);

	virtual void KillNotification();
};

inline void UNotificationWidget::SetupNotification(UNotificationDescriptor* NotificationDescriptor,
								   FNotificationActionDelegate ResultCallback)
{}

inline void UNotificationWidget::KillNotification() {}
