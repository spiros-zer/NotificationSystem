# Notification System Plugin

## Table of Contents

## Core Overview
The notification system plugin offers a straight-forward way to display notifications to the player. It uses the **CommonUI plugin** for the notification widget.

### Notification Action Context
`NotificationActionContext.h` provides an enum that describes the context of the notification's action the player interacted with.

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
Actions are also provided through subclassing `UBlueprintAsyncActionBase` for quality of life.

### DisplayNotificationAsyncActions


Copyright 2024 Spyridon Zervos