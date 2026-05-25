// Copyright Noa Second 2026. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/SoftObjectPtr.h"
#include "BlueprintProjectSettingsLibrary.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct BLUEPRINTPROJECTSETTINGS_API FBlueprintProjectSettingsAboutInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString ProjectID;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString ProjectName;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString ProjectVersion;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString Description;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	TSoftObjectPtr<UTexture2D> ProjectThumbnail;
};

USTRUCT(BlueprintType)
struct BLUEPRINTPROJECTSETTINGS_API FBlueprintProjectSettingsPublisherInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString CompanyName;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString CompanyDistinguishedName;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString Homepage;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString SupportContact;
};

USTRUCT(BlueprintType)
struct BLUEPRINTPROJECTSETTINGS_API FBlueprintProjectSettingsLegalInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString CopyrightNotice;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString LicensingTerms;
};

USTRUCT(BlueprintType)
struct BLUEPRINTPROJECTSETTINGS_API FBlueprintProjectSettingsDisplayedInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString ProjectDisplayedTitle;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FString ProjectDebugTitleInfo;
};

USTRUCT(BlueprintType)
struct BLUEPRINTPROJECTSETTINGS_API FBlueprintProjectSettingsInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FBlueprintProjectSettingsAboutInfo About;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FBlueprintProjectSettingsPublisherInfo Publisher;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FBlueprintProjectSettingsLegalInfo Legal;

	UPROPERTY(BlueprintReadOnly, Category = "Project Settings")
	FBlueprintProjectSettingsDisplayedInfo Displayed;
};

UCLASS()
class BLUEPRINTPROJECTSETTINGS_API UBlueprintProjectSettingsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings About"))
	static FBlueprintProjectSettingsAboutInfo GetProjectSettingsAbout();

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings About", CompactNodeTitle = "About"))
	static FBlueprintProjectSettingsAboutInfo GetProjectSettingsAboutSection(const FBlueprintProjectSettingsInfo& ProjectSettings);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings Publisher"))
	static FBlueprintProjectSettingsPublisherInfo GetProjectSettingsPublisher();

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings Publisher", CompactNodeTitle = "Publisher"))
	static FBlueprintProjectSettingsPublisherInfo GetProjectSettingsPublisherSection(const FBlueprintProjectSettingsInfo& ProjectSettings);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings Legal"))
	static FBlueprintProjectSettingsLegalInfo GetProjectSettingsLegal();

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings Legal", CompactNodeTitle = "Legal"))
	static FBlueprintProjectSettingsLegalInfo GetProjectSettingsLegalSection(const FBlueprintProjectSettingsInfo& ProjectSettings);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings Displayed"))
	static FBlueprintProjectSettingsDisplayedInfo GetProjectSettingsDisplayed();

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings Displayed", CompactNodeTitle = "Displayed"))
	static FBlueprintProjectSettingsDisplayedInfo GetProjectSettingsDisplayedSection(const FBlueprintProjectSettingsInfo& ProjectSettings);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Settings"))
	static FBlueprintProjectSettingsInfo GetProjectSettings();

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project ID", CompactNodeTitle = "Project ID"))
	static FString GetProjectID(const FBlueprintProjectSettingsAboutInfo& About);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Name", CompactNodeTitle = "Project Name"))
	static FString GetProjectName(const FBlueprintProjectSettingsAboutInfo& About);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Version", CompactNodeTitle = "Project Version"))
	static FString GetProjectVersion(const FBlueprintProjectSettingsAboutInfo& About);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Description", CompactNodeTitle = "Description"))
	static FString GetProjectDescription(const FBlueprintProjectSettingsAboutInfo& About);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Thumbnail", CompactNodeTitle = "Project Thumbnail"))
	static TSoftObjectPtr<UTexture2D> GetProjectThumbnail(const FBlueprintProjectSettingsAboutInfo& About);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Company Name", CompactNodeTitle = "Company Name"))
	static FString GetCompanyName(const FBlueprintProjectSettingsPublisherInfo& Publisher);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Company Distinguished Name", CompactNodeTitle = "Company DN"))
	static FString GetCompanyDistinguishedName(const FBlueprintProjectSettingsPublisherInfo& Publisher);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Homepage", CompactNodeTitle = "Homepage"))
	static FString GetHomepage(const FBlueprintProjectSettingsPublisherInfo& Publisher);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Support Contact", CompactNodeTitle = "Support Contact"))
	static FString GetSupportContact(const FBlueprintProjectSettingsPublisherInfo& Publisher);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Copyright Notice", CompactNodeTitle = "Copyright"))
	static FString GetCopyrightNotice(const FBlueprintProjectSettingsLegalInfo& Legal);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Licensing Terms", CompactNodeTitle = "Licensing Terms"))
	static FString GetLicensingTerms(const FBlueprintProjectSettingsLegalInfo& Legal);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Displayed Title", CompactNodeTitle = "Displayed Title"))
	static FString GetProjectDisplayedTitle(const FBlueprintProjectSettingsDisplayedInfo& Displayed);

	UFUNCTION(BlueprintPure, Category = "Project Settings", meta = (DisplayName = "Get Project Debug Title Info", CompactNodeTitle = "Debug Title Info"))
	static FString GetProjectDebugTitleInfo(const FBlueprintProjectSettingsDisplayedInfo& Displayed);

private:
	static FString ReadProjectSettingValue(const FName PropertyName);
};