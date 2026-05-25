// Copyright Noa Second 2026. All Rights Reserved.
#include "BlueprintProjectSettingsLibrary.h"

#include "GeneralProjectSettings.h"
#include "UObject/UnrealType.h"
#include "UObject/SoftObjectPtr.h"
#include "Engine/Texture2D.h"

namespace
{
	const UGeneralProjectSettings* GetProjectSettingsDefaults()
	{
		return GetDefault<UGeneralProjectSettings>();
	}

	FString ReadProjectSettingsPropertyValue(const UGeneralProjectSettings* Settings, const FName PropertyName)
	{
		if (!Settings)
		{
			return FString();
		}

		const FProperty* Property = Settings->GetClass()->FindPropertyByName(PropertyName);
		if (!Property)
		{
			return FString();
		}

		const void* ValuePtr = Property->ContainerPtrToValuePtr<void>(Settings);

		if (const FStrProperty* StringProperty = CastField<FStrProperty>(Property))
		{
			return StringProperty->GetPropertyValue(ValuePtr);
		}

		if (const FTextProperty* TextProperty = CastField<FTextProperty>(Property))
		{
			return TextProperty->GetPropertyValue(ValuePtr).ToString();
		}

		if (const FNameProperty* NameProperty = CastField<FNameProperty>(Property))
		{
			return NameProperty->GetPropertyValue(ValuePtr).ToString();
		}

		if (const FBoolProperty* BoolProperty = CastField<FBoolProperty>(Property))
		{
			return BoolProperty->GetPropertyValue(ValuePtr) ? TEXT("True") : TEXT("False");
		}

		if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property))
		{
			if (StructProperty->Struct == TBaseStructure<FGuid>::Get())
			{
				const FGuid* GuidValue = StructProperty->ContainerPtrToValuePtr<FGuid>(Settings);
				return GuidValue ? GuidValue->ToString() : FString();
			}
		}

		if (const FObjectPropertyBase* ObjectProperty = CastField<FObjectPropertyBase>(Property))
		{
			const UObject* ObjectValue = ObjectProperty->GetObjectPropertyValue(ValuePtr);
			return ObjectValue ? ObjectValue->GetPathName() : FString();
		}

		return FString();
	}

	FBlueprintProjectSettingsAboutInfo ReadAboutInfo(const UGeneralProjectSettings* Settings)
	{
		FBlueprintProjectSettingsAboutInfo Result;
		Result.ProjectID = ReadProjectSettingsPropertyValue(Settings, TEXT("ProjectID"));
		Result.ProjectName = ReadProjectSettingsPropertyValue(Settings, TEXT("ProjectName"));
		Result.ProjectVersion = ReadProjectSettingsPropertyValue(Settings, TEXT("ProjectVersion"));
		Result.Description = ReadProjectSettingsPropertyValue(Settings, TEXT("Description"));
		Result.ProjectThumbnail = ReadProjectSettingsPropertyValue(Settings, TEXT("ProjectThumbnail"));
		// Try to read ProjectThumbnail as an object/soft object when possible
		if (Settings)
		{
			const FProperty* Property = Settings->GetClass()->FindPropertyByName(TEXT("ProjectThumbnail"));
			if (Property)
			{
				if (const FSoftObjectProperty* SoftObjProp = CastField<FSoftObjectProperty>(Property))
				{
					FSoftObjectPtr SoftPtr = SoftObjProp->GetPropertyValue_InContainer(Settings);
					Result.ProjectThumbnail = TSoftObjectPtr<UTexture2D>(SoftPtr.ToSoftObjectPath());
				}
				else if (const FObjectPropertyBase* ObjProp = CastField<FObjectPropertyBase>(Property))
				{
					UObject* Obj = ObjProp->GetObjectPropertyValue_InContainer(Settings);
					if (UTexture2D* Tex = Cast<UTexture2D>(Obj))
					{
						Result.ProjectThumbnail = Tex;
					}
				}
			}
		}
		return Result;
	}

	FBlueprintProjectSettingsPublisherInfo ReadPublisherInfo(const UGeneralProjectSettings* Settings)
	{
		FBlueprintProjectSettingsPublisherInfo Result;
		Result.CompanyName = ReadProjectSettingsPropertyValue(Settings, TEXT("CompanyName"));
		Result.CompanyDistinguishedName = ReadProjectSettingsPropertyValue(Settings, TEXT("CompanyDistinguishedName"));
		Result.Homepage = ReadProjectSettingsPropertyValue(Settings, TEXT("Homepage"));
		Result.SupportContact = ReadProjectSettingsPropertyValue(Settings, TEXT("SupportContact"));
		return Result;
	}

	FBlueprintProjectSettingsLegalInfo ReadLegalInfo(const UGeneralProjectSettings* Settings)
	{
		FBlueprintProjectSettingsLegalInfo Result;
		Result.CopyrightNotice = ReadProjectSettingsPropertyValue(Settings, TEXT("CopyrightNotice"));
		Result.LicensingTerms = ReadProjectSettingsPropertyValue(Settings, TEXT("LicensingTerms"));
		return Result;
	}

	FBlueprintProjectSettingsDisplayedInfo ReadDisplayedInfo(const UGeneralProjectSettings* Settings)
	{
		FBlueprintProjectSettingsDisplayedInfo Result;
		Result.ProjectDisplayedTitle = ReadProjectSettingsPropertyValue(Settings, TEXT("ProjectDisplayedTitle"));
		Result.ProjectDebugTitleInfo = ReadProjectSettingsPropertyValue(Settings, TEXT("ProjectDebugTitleInfo"));
		return Result;
	}
}

FString UBlueprintProjectSettingsLibrary::ReadProjectSettingValue(const FName PropertyName)
{
	return ReadProjectSettingsPropertyValue(GetProjectSettingsDefaults(), PropertyName);
}

FBlueprintProjectSettingsAboutInfo UBlueprintProjectSettingsLibrary::GetProjectSettingsAbout()
{
	return ReadAboutInfo(GetProjectSettingsDefaults());
}

FBlueprintProjectSettingsAboutInfo UBlueprintProjectSettingsLibrary::GetProjectSettingsAboutSection(const FBlueprintProjectSettingsInfo& ProjectSettings)
{
	return ProjectSettings.About;
}

FBlueprintProjectSettingsPublisherInfo UBlueprintProjectSettingsLibrary::GetProjectSettingsPublisher()
{
	return ReadPublisherInfo(GetProjectSettingsDefaults());
}

FBlueprintProjectSettingsPublisherInfo UBlueprintProjectSettingsLibrary::GetProjectSettingsPublisherSection(const FBlueprintProjectSettingsInfo& ProjectSettings)
{
	return ProjectSettings.Publisher;
}

FBlueprintProjectSettingsLegalInfo UBlueprintProjectSettingsLibrary::GetProjectSettingsLegal()
{
	return ReadLegalInfo(GetProjectSettingsDefaults());
}

FBlueprintProjectSettingsLegalInfo UBlueprintProjectSettingsLibrary::GetProjectSettingsLegalSection(const FBlueprintProjectSettingsInfo& ProjectSettings)
{
	return ProjectSettings.Legal;
}

FBlueprintProjectSettingsDisplayedInfo UBlueprintProjectSettingsLibrary::GetProjectSettingsDisplayed()
{
	return ReadDisplayedInfo(GetProjectSettingsDefaults());
}

FBlueprintProjectSettingsDisplayedInfo UBlueprintProjectSettingsLibrary::GetProjectSettingsDisplayedSection(const FBlueprintProjectSettingsInfo& ProjectSettings)
{
	return ProjectSettings.Displayed;
}

FBlueprintProjectSettingsInfo UBlueprintProjectSettingsLibrary::GetProjectSettings()
{
	FBlueprintProjectSettingsInfo Result;
	const UGeneralProjectSettings* Settings = GetProjectSettingsDefaults();
	Result.About = ReadAboutInfo(Settings);
	Result.Publisher = ReadPublisherInfo(Settings);
	Result.Legal = ReadLegalInfo(Settings);
	Result.Displayed = ReadDisplayedInfo(Settings);
	return Result;
}

FString UBlueprintProjectSettingsLibrary::GetProjectID(const FBlueprintProjectSettingsAboutInfo& About)
{
	return About.ProjectID;
}

FString UBlueprintProjectSettingsLibrary::GetProjectName(const FBlueprintProjectSettingsAboutInfo& About)
{
	return About.ProjectName;
}

FString UBlueprintProjectSettingsLibrary::GetProjectVersion(const FBlueprintProjectSettingsAboutInfo& About)
{
	return About.ProjectVersion;
}

FString UBlueprintProjectSettingsLibrary::GetProjectDescription(const FBlueprintProjectSettingsAboutInfo& About)
{
	return About.Description;
}

TSoftObjectPtr<UTexture2D> UBlueprintProjectSettingsLibrary::GetProjectThumbnail(const FBlueprintProjectSettingsAboutInfo& About)
{
	return About.ProjectThumbnail;
}

FString UBlueprintProjectSettingsLibrary::GetCompanyName(const FBlueprintProjectSettingsPublisherInfo& Publisher)
{
	return Publisher.CompanyName;
}

FString UBlueprintProjectSettingsLibrary::GetCompanyDistinguishedName(const FBlueprintProjectSettingsPublisherInfo& Publisher)
{
	return Publisher.CompanyDistinguishedName;
}

FString UBlueprintProjectSettingsLibrary::GetHomepage(const FBlueprintProjectSettingsPublisherInfo& Publisher)
{
	return Publisher.Homepage;
}

FString UBlueprintProjectSettingsLibrary::GetSupportContact(const FBlueprintProjectSettingsPublisherInfo& Publisher)
{
	return Publisher.SupportContact;
}

FString UBlueprintProjectSettingsLibrary::GetCopyrightNotice(const FBlueprintProjectSettingsLegalInfo& Legal)
{
	return Legal.CopyrightNotice;
}

FString UBlueprintProjectSettingsLibrary::GetLicensingTerms(const FBlueprintProjectSettingsLegalInfo& Legal)
{
	return Legal.LicensingTerms;
}

FString UBlueprintProjectSettingsLibrary::GetProjectDisplayedTitle(const FBlueprintProjectSettingsDisplayedInfo& Displayed)
{
	return Displayed.ProjectDisplayedTitle;
}

FString UBlueprintProjectSettingsLibrary::GetProjectDebugTitleInfo(const FBlueprintProjectSettingsDisplayedInfo& Displayed)
{
	return Displayed.ProjectDebugTitleInfo;
}