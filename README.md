# Notification System Plugin
The notification system plugin offers a straight-forward way to display notifications to the player. It uses the **CommonUI plugin** for the notification widget, so in order for the plugin to work as expected the CommonUI is necessary.

<!-- TOC -->

## Core Overview
The order with which the modules are laid out below is very important as they are built on top of each other. Do not move to the next one if you have not fully understand the one before. The code has been extensively commented and is advised to check the corresponding part while going through the modules.

### Notification Action Context
`NotificationActionContext.h` provides an enum that describes the context of the notification's action the player interacted with.
>Out-of-box supported contexts are `Accept, Declined, Cancelled, Killed and Default`.

### NotificationAction
`NotificationAction.h` provides a struct that describes the action that a notification can have. The action itself has a [Notification Action Context](#notification-action-context), text and an equality operator is provided for implementation purposes.

### NotificationDescriptor
`NotificationDescriptor.h` provides a UObject that, as the name denotes, describes a notification in the means of containing its title, body and [Notification Action](#notificationaction) (s) it will have.

### NotificationWidget
`NotificationWidget.h` is the notification itself. It is expected that this class will be inherited and that the `SetupNotification(UNotificationDescriptor*,
FNotificationActionDelegate)` will be overwritten since it sets up the notification based on the input NotificationDescriptor and decides when the ResultCallback will be fired.

### NotificationSystem
`NotificationSystem.h` is the core of the notification system plugin. Responsible for (de)initialization and displaying the notifications. Must be subclassed in order to work properly with the corresponding game's UI pipeline.

>The base class is `UCLASS(Abstract)` and won't be automatically initialized as other LocalPlayerSubsystems. This is because its functionality is incomplete as it expects the programmer to subclass it and override the function `ShowNotification(UNotificationType*, FNotificationActionDelegate)`. That function is the manager/middle man of displaying the notification of type NotificationType and hooking it up to the callback to be triggered.

## Actions Overview
Actions - subclass of `UBlueprintAsyncActionBase` - are also provided for quality of life. The actions are static and can be called from blueprints to automatically show the requested notification. There are currently four functions that also describe the type of notification that will be displayed.

### DisplayNotificationAsyncActions
`DisplayNotificationAsyncActions.h` provides the functions that create the corresponding notification. It can be subclassed and expanded by the programmer with whatever notification type seems appropriate.

- `UDisplayNotificationAsyncActions::ShowNotificationAcknowledgement` displays a notification that acts as an acknowledgement to the player. Has title, body and a single button with hardcoded "OK" text.
- `UDisplayNotificationAsyncActions::ShowNotificationSingle` displays a notification with a singular button.  Has title, body and a single button with programmer-defined text.
- `UDisplayNotificationAsyncActions::ShowNotificationDual` displays a notification with dual buttons. Has title, body and a dual buttons both of which with programmer-defined text.
> The first (left) button will be of `ENotificationActionContext::Accepted` and the second (right) of `ENotificationActionContext::Cancelled`.

Copyright 2024 Spyridon Zervos
