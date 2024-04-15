// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "DisplayNotificationAsyncActions.generated.h"

enum ENotificationActionContext : uint8;
class UNotificationDescriptor;

/** */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotificationActionDelegateMC, ENotificationActionContext, Action);

/**
 * Actions for quality of life. The actions are static and can be called from  blueprints to automatically show the requested notification. 
 * There are currently four functions that also describe the type of notification that will be displayed.
 */
UCLASS()
class NOTIFICATIONSYSTEM_API UDisplayNotificationAsyncActions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:

	/** To be deleted. */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncActions* ShowNotification(UObject* InWorldContextObject, const FText InTitle, const FText InBody);

	/** 
 	 * Displays a notification that acts as an acknowledgement to the player with a singular button. Has title, body and a single button with 
	 * hardcoded "OK" text. Calls ShowNotificationSingle 
  	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncActions* ShowNotificationAcknowledgement(UObject* InWorldContextObject, FText InTitle, FText InBody);

	/** Displays a notification with a singular button.  Has title, body and a single button with programmer-defined text. */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncActions* ShowNotificationSingle(UObject* InWorldContextObject, FText InTitle, FText InBody, FText InActionText);

	/** 
 	 * Displays a notification with dual buttons. Has title, body and a dual buttons both of which with programmer-defined text. The first (left) 
   	 * button will be of ENotificationActionContext::Accepted and the second (right) of ENotificationActionContext::Cancelled. */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncActions* ShowNotificationDual(UObject* InWorldContextObject, FText InTitle, FText InBody, FText InActionLeftText, FText InActionRightText);
	
	virtual void Activate() override;
	
	UPROPERTY(BlueprintAssignable)
	FNotificationActionDelegateMC OnResult;

private:
	
	void HandleConfirmationResult(ENotificationActionContext NotificationResult);

	UPROPERTY(Transient)
	TObjectPtr<UObject> WorldContextObject;

	UPROPERTY(Transient)
	TObjectPtr<ULocalPlayer> TargetLocalPlayer;

	UPROPERTY(Transient)
	TObjectPtr<UNotificationDescriptor> Descriptor;
	
};
