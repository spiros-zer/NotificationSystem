// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "NotificationAction.h"
#include "UObject/Object.h"
#include "NotificationDescriptor.generated.h"

/**
 * A notification descriptor, as the name denotes, describes a notification in the means of containing its title,
 * body and FNotificationAction (s) it will have.
 */
UCLASS()
class NOTIFICATIONSYSTEM_API UNotificationDescriptor : public UObject
{
	GENERATED_BODY()

public:

	/** Creates descriptor for notification with a single action with accept context. */
	static UNotificationDescriptor* CreateNotificationSingle(const FText& InTitle, const FText& InBody,
		const FText& InActionText);

	/** Creates descriptor for notification with dual actions with accept and cancelled context. */
	static UNotificationDescriptor* CreateNotificationDouble(const FText& InTitle, const FText& InBody,
		const FText& InActionText_L, const FText& InActionText_R);

	/** The title of the notification. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;
	
	/** The body of the notification. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Body;

	/** The button(s) action(s) of the notification. Depending on the type of the action there can be multiple. */
	UPROPERTY(BlueprintReadWrite)
	TArray<FNotificationAction> ButtonsActions;
};
