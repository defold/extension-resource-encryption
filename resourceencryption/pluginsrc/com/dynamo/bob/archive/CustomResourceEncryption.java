package com.dynamo.bob.archive;

import com.dynamo.bob.archive.ResourceEncryptionPlugin;
import com.dynamo.crypt.Crypt;

public class CustomResourceEncryption extends ResourceEncryptionPlugin {
	private final byte[] KEY = "%/builtins/fonts".getBytes();

	@Override
	public byte[] encrypt(byte[] resource) throws Exception {
		return Crypt.encryptCTR(resource, KEY);
	}
}