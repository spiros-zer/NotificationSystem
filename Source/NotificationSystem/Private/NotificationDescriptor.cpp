// Copyright 2024 Spyridon Zervos


#include "NotificationDescriptor.h"

UNotificationDescriptor* UNotificationDescriptor::CreateNotificationSingle(const FText& InTitle, const FText& InBody,
	const FText& InActionText)
{
	UNotificationDescriptor* NotificationType = NewObject<UNotificationDescriptor>();
	NotificationType->Title = InTitle;
	NotificationType->Body = InBody;

	FNotificationAction NotificationAction;
	NotificationAction.Context = ENotificationActionContext::Accepted;
	NotificationAction.ActionText = InActionText;
	NotificationType->ButtonsActions.Add(NotificationAction);

	return NotificationType;
}

UNotificationDescriptor* UNotificationDescriptor::CreateNotificationDouble(const FText& InTitle, const FText& InBody,
	const FText& InActionText_L, const FText& InActionText_R)
{
	UNotificationDescriptor* NotificationType = NewObject<UNotificationDescriptor>();
	NotificationType->Title = InTitle;
	NotificationType->Body = InBody;

	FNotificationAction NotificationAction_L;
	NotificationAction_L.Context = ENotificationActionContext::Accepted;
	NotificationAction_L.ActionText = InActionText_L;
	NotificationType->ButtonsActions.Add(NotificationAction_L);

	FNotificationAction NotificationAction_R;
	NotificationAction_R.Context = ENotificationActionContext::Cancelled;
	NotificationAction_R.ActionText = InActionText_R;
	NotificationType->ButtonsActions.Add(NotificationAction_R);

	return NotificationType;
}
