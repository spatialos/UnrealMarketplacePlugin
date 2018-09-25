//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "Core/PlayFabCloudScriptDataModels.h"
#include "Core/PlayFabJsonHelpers.h"

using namespace PlayFab;
using namespace PlayFab::CloudScriptModels;

void PlayFab::CloudScriptModels::writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, JsonWriter& writer)
{
    switch (enumVal)
    {

    case CloudScriptRevisionOptionLive: writer->WriteValue(TEXT("Live")); break;
    case CloudScriptRevisionOptionLatest: writer->WriteValue(TEXT("Latest")); break;
    case CloudScriptRevisionOptionSpecific: writer->WriteValue(TEXT("Specific")); break;
    }
}

CloudScriptModels::CloudScriptRevisionOption PlayFab::CloudScriptModels::readCloudScriptRevisionOptionFromValue(const TSharedPtr<FJsonValue>& value)
{
    return readCloudScriptRevisionOptionFromValue(value.IsValid() ? value->AsString() : "");
}

CloudScriptModels::CloudScriptRevisionOption PlayFab::CloudScriptModels::readCloudScriptRevisionOptionFromValue(const FString& value)
{
    static TMap<FString, CloudScriptRevisionOption> _CloudScriptRevisionOptionMap;
    if (_CloudScriptRevisionOptionMap.Num() == 0)
    {
        // Auto-generate the map on the first use
        _CloudScriptRevisionOptionMap.Add(TEXT("Live"), CloudScriptRevisionOptionLive);
        _CloudScriptRevisionOptionMap.Add(TEXT("Latest"), CloudScriptRevisionOptionLatest);
        _CloudScriptRevisionOptionMap.Add(TEXT("Specific"), CloudScriptRevisionOptionSpecific);

    }

    if (!value.IsEmpty())
    {
        auto output = _CloudScriptRevisionOptionMap.Find(value);
        if (output != nullptr)
            return *output;
    }

    return CloudScriptRevisionOptionLive; // Basically critical fail
}

PlayFab::CloudScriptModels::FEntityKey::~FEntityKey()
{

}

void PlayFab::CloudScriptModels::FEntityKey::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("Id")); writer->WriteValue(Id);

    if (Type.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Type")); writer->WriteValue(Type); }

    writer->WriteObjectEnd();
}

bool PlayFab::CloudScriptModels::FEntityKey::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> IdValue = obj->TryGetField(TEXT("Id"));
    if (IdValue.IsValid() && !IdValue->IsNull())
    {
        FString TmpValue;
        if (IdValue->TryGetString(TmpValue)) { Id = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TypeValue = obj->TryGetField(TEXT("Type"));
    if (TypeValue.IsValid() && !TypeValue->IsNull())
    {
        FString TmpValue;
        if (TypeValue->TryGetString(TmpValue)) { Type = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::CloudScriptModels::FScriptExecutionError::~FScriptExecutionError()
{

}

void PlayFab::CloudScriptModels::FScriptExecutionError::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Error.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Error")); writer->WriteValue(Error); }

    if (Message.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Message")); writer->WriteValue(Message); }

    if (StackTrace.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("StackTrace")); writer->WriteValue(StackTrace); }

    writer->WriteObjectEnd();
}

bool PlayFab::CloudScriptModels::FScriptExecutionError::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> ErrorValue = obj->TryGetField(TEXT("Error"));
    if (ErrorValue.IsValid() && !ErrorValue->IsNull())
    {
        FString TmpValue;
        if (ErrorValue->TryGetString(TmpValue)) { Error = TmpValue; }
    }

    const TSharedPtr<FJsonValue> MessageValue = obj->TryGetField(TEXT("Message"));
    if (MessageValue.IsValid() && !MessageValue->IsNull())
    {
        FString TmpValue;
        if (MessageValue->TryGetString(TmpValue)) { Message = TmpValue; }
    }

    const TSharedPtr<FJsonValue> StackTraceValue = obj->TryGetField(TEXT("StackTrace"));
    if (StackTraceValue.IsValid() && !StackTraceValue->IsNull())
    {
        FString TmpValue;
        if (StackTraceValue->TryGetString(TmpValue)) { StackTrace = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::CloudScriptModels::FLogStatement::~FLogStatement()
{

}

void PlayFab::CloudScriptModels::FLogStatement::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Data.notNull()) { writer->WriteIdentifierPrefix(TEXT("Data")); Data.writeJSON(writer); }

    if (Level.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Level")); writer->WriteValue(Level); }

    if (Message.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("Message")); writer->WriteValue(Message); }

    writer->WriteObjectEnd();
}

bool PlayFab::CloudScriptModels::FLogStatement::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> DataValue = obj->TryGetField(TEXT("Data"));
    if (DataValue.IsValid() && !DataValue->IsNull())
    {
        Data = FJsonKeeper(DataValue);
    }

    const TSharedPtr<FJsonValue> LevelValue = obj->TryGetField(TEXT("Level"));
    if (LevelValue.IsValid() && !LevelValue->IsNull())
    {
        FString TmpValue;
        if (LevelValue->TryGetString(TmpValue)) { Level = TmpValue; }
    }

    const TSharedPtr<FJsonValue> MessageValue = obj->TryGetField(TEXT("Message"));
    if (MessageValue.IsValid() && !MessageValue->IsNull())
    {
        FString TmpValue;
        if (MessageValue->TryGetString(TmpValue)) { Message = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::CloudScriptModels::FExecuteCloudScriptResult::~FExecuteCloudScriptResult()
{
    //if (Error != nullptr) delete Error;

}

void PlayFab::CloudScriptModels::FExecuteCloudScriptResult::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteIdentifierPrefix(TEXT("APIRequestsIssued")); writer->WriteValue(APIRequestsIssued);

    if (Error.IsValid()) { writer->WriteIdentifierPrefix(TEXT("Error")); Error->writeJSON(writer); }

    writer->WriteIdentifierPrefix(TEXT("ExecutionTimeSeconds")); writer->WriteValue(ExecutionTimeSeconds);

    if (FunctionName.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("FunctionName")); writer->WriteValue(FunctionName); }

    if (FunctionResult.notNull()) { writer->WriteIdentifierPrefix(TEXT("FunctionResult")); FunctionResult.writeJSON(writer); }

    if (FunctionResultTooLarge.notNull()) { writer->WriteIdentifierPrefix(TEXT("FunctionResultTooLarge")); writer->WriteValue(FunctionResultTooLarge); }

    writer->WriteIdentifierPrefix(TEXT("HttpRequestsIssued")); writer->WriteValue(HttpRequestsIssued);

    if (Logs.Num() != 0)
    {
        writer->WriteArrayStart(TEXT("Logs"));
        for (const FLogStatement& item : Logs)
            item.writeJSON(writer);
        writer->WriteArrayEnd();
    }


    if (LogsTooLarge.notNull()) { writer->WriteIdentifierPrefix(TEXT("LogsTooLarge")); writer->WriteValue(LogsTooLarge); }

    writer->WriteIdentifierPrefix(TEXT("MemoryConsumedBytes")); writer->WriteValue(static_cast<int64>(MemoryConsumedBytes));

    writer->WriteIdentifierPrefix(TEXT("ProcessorTimeSeconds")); writer->WriteValue(ProcessorTimeSeconds);

    writer->WriteIdentifierPrefix(TEXT("Revision")); writer->WriteValue(Revision);

    writer->WriteObjectEnd();
}

bool PlayFab::CloudScriptModels::FExecuteCloudScriptResult::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> APIRequestsIssuedValue = obj->TryGetField(TEXT("APIRequestsIssued"));
    if (APIRequestsIssuedValue.IsValid() && !APIRequestsIssuedValue->IsNull())
    {
        int32 TmpValue;
        if (APIRequestsIssuedValue->TryGetNumber(TmpValue)) { APIRequestsIssued = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ErrorValue = obj->TryGetField(TEXT("Error"));
    if (ErrorValue.IsValid() && !ErrorValue->IsNull())
    {
        Error = MakeShareable(new FScriptExecutionError(ErrorValue->AsObject()));
    }

    const TSharedPtr<FJsonValue> ExecutionTimeSecondsValue = obj->TryGetField(TEXT("ExecutionTimeSeconds"));
    if (ExecutionTimeSecondsValue.IsValid() && !ExecutionTimeSecondsValue->IsNull())
    {
        double TmpValue;
        if (ExecutionTimeSecondsValue->TryGetNumber(TmpValue)) { ExecutionTimeSeconds = TmpValue; }
    }

    const TSharedPtr<FJsonValue> FunctionNameValue = obj->TryGetField(TEXT("FunctionName"));
    if (FunctionNameValue.IsValid() && !FunctionNameValue->IsNull())
    {
        FString TmpValue;
        if (FunctionNameValue->TryGetString(TmpValue)) { FunctionName = TmpValue; }
    }

    const TSharedPtr<FJsonValue> FunctionResultValue = obj->TryGetField(TEXT("FunctionResult"));
    if (FunctionResultValue.IsValid() && !FunctionResultValue->IsNull())
    {
        FunctionResult = FJsonKeeper(FunctionResultValue);
    }

    const TSharedPtr<FJsonValue> FunctionResultTooLargeValue = obj->TryGetField(TEXT("FunctionResultTooLarge"));
    if (FunctionResultTooLargeValue.IsValid() && !FunctionResultTooLargeValue->IsNull())
    {
        bool TmpValue;
        if (FunctionResultTooLargeValue->TryGetBool(TmpValue)) { FunctionResultTooLarge = TmpValue; }
    }

    const TSharedPtr<FJsonValue> HttpRequestsIssuedValue = obj->TryGetField(TEXT("HttpRequestsIssued"));
    if (HttpRequestsIssuedValue.IsValid() && !HttpRequestsIssuedValue->IsNull())
    {
        int32 TmpValue;
        if (HttpRequestsIssuedValue->TryGetNumber(TmpValue)) { HttpRequestsIssued = TmpValue; }
    }

    const TArray<TSharedPtr<FJsonValue>>&LogsArray = FPlayFabJsonHelpers::ReadArray(obj, TEXT("Logs"));
    for (int32 Idx = 0; Idx < LogsArray.Num(); Idx++)
    {
        TSharedPtr<FJsonValue> CurrentItem = LogsArray[Idx];
        Logs.Add(FLogStatement(CurrentItem->AsObject()));
    }


    const TSharedPtr<FJsonValue> LogsTooLargeValue = obj->TryGetField(TEXT("LogsTooLarge"));
    if (LogsTooLargeValue.IsValid() && !LogsTooLargeValue->IsNull())
    {
        bool TmpValue;
        if (LogsTooLargeValue->TryGetBool(TmpValue)) { LogsTooLarge = TmpValue; }
    }

    const TSharedPtr<FJsonValue> MemoryConsumedBytesValue = obj->TryGetField(TEXT("MemoryConsumedBytes"));
    if (MemoryConsumedBytesValue.IsValid() && !MemoryConsumedBytesValue->IsNull())
    {
        uint32 TmpValue;
        if (MemoryConsumedBytesValue->TryGetNumber(TmpValue)) { MemoryConsumedBytes = TmpValue; }
    }

    const TSharedPtr<FJsonValue> ProcessorTimeSecondsValue = obj->TryGetField(TEXT("ProcessorTimeSeconds"));
    if (ProcessorTimeSecondsValue.IsValid() && !ProcessorTimeSecondsValue->IsNull())
    {
        double TmpValue;
        if (ProcessorTimeSecondsValue->TryGetNumber(TmpValue)) { ProcessorTimeSeconds = TmpValue; }
    }

    const TSharedPtr<FJsonValue> RevisionValue = obj->TryGetField(TEXT("Revision"));
    if (RevisionValue.IsValid() && !RevisionValue->IsNull())
    {
        int32 TmpValue;
        if (RevisionValue->TryGetNumber(TmpValue)) { Revision = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::CloudScriptModels::FExecuteEntityCloudScriptRequest::~FExecuteEntityCloudScriptRequest()
{
    //if (Entity != nullptr) delete Entity;

}

void PlayFab::CloudScriptModels::FExecuteEntityCloudScriptRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid()) { writer->WriteIdentifierPrefix(TEXT("Entity")); Entity->writeJSON(writer); }

    writer->WriteIdentifierPrefix(TEXT("FunctionName")); writer->WriteValue(FunctionName);

    if (FunctionParameter.notNull()) { writer->WriteIdentifierPrefix(TEXT("FunctionParameter")); FunctionParameter.writeJSON(writer); }

    if (GeneratePlayStreamEvent.notNull()) { writer->WriteIdentifierPrefix(TEXT("GeneratePlayStreamEvent")); writer->WriteValue(GeneratePlayStreamEvent); }

    if (RevisionSelection.notNull()) { writer->WriteIdentifierPrefix(TEXT("RevisionSelection")); writeCloudScriptRevisionOptionEnumJSON(RevisionSelection, writer); }

    if (SpecificRevision.notNull()) { writer->WriteIdentifierPrefix(TEXT("SpecificRevision")); writer->WriteValue(SpecificRevision); }

    writer->WriteObjectEnd();
}

bool PlayFab::CloudScriptModels::FExecuteEntityCloudScriptRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    const TSharedPtr<FJsonValue> FunctionNameValue = obj->TryGetField(TEXT("FunctionName"));
    if (FunctionNameValue.IsValid() && !FunctionNameValue->IsNull())
    {
        FString TmpValue;
        if (FunctionNameValue->TryGetString(TmpValue)) { FunctionName = TmpValue; }
    }

    const TSharedPtr<FJsonValue> FunctionParameterValue = obj->TryGetField(TEXT("FunctionParameter"));
    if (FunctionParameterValue.IsValid() && !FunctionParameterValue->IsNull())
    {
        FunctionParameter = FJsonKeeper(FunctionParameterValue);
    }

    const TSharedPtr<FJsonValue> GeneratePlayStreamEventValue = obj->TryGetField(TEXT("GeneratePlayStreamEvent"));
    if (GeneratePlayStreamEventValue.IsValid() && !GeneratePlayStreamEventValue->IsNull())
    {
        bool TmpValue;
        if (GeneratePlayStreamEventValue->TryGetBool(TmpValue)) { GeneratePlayStreamEvent = TmpValue; }
    }

    RevisionSelection = readCloudScriptRevisionOptionFromValue(obj->TryGetField(TEXT("RevisionSelection")));

    const TSharedPtr<FJsonValue> SpecificRevisionValue = obj->TryGetField(TEXT("SpecificRevision"));
    if (SpecificRevisionValue.IsValid() && !SpecificRevisionValue->IsNull())
    {
        int32 TmpValue;
        if (SpecificRevisionValue->TryGetNumber(TmpValue)) { SpecificRevision = TmpValue; }
    }

    return HasSucceeded;
}

