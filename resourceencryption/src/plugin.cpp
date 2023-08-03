#include <dmsdk/sdk.h>
#include <dmsdk/dlib/crypt.h>
#include <dmsdk/resource/resource.h>

// change this in your own fork!
// also change in CustomResourceEncryption.java
const char* KEY = "aQj8CScgNP4VsfXK";
	
static dmResource::Result FooDecrypt(void* buffer, uint32_t buffer_len)
{
	dmCrypt::Result cr = dmCrypt::Decrypt(dmCrypt::ALGORITHM_XTEA, (uint8_t*) buffer, buffer_len, (const uint8_t*) KEY, strlen(KEY));
	if (cr != dmCrypt::RESULT_OK)
	{
		return dmResource::RESULT_UNKNOWN_ERROR;
	}
	return dmResource::RESULT_OK;
}

static dmExtension::Result AppInitialize(dmExtension::AppParams* params)
{
	dmResource::RegisterResourceDecryptionFunction(FooDecrypt);
	return dmExtension::RESULT_OK;
}

static dmExtension::Result Initialize(dmExtension::Params* params)
{
	return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(CustomResourceEncryption, "CustomResourceEncryption", AppInitialize, 0, Initialize, 0, 0, 0);
