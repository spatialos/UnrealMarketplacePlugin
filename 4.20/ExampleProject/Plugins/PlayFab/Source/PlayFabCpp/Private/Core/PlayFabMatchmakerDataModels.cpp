//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "Core/PlayFabMatchmakerDataModels.h"
#include "Core/PlayFabJsonHelpers.h"

using namespace PlayFab;
using namespace PlayFab::MatchmakerModels;

PlayFab::MatchmakerModels::FAuthUserRequest::~FAuthUserRequest()
{

}

void PlayFab::MatchmakerModels::FAuthUserRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("AuthorizationTicket")); writer->WriteValue(AuthorizationTicket);

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FAuthUserRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> AuthorizationTicketValue = obj->TryGetField(TEXT("AuthorizationTicket"));
    if (AuthorizationTicketValue.IsValid() && !AuthorizationTicketValue->IsNull())
    {
        FString TmpValue;
        if (AuthorizationTicketValue->TryGetString(TmpValue)) { AuthorizationTicket = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FAuthUserResponse::~FAuthUserResponse()
{

}

void PlayFab::MatchmakerModels::FAuthUserResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("Authorized")); writer->WriteValue(Authorized);

    if (PlayFabId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("PlayFabId")); writer->WriteValue(PlayFabId); }

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FAuthUserResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> AuthorizedValue = obj->TryGetField(TEXT("Authorized"));
    if (AuthorizedValue.IsValid() && !AuthorizedValue->IsNull())
    {
        bool TmpValue;
        if (AuthorizedValue->TryGetBool(TmpValue)) { Authorized = TmpValue; }
    }

    const TSharedPtr<FJsonValue> PlayFabIdValue = obj->TryGetField(TEXT("PlayFabId"));
    if (PlayFabIdValue.IsValid() && !PlayFabIdValue->IsNull())
    {
        FString TmpValue;
        if (PlayFabIdValue->TryGetString(TmpValue)) { PlayFabId = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FItemInstance::~FItemInstance()
{

}

void PlayFab::MatchmakerModels::FItemInstance::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Annotation.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Annotation")); writer->WriteValue(Annotation); }

    if (BundleContents.Num() != 0)
    {
        writer->WriteArrayStart(TEXT("BundleContents"));
        for (const FString& item : BundleContents)
            writer->WriteValue(item);
        writer->WriteArrayEnd();
    }


    if (BundleParent.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("BundleParent")); writer->WriteValue(BundleParent); }

    if (CatalogVersion.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("CatalogVersion")); writer->WriteValue(CatalogVersion); }

    if (CustomData.Num() != 0)
    {
        writer->WriteObjectStart(TEXT("CustomData"));
        for (TMap<FString, FString>::TConstIterator It(CustomData); It; ++It)
        {
            writer->WriteIdentifierPrefix((*It).Key);
            writer->WriteValue((*It).Value);
        }
        writer->WriteObjectEnd();
    }

    if (DisplayName.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("DisplayName")); writer->WriteValue(DisplayName); }

    if (Expiration.notNull()) { writer->WriteIdentifierPrefix(TEXT("Expiration")); writeDatetime(Expiration, writer); }

    if (ItemClass.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("ItemClass")); writer->WriteValue(ItemClass); }

    if (ItemId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("ItemId")); writer->WriteValue(ItemId); }

    if (ItemInstanceId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("ItemInstanceId")); writer->WriteValue(ItemInstanceId); }

    if (PurchaseDate.notNull()) { writer->WriteIdentifierPrefix(TEXT("PurchaseDate")); writeDatetime(PurchaseDate, writer); }

    if (RemainingUses.notNull()) { writer->WriteIdentifierPrefix(TEXT("RemainingUses")); writer->WriteValue(RemainingUses); }

    if (UnitCurrency.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("UnitCurrency")); writer->WriteValue(UnitCurrency); }

    writer->WriteIdentifierPrefix(TEXT("UnitPrice")); writer->WriteValue(static_cast<int64>(UnitPrice));

    if (UsesIncrementedBy.notNull()) { writer->WriteIdentifierPrefix(TEXT("UsesIncrementedBy")); writer->WriteValue(UsesIncrementedBy); }

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FItemInstance::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> AnnotationValue = obj->TryGetField(TEXT("Annotation"));
    if (AnnotationValue.IsValid() && !AnnotationValue->IsNull())
    {
        FString TmpValue;
        if (AnnotationValue->TryGetString(TmpValue)) { Annotation = TmpValue; }
    }

    obj->TryGetStringArrayField(TEXT("BundleContents"), BundleContents);

    const TSharedPtr<FJsonValue> BundleParentValue = obj->TryGetField(TEXT("BundleParent"));
    if (BundleParentValue.IsValid() && !BundleParentValue->IsNull())
    {
        FString TmpValue;
        if (BundleParentValue->TryGetString(TmpValue)) { BundleParent = TmpValue; }
    }

    const TSharedPtr<FJsonValue> CatalogVersionValue = obj->TryGetField(TEXT("CatalogVersion"));
    if (CatalogVersionValue.IsValid() && !CatalogVersionValue->IsNull())
    {
        FString TmpValue;
        if (CatalogVersionValue->TryGetString(TmpValue)) { CatalogVersion = TmpValue; }
    }

    const TSharedPtr<FJsonObject>* CustomDataObject;
    if (obj->TryGetObjectField(TEXT("CustomData"), CustomDataObject))
    {
        for (TMap<FString, TSharedPtr<FJsonValue>>::TConstIterator It((*CustomDataObject)->Values); It; ++It)
        {
            CustomData.Add(It.Key(), It.Value()->AsString());
        }
    }

    const TSharedPtr<FJsonValue> DisplayNameValue = obj->TryGetField(TEXT("DisplayName"));
    if (DisplayNameValue.IsValid() && !DisplayNameValue->IsNull())
    {
        FString TmpValue;
        if (DisplayNameValue->TryGetString(TmpValue)) { DisplayName = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ExpirationValue = obj->TryGetField(TEXT("Expiration"));
    if (ExpirationValue.IsValid())
        Expiration = readDatetime(ExpirationValue);


    const TSharedPtr<FJsonValue> ItemClassValue = obj->TryGetField(TEXT("ItemClass"));
    if (ItemClassValue.IsValid() && !ItemClassValue->IsNull())
    {
        FString TmpValue;
        if (ItemClassValue->TryGetString(TmpValue)) { ItemClass = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ItemIdValue = obj->TryGetField(TEXT("ItemId"));
    if (ItemIdValue.IsValid() && !ItemIdValue->IsNull())
    {
        FString TmpValue;
        if (ItemIdValue->TryGetString(TmpValue)) { ItemId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ItemInstanceIdValue = obj->TryGetField(TEXT("ItemInstanceId"));
    if (ItemInstanceIdValue.IsValid() && !ItemInstanceIdValue->IsNull())
    {
        FString TmpValue;
        if (ItemInstanceIdValue->TryGetString(TmpValue)) { ItemInstanceId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> PurchaseDateValue = obj->TryGetField(TEXT("PurchaseDate"));
    if (PurchaseDateValue.IsValid())
        PurchaseDate = readDatetime(PurchaseDateValue);


    const TSharedPtr<FJsonValue> RemainingUsesValue = obj->TryGetField(TEXT("RemainingUses"));
    if (RemainingUsesValue.IsValid() && !RemainingUsesValue->IsNull())
    {
        int32 TmpValue;
        if (RemainingUsesValue->TryGetNumber(TmpValue)) { RemainingUses = TmpValue; }
    }

    const TSharedPtr<FJsonValue> UnitCurrencyValue = obj->TryGetField(TEXT("UnitCurrency"));
    if (UnitCurrencyValue.IsValid() && !UnitCurrencyValue->IsNull())
    {
        FString TmpValue;
        if (UnitCurrencyValue->TryGetString(TmpValue)) { UnitCurrency = TmpValue; }
    }

    const TSharedPtr<FJsonValue> UnitPriceValue = obj->TryGetField(TEXT("UnitPrice"));
    if (UnitPriceValue.IsValid() && !UnitPriceValue->IsNull())
    {
        uint32 TmpValue;
        if (UnitPriceValue->TryGetNumber(TmpValue)) { UnitPrice = TmpValue; }
    }

    const TSharedPtr<FJsonValue> UsesIncrementedByValue = obj->TryGetField(TEXT("UsesIncrementedBy"));
    if (UsesIncrementedByValue.IsValid() && !UsesIncrementedByValue->IsNull())
    {
        int32 TmpValue;
        if (UsesIncrementedByValue->TryGetNumber(TmpValue)) { UsesIncrementedBy = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FPlayerJoinedRequest::~FPlayerJoinedRequest()
{

}

void PlayFab::MatchmakerModels::FPlayerJoinedRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("LobbyId")); writer->WriteValue(LobbyId);

    writer->WriteIdentifierPrefix(TEXT("PlayFabId")); writer->WriteValue(PlayFabId);

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FPlayerJoinedRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> LobbyIdValue = obj->TryGetField(TEXT("LobbyId"));
    if (LobbyIdValue.IsValid() && !LobbyIdValue->IsNull())
    {
        FString TmpValue;
        if (LobbyIdValue->TryGetString(TmpValue)) { LobbyId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> PlayFabIdValue = obj->TryGetField(TEXT("PlayFabId"));
    if (PlayFabIdValue.IsValid() && !PlayFabIdValue->IsNull())
    {
        FString TmpValue;
        if (PlayFabIdValue->TryGetString(TmpValue)) { PlayFabId = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FPlayerJoinedResponse::~FPlayerJoinedResponse()
{

}

void PlayFab::MatchmakerModels::FPlayerJoinedResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FPlayerJoinedResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FPlayerLeftRequest::~FPlayerLeftRequest()
{

}

void PlayFab::MatchmakerModels::FPlayerLeftRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("LobbyId")); writer->WriteValue(LobbyId);

    writer->WriteIdentifierPrefix(TEXT("PlayFabId")); writer->WriteValue(PlayFabId);

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FPlayerLeftRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> LobbyIdValue = obj->TryGetField(TEXT("LobbyId"));
    if (LobbyIdValue.IsValid() && !LobbyIdValue->IsNull())
    {
        FString TmpValue;
        if (LobbyIdValue->TryGetString(TmpValue)) { LobbyId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> PlayFabIdValue = obj->TryGetField(TEXT("PlayFabId"));
    if (PlayFabIdValue.IsValid() && !PlayFabIdValue->IsNull())
    {
        FString TmpValue;
        if (PlayFabIdValue->TryGetString(TmpValue)) { PlayFabId = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FPlayerLeftResponse::~FPlayerLeftResponse()
{

}

void PlayFab::MatchmakerModels::FPlayerLeftResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FPlayerLeftResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    return HasSucceeded;
}

void PlayFab::MatchmakerModels::writeRegionEnumJSON(Region enumVal, JsonWriter& writer)
{
    switch (enumVal)
    {

    case RegionUSCentral: writer->WriteValue(TEXT("USCentral")); break;
    case RegionUSEast: writer->WriteValue(TEXT("USEast")); break;
    case RegionEUWest: writer->WriteValue(TEXT("EUWest")); break;
    case RegionSingapore: writer->WriteValue(TEXT("Singapore")); break;
    case RegionJapan: writer->WriteValue(TEXT("Japan")); break;
    case RegionBrazil: writer->WriteValue(TEXT("Brazil")); break;
    case RegionAustralia: writer->WriteValue(TEXT("Australia")); break;
    }
}

MatchmakerModels::Region PlayFab::MatchmakerModels::readRegionFromValue(const TSharedPtr<FJsonValue>& value)
{
    return readRegionFromValue(value.IsValid() ? value->AsString() : "");
}

MatchmakerModels::Region PlayFab::MatchmakerModels::readRegionFromValue(const FString& value)
{
    static TMap<FString, Region> _RegionMap;
    if (_RegionMap.Num() == 0)
    {
        // Auto-generate the map on the first use
        _RegionMap.Add(TEXT("USCentral"), RegionUSCentral);
        _RegionMap.Add(TEXT("USEast"), RegionUSEast);
        _RegionMap.Add(TEXT("EUWest"), RegionEUWest);
        _RegionMap.Add(TEXT("Singapore"), RegionSingapore);
        _RegionMap.Add(TEXT("Japan"), RegionJapan);
        _RegionMap.Add(TEXT("Brazil"), RegionBrazil);
        _RegionMap.Add(TEXT("Australia"), RegionAustralia);

    }

    if (!value.IsEmpty())
    {
        auto output = _RegionMap.Find(value);
        if (output != nullptr)
            return *output;
    }

    return RegionUSCentral; // Basically critical fail
}

PlayFab::MatchmakerModels::FStartGameRequest::~FStartGameRequest()
{

}

void PlayFab::MatchmakerModels::FStartGameRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("Build")); writer->WriteValue(Build);

    if (CustomCommandLineData.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("CustomCommandLineData")); writer->WriteValue(CustomCommandLineData); }

    writer->WriteIdentifierPrefix(TEXT("ExternalMatchmakerEventEndpoint")); writer->WriteValue(ExternalMatchmakerEventEndpoint);

    writer->WriteIdentifierPrefix(TEXT("GameMode")); writer->WriteValue(GameMode);

    writer->WriteIdentifierPrefix(TEXT("Region")); writeRegionEnumJSON(pfRegion, writer);

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FStartGameRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> BuildValue = obj->TryGetField(TEXT("Build"));
    if (BuildValue.IsValid() && !BuildValue->IsNull())
    {
        FString TmpValue;
        if (BuildValue->TryGetString(TmpValue)) { Build = TmpValue; }
    }

    const TSharedPtr<FJsonValue> CustomCommandLineDataValue = obj->TryGetField(TEXT("CustomCommandLineData"));
    if (CustomCommandLineDataValue.IsValid() && !CustomCommandLineDataValue->IsNull())
    {
        FString TmpValue;
        if (CustomCommandLineDataValue->TryGetString(TmpValue)) { CustomCommandLineData = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ExternalMatchmakerEventEndpointValue = obj->TryGetField(TEXT("ExternalMatchmakerEventEndpoint"));
    if (ExternalMatchmakerEventEndpointValue.IsValid() && !ExternalMatchmakerEventEndpointValue->IsNull())
    {
        FString TmpValue;
        if (ExternalMatchmakerEventEndpointValue->TryGetString(TmpValue)) { ExternalMatchmakerEventEndpoint = TmpValue; }
    }

    const TSharedPtr<FJsonValue> GameModeValue = obj->TryGetField(TEXT("GameMode"));
    if (GameModeValue.IsValid() && !GameModeValue->IsNull())
    {
        FString TmpValue;
        if (GameModeValue->TryGetString(TmpValue)) { GameMode = TmpValue; }
    }

    pfRegion = readRegionFromValue(obj->TryGetField(TEXT("Region")));

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FStartGameResponse::~FStartGameResponse()
{

}

void PlayFab::MatchmakerModels::FStartGameResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (GameID.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("GameID")); writer->WriteValue(GameID); }

    if (ServerHostname.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("ServerHostname")); writer->WriteValue(ServerHostname); }

    if (ServerIPV4Address.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("ServerIPV4Address")); writer->WriteValue(ServerIPV4Address); }

    if (ServerIPV6Address.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("ServerIPV6Address")); writer->WriteValue(ServerIPV6Address); }

    writer->WriteIdentifierPrefix(TEXT("ServerPort")); writer->WriteValue(static_cast<int64>(ServerPort));

    if (ServerPublicDNSName.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("ServerPublicDNSName")); writer->WriteValue(ServerPublicDNSName); }

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FStartGameResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> GameIDValue = obj->TryGetField(TEXT("GameID"));
    if (GameIDValue.IsValid() && !GameIDValue->IsNull())
    {
        FString TmpValue;
        if (GameIDValue->TryGetString(TmpValue)) { GameID = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ServerHostnameValue = obj->TryGetField(TEXT("ServerHostname"));
    if (ServerHostnameValue.IsValid() && !ServerHostnameValue->IsNull())
    {
        FString TmpValue;
        if (ServerHostnameValue->TryGetString(TmpValue)) { ServerHostname = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ServerIPV4AddressValue = obj->TryGetField(TEXT("ServerIPV4Address"));
    if (ServerIPV4AddressValue.IsValid() && !ServerIPV4AddressValue->IsNull())
    {
        FString TmpValue;
        if (ServerIPV4AddressValue->TryGetString(TmpValue)) { ServerIPV4Address = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ServerIPV6AddressValue = obj->TryGetField(TEXT("ServerIPV6Address"));
    if (ServerIPV6AddressValue.IsValid() && !ServerIPV6AddressValue->IsNull())
    {
        FString TmpValue;
        if (ServerIPV6AddressValue->TryGetString(TmpValue)) { ServerIPV6Address = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ServerPortValue = obj->TryGetField(TEXT("ServerPort"));
    if (ServerPortValue.IsValid() && !ServerPortValue->IsNull())
    {
        uint32 TmpValue;
        if (ServerPortValue->TryGetNumber(TmpValue)) { ServerPort = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ServerPublicDNSNameValue = obj->TryGetField(TEXT("ServerPublicDNSName"));
    if (ServerPublicDNSNameValue.IsValid() && !ServerPublicDNSNameValue->IsNull())
    {
        FString TmpValue;
        if (ServerPublicDNSNameValue->TryGetString(TmpValue)) { ServerPublicDNSName = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FUserInfoRequest::~FUserInfoRequest()
{

}

void PlayFab::MatchmakerModels::FUserInfoRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("MinCatalogVersion")); writer->WriteValue(MinCatalogVersion);

    writer->WriteIdentifierPrefix(TEXT("PlayFabId")); writer->WriteValue(PlayFabId);

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FUserInfoRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> MinCatalogVersionValue = obj->TryGetField(TEXT("MinCatalogVersion"));
    if (MinCatalogVersionValue.IsValid() && !MinCatalogVersionValue->IsNull())
    {
        int32 TmpValue;
        if (MinCatalogVersionValue->TryGetNumber(TmpValue)) { MinCatalogVersion = TmpValue; }
    }

    const TSharedPtr<FJsonValue> PlayFabIdValue = obj->TryGetField(TEXT("PlayFabId"));
    if (PlayFabIdValue.IsValid() && !PlayFabIdValue->IsNull())
    {
        FString TmpValue;
        if (PlayFabIdValue->TryGetString(TmpValue)) { PlayFabId = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FVirtualCurrencyRechargeTime::~FVirtualCurrencyRechargeTime()
{

}

void PlayFab::MatchmakerModels::FVirtualCurrencyRechargeTime::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("RechargeMax")); writer->WriteValue(RechargeMax);

    writer->WriteIdentifierPrefix(TEXT("RechargeTime")); writeDatetime(RechargeTime, writer);

    writer->WriteIdentifierPrefix(TEXT("SecondsToRecharge")); writer->WriteValue(SecondsToRecharge);

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FVirtualCurrencyRechargeTime::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> RechargeMaxValue = obj->TryGetField(TEXT("RechargeMax"));
    if (RechargeMaxValue.IsValid() && !RechargeMaxValue->IsNull())
    {
        int32 TmpValue;
        if (RechargeMaxValue->TryGetNumber(TmpValue)) { RechargeMax = TmpValue; }
    }

    const TSharedPtr<FJsonValue> RechargeTimeValue = obj->TryGetField(TEXT("RechargeTime"));
    if (RechargeTimeValue.IsValid())
        RechargeTime = readDatetime(RechargeTimeValue);


    const TSharedPtr<FJsonValue> SecondsToRechargeValue = obj->TryGetField(TEXT("SecondsToRecharge"));
    if (SecondsToRechargeValue.IsValid() && !SecondsToRechargeValue->IsNull())
    {
        int32 TmpValue;
        if (SecondsToRechargeValue->TryGetNumber(TmpValue)) { SecondsToRecharge = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::MatchmakerModels::FUserInfoResponse::~FUserInfoResponse()
{

}

void PlayFab::MatchmakerModels::FUserInfoResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Inventory.Num() != 0)
    {
        writer->WriteArrayStart(TEXT("Inventory"));
        for (const FItemInstance& item : Inventory)
            item.writeJSON(writer);
        writer->WriteArrayEnd();
    }


    writer->WriteIdentifierPrefix(TEXT("IsDeveloper")); writer->WriteValue(IsDeveloper);

    if (PlayFabId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("PlayFabId")); writer->WriteValue(PlayFabId); }

    if (SteamId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("SteamId")); writer->WriteValue(SteamId); }

    if (TitleDisplayName.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("TitleDisplayName")); writer->WriteValue(TitleDisplayName); }

    if (Username.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Username")); writer->WriteValue(Username); }

    if (VirtualCurrency.Num() != 0)
    {
        writer->WriteObjectStart(TEXT("VirtualCurrency"));
        for (TMap<FString, int32>::TConstIterator It(VirtualCurrency); It; ++It)
        {
            writer->WriteIdentifierPrefix((*It).Key);
            writer->WriteValue((*It).Value);
        }
        writer->WriteObjectEnd();
    }

    if (VirtualCurrencyRechargeTimes.Num() != 0)
    {
        writer->WriteObjectStart(TEXT("VirtualCurrencyRechargeTimes"));
        for (TMap<FString, FVirtualCurrencyRechargeTime>::TConstIterator It(VirtualCurrencyRechargeTimes); It; ++It)
        {
            writer->WriteIdentifierPrefix((*It).Key);
            (*It).Value.writeJSON(writer);
        }
        writer->WriteObjectEnd();
    }

    writer->WriteObjectEnd();
}

bool PlayFab::MatchmakerModels::FUserInfoResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TArray<TSharedPtr<FJsonValue>>&InventoryArray = FPlayFabJsonHelpers::ReadArray(obj, TEXT("Inventory"));
    for (int32 Idx = 0; Idx < InventoryArray.Num(); Idx++)
    {
        TSharedPtr<FJsonValue> CurrentItem = InventoryArray[Idx];
        Inventory.Add(FItemInstance(CurrentItem->AsObject()));
    }


    const TSharedPtr<FJsonValue> IsDeveloperValue = obj->TryGetField(TEXT("IsDeveloper"));
    if (IsDeveloperValue.IsValid() && !IsDeveloperValue->IsNull())
    {
        bool TmpValue;
        if (IsDeveloperValue->TryGetBool(TmpValue)) { IsDeveloper = TmpValue; }
    }

    const TSharedPtr<FJsonValue> PlayFabIdValue = obj->TryGetField(TEXT("PlayFabId"));
    if (PlayFabIdValue.IsValid() && !PlayFabIdValue->IsNull())
    {
        FString TmpValue;
        if (PlayFabIdValue->TryGetString(TmpValue)) { PlayFabId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> SteamIdValue = obj->TryGetField(TEXT("SteamId"));
    if (SteamIdValue.IsValid() && !SteamIdValue->IsNull())
    {
        FString TmpValue;
        if (SteamIdValue->TryGetString(TmpValue)) { SteamId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TitleDisplayNameValue = obj->TryGetField(TEXT("TitleDisplayName"));
    if (TitleDisplayNameValue.IsValid() && !TitleDisplayNameValue->IsNull())
    {
        FString TmpValue;
        if (TitleDisplayNameValue->TryGetString(TmpValue)) { TitleDisplayName = TmpValue; }
    }

    const TSharedPtr<FJsonValue> UsernameValue = obj->TryGetField(TEXT("Username"));
    if (UsernameValue.IsValid() && !UsernameValue->IsNull())
    {
        FString TmpValue;
        if (UsernameValue->TryGetString(TmpValue)) { Username = TmpValue; }
    }

    const TSharedPtr<FJsonObject>* VirtualCurrencyObject;
    if (obj->TryGetObjectField(TEXT("VirtualCurrency"), VirtualCurrencyObject))
    {
        for (TMap<FString, TSharedPtr<FJsonValue>>::TConstIterator It((*VirtualCurrencyObject)->Values); It; ++It)
        {
            int32 TmpValue; It.Value()->TryGetNumber(TmpValue);
            VirtualCurrency.Add(It.Key(), TmpValue);
        }
    }

    const TSharedPtr<FJsonObject>* VirtualCurrencyRechargeTimesObject;
    if (obj->TryGetObjectField(TEXT("VirtualCurrencyRechargeTimes"), VirtualCurrencyRechargeTimesObject))
    {
        for (TMap<FString, TSharedPtr<FJsonValue>>::TConstIterator It((*VirtualCurrencyRechargeTimesObject)->Values); It; ++It)
        {
            VirtualCurrencyRechargeTimes.Add(It.Key(), FVirtualCurrencyRechargeTime(It.Value()->AsObject()));
        }
    }

    return HasSucceeded;
}

