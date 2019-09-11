//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabMatchmakerInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::MatchmakerModels;

UPlayFabMatchmakerInstanceAPI::UPlayFabMatchmakerInstanceAPI()
{
}

UPlayFabMatchmakerInstanceAPI::UPlayFabMatchmakerInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabMatchmakerInstanceAPI::UPlayFabMatchmakerInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabMatchmakerInstanceAPI::UPlayFabMatchmakerInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabMatchmakerInstanceAPI::~UPlayFabMatchmakerInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabMatchmakerInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabMatchmakerInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabMatchmakerInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabMatchmakerInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabMatchmakerInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabMatchmakerInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabMatchmakerInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = MakeSharedUObject<UPlayFabAuthenticationContext>();

    return this->authContext;
}

bool UPlayFabMatchmakerInstanceAPI::AuthUser(
    MatchmakerModels::FAuthUserRequest& request,
    const FAuthUserDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetDeveloperSecretKey().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey().Len() == 0)){
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Matchmaker/AuthUser")) : this->settings->GetUrl(TEXT("/Matchmaker/AuthUser")), request.toJSONString(), TEXT("X-SecretKey"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey() : request.AuthenticationContext->GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerInstanceAPI::OnAuthUserResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerInstanceAPI::OnAuthUserResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAuthUserDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FAuthUserResponse outResult;
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

bool UPlayFabMatchmakerInstanceAPI::PlayerJoined(
    MatchmakerModels::FPlayerJoinedRequest& request,
    const FPlayerJoinedDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetDeveloperSecretKey().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey().Len() == 0)){
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Matchmaker/PlayerJoined")) : this->settings->GetUrl(TEXT("/Matchmaker/PlayerJoined")), request.toJSONString(), TEXT("X-SecretKey"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey() : request.AuthenticationContext->GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerInstanceAPI::OnPlayerJoinedResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerInstanceAPI::OnPlayerJoinedResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPlayerJoinedDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FPlayerJoinedResponse outResult;
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

bool UPlayFabMatchmakerInstanceAPI::PlayerLeft(
    MatchmakerModels::FPlayerLeftRequest& request,
    const FPlayerLeftDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetDeveloperSecretKey().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey().Len() == 0)){
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Matchmaker/PlayerLeft")) : this->settings->GetUrl(TEXT("/Matchmaker/PlayerLeft")), request.toJSONString(), TEXT("X-SecretKey"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey() : request.AuthenticationContext->GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerInstanceAPI::OnPlayerLeftResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerInstanceAPI::OnPlayerLeftResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPlayerLeftDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FPlayerLeftResponse outResult;
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

bool UPlayFabMatchmakerInstanceAPI::StartGame(
    MatchmakerModels::FStartGameRequest& request,
    const FStartGameDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetDeveloperSecretKey().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey().Len() == 0)){
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Matchmaker/StartGame")) : this->settings->GetUrl(TEXT("/Matchmaker/StartGame")), request.toJSONString(), TEXT("X-SecretKey"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey() : request.AuthenticationContext->GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerInstanceAPI::OnStartGameResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerInstanceAPI::OnStartGameResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FStartGameDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FStartGameResponse outResult;
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

bool UPlayFabMatchmakerInstanceAPI::UserInfo(
    MatchmakerModels::FUserInfoRequest& request,
    const FUserInfoDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetDeveloperSecretKey().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey().Len() == 0)){
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Matchmaker/UserInfo")) : this->settings->GetUrl(TEXT("/Matchmaker/UserInfo")), request.toJSONString(), TEXT("X-SecretKey"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetDeveloperSecretKey() : request.AuthenticationContext->GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerInstanceAPI::OnUserInfoResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerInstanceAPI::OnUserInfoResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUserInfoDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FUserInfoResponse outResult;
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
