#include <dmsdk/sdk.h>
#include <dmsdk/resource/resource_archive.h>

namespace CustomResourceEncryption
{
	// change this in your own fork!
	// also change in CustomResourceEncryption.java
	const char* KEY = "%/builtins/connect";
		
	static dmResourceArchive::Result Decrypt(void* buffer, uint32_t buffer_len)
	{
		dmCrypt::Result cr = dmCrypt::Decrypt(dmCrypt::ALGORITHM_XTEA, (uint8_t*) buffer, buffer_len, (const uint8_t*) KEY, strlen(KEY));
		if (cr != dmCrypt::RESULT_OK)
		{
			return dmResourceArchive::RESULT_UNKNOWN;
		}
		return dmResourceArchive::RESULT_OK;
	}

	static dmExtension::Result AppInitialize(dmExtension::AppParams* params)
	{
		dmResourceArchive::RegisterResourceDecryption(dmSillyEncryption::Decrypt);
		return dmExtension::RESULT_OK;
	}

	static dmExtension::Result Initialize(dmExtension::Params* params)
	{
		return dmExtension::RESULT_OK;
	}
}

DM_DECLARE_EXTENSION(CustomResourceEncryption, "CustomResourceEncryption", CustomResourceEncryption::AppInitialize, 0, CustomResourceEncryption::Initialize, 0, 0, 0);
