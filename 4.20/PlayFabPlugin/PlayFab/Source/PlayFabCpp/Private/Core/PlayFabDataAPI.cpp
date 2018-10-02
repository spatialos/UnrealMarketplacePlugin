//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabDataAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::DataModels;

UPlayFabDataAPI::UPlayFabDataAPI() {}

UPlayFabDataAPI::~UPlayFabDataAPI() {}

int UPlayFabDataAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

FString UPlayFabDataAPI::GetBuildIdentifier() const
{
    return PlayFabSettings::buildIdentifier;
}

void UPlayFabDataAPI::SetTitleId(const FString& titleId)
{
    PlayFabSettings::SetTitleId(titleId);
}

void UPlayFabDataAPI::SetDevSecretKey(const FString& developerSecretKey)
{
    PlayFabSettings::SetDeveloperSecretKey(developerSecretKey);
}

bool UPlayFabDataAPI::AbortFileUploads(
    DataModels::FAbortFileUploadsRequest& request,
    const FAbortFileUploadsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/File/AbortFileUploads")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataAPI::OnAbortFileUploadsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataAPI::OnAbortFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAbortFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FAbortFileUploadsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataAPI::DeleteFiles(
    DataModels::FDeleteFilesRequest& request,
    const FDeleteFilesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/File/DeleteFiles")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataAPI::OnDeleteFilesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataAPI::OnDeleteFilesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteFilesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FDeleteFilesResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataAPI::FinalizeFileUploads(
    DataModels::FFinalizeFileUploadsRequest& request,
    const FFinalizeFileUploadsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/File/FinalizeFileUploads")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataAPI::OnFinalizeFileUploadsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataAPI::OnFinalizeFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FFinalizeFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FFinalizeFileUploadsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataAPI::GetFiles(
    DataModels::FGetFilesRequest& request,
    const FGetFilesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/File/GetFiles")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataAPI::OnGetFilesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataAPI::OnGetFilesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetFilesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FGetFilesResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataAPI::GetObjects(
    DataModels::FGetObjectsRequest& request,
    const FGetObjectsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/Object/GetObjects")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataAPI::OnGetObjectsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataAPI::OnGetObjectsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetObjectsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FGetObjectsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataAPI::InitiateFileUploads(
    DataModels::FInitiateFileUploadsRequest& request,
    const FInitiateFileUploadsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/File/InitiateFileUploads")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataAPI::OnInitiateFileUploadsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataAPI::OnInitiateFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FInitiateFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FInitiateFileUploadsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataAPI::SetObjects(
    DataModels::FSetObjectsRequest& request,
    const FSetObjectsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/Object/SetObjects")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataAPI::OnSetObjectsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataAPI::OnSetObjectsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetObjectsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FSetObjectsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

