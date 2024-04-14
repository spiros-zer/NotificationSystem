// Copyright 2024 Spyridon Zervos

#pragma once

#include "NotificationActionContext.generated.h"

/**
 * The context of the notification's action the player interacted with.
 */
UENUM(BlueprintType)
enum ENotificationActionContext : uint8
{
    Accepted	UMETA(DisplayName="Accepted",	ToolTip="The player has accepted the notification's effect."),
	Declined	UMETA(DisplayName="Declined",	ToolTip="The player has declined the notification's context."),
	Cancelled	UMETA(DisplayName="Cancelled",	ToolTip="The player has cancelled interaction with the notification."),
	Killed		UMETA(DisplayName="Killed",		ToolTip="The notification has been killed. It is not equal to cancelled!"),
	Default		UMETA(DisplayName="Default",	ToolTip="",		Hidden)
};
