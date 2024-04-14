// Copyright 2024 Spyridon Zervos

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "DisplayNotificationAsyncActions.generated.h"

enum ENotificationActionContext : uint8;
class UNotificationDescriptor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotificationActionDelegateMC, ENotificationActionContext, Action);

/**
 * 
 */
UCLASS()
class NOTIFICATIONSYSTEM_API UDisplayNotificationAsyncActions : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncActions* ShowNotification(UObject* InWorldContextObject, const FText InTitle, const FText InBody);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncActions* ShowNotificationAcknowledgement(UObject* InWorldContextObject, FText InTitle, FText InBody);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UDisplayNotificationAsyncActions* ShowNotificationSingle(UObject* InWorldContextObject, FText InTitle, FText InBody, FText InActionText);
	
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
