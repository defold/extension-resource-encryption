package com.dynamo.bob.archive;

import com.dynamo.bob.archive.ResourceEncryptionPlugin;
import com.dynamo.crypt.Crypt;

public class CustomResourceEncryption extends ResourceEncryptionPlugin {
	private final byte[] KEY = "aQj8CScgNP4VsfXK".getBytes();

	@Override
	public byte[] encrypt(byte[] resource) throws Exception {
		return Crypt.encryptCTR(resource, KEY);
	}
}
