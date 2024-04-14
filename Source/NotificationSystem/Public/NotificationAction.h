// Copyright 2024 Spyridon Zervos
#pragma once

#include "CoreMinimal.h"
#include "NotificationActionContext.h"
#include "UObject/Object.h"
#include "NotificationAction.generated.h"

/**
 * Action that a notification can have. The action itself has a NotificationActionContext, text and an equality
 * operator is provided for implementation purposes.
 */
USTRUCT(BlueprintType)
struct FNotificationAction
{
	GENERATED_BODY()

	/** The context that this notification action represents. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ENotificationActionContext> Context = ENotificationActionContext::Default;

	/** Text that will be displayed in the button related to this action. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ActionText{};

	bool operator==(const FNotificationAction& Other) const
	{
		return Context == Other.Context && ActionText.EqualTo(Other.ActionText);
	}
};
