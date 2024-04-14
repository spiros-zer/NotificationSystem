// Copyright 2024 Spyridon Zervos


#include "AsyncActions/DisplayNotificationAsyncActions.h"

#include "NotificationDescriptor.h"
#include "NotificationSystem.h"
#include "Blueprint/UserWidget.h"

UDisplayNotificationAsyncActions* UDisplayNotificationAsyncActions::ShowNotification(UObject* InWorldContextObject,
                                                                                     const FText InTitle,
                                                                                     const FText InBody)
{
	UDisplayNotificationAsyncActions* Action = NewObject<UDisplayNotificationAsyncActions>();
	Action->WorldContextObject = InWorldContextObject;
	Action->Descriptor = UNotificationDescriptor::CreateNotificationSingle(InTitle, InBody, FText::FromString("Ok"));
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

UDisplayNotificationAsyncActions* UDisplayNotificationAsyncActions::ShowNotificationAcknowledgement(
	UObject* InWorldContextObject, FText InTitle, FText InBody)
{
	UDisplayNotificationAsyncActions* Action = NewObject<UDisplayNotificationAsyncActions>();
	Action->WorldContextObject = InWorldContextObject;
	Action->Descriptor = UNotificationDescriptor::CreateNotificationSingle(InTitle, InBody, FText::FromString("Ok"));
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

UDisplayNotificationAsyncActions* UDisplayNotificationAsyncActions::ShowNotificationSingle(
	UObject* InWorldContextObject, FText InTitle, FText InBody, FText InActionText)
{
	UDisplayNotificationAsyncActions* Action = NewObject<UDisplayNotificationAsyncActions>();
	Action->WorldContextObject = InWorldContextObject;
	Action->Descriptor = UNotificationDescriptor::CreateNotificationSingle(InTitle, InBody, InActionText);
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

UDisplayNotificationAsyncActions* UDisplayNotificationAsyncActions::ShowNotificationDual(UObject* InWorldContextObject,
	FText InTitle, FText InBody, FText InActionLeftText, FText InActionRightText)
{
	UDisplayNotificationAsyncActions* Action = NewObject<UDisplayNotificationAsyncActions>();
	Action->WorldContextObject = InWorldContextObject;
	Action->Descriptor = UNotificationDescriptor::CreateNotificationDouble(InTitle, InBody, InActionLeftText, InActionRightText);
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

void UDisplayNotificationAsyncActions::Activate()
{
	Super::Activate();

	if (WorldContextObject && !TargetLocalPlayer)
	{
		if (const UUserWidget* UserWidget = Cast<UUserWidget>(WorldContextObject))
		{
			TargetLocalPlayer = UserWidget->GetOwningLocalPlayer<ULocalPlayer>();
		}
		else if (const APlayerController* PlayerController = Cast<APlayerController>(WorldContextObject))
		{
			TargetLocalPlayer = PlayerController->GetLocalPlayer();
		}
		else if (const UWorld* World = WorldContextObject->GetWorld())
		{
			if (const UGameInstance* GameInstance = World->GetGameInstance<UGameInstance>())
			{
				TargetLocalPlayer = GameInstance->GetPrimaryPlayerController(false)->GetLocalPlayer();
			}
		}
	}

	if (TargetLocalPlayer)
	{
		if (UNotificationSystem* Messaging = TargetLocalPlayer->GetSubsystem<UNotificationSystem>())
		{
			FNotificationActionDelegate ResultCallback = FNotificationActionDelegate::CreateUObject(this, &ThisClass::HandleConfirmationResult);
			Messaging->ShowNotification(Descriptor, ResultCallback);
			return;
		}
	}
	
	// If we couldn't make the confirmation, just handle an unknown result and broadcast nothing
	HandleConfirmationResult(ENotificationActionContext::Default);
}

void UDisplayNotificationAsyncActions::HandleConfirmationResult(ENotificationActionContext NotificationResult)
{
	OnResult.Broadcast(NotificationResult);

	SetReadyToDestroy();
}
