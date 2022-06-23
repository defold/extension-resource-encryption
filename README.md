# extension-resource-encryption
This extension implements a buildtime plugin for resource archive encryption and a runtime counterpart to decrypt the archive. The extension uses the same encryption algorithm as in the official Defold source code, but since it can be forked it allows developers to replace the default encryption key with a private project specific key.

NOTE: The plugin only works when bundling a project using the bob.jar command line tools. It does not work when bundling from the editor.

## Installation
To use this library in your Defold project, add the following URL to your `game.project` dependencies:

https://github.com/defold/extension-resource-encryption/archive/master.zip

We recommend using a link to a zip file of a [specific release](https://github.com/defold/extension-resource-encryption/releases).

## Buildtime plugin for Bob
https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/pluginsrc/com/dynamo/bob/archive/CustomResourceEncryption.java

## Runtime decryption
https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/src/plugin.cpp

## Replace the key
When you fork this repository make sure to change the key in both the buildtime and runtime part of the extension:

* Buildtime: https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/pluginsrc/com/dynamo/bob/archive/CustomResourceEncryption.java#L7
* Runtime: https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/src/plugin.cpp#L7

## Use your own encryption
Use this extension as a base to apply your own encryption algorithm to the resource archive. Using custom encryption will add another layer of security as the encryption algorithm will not be know to an attacker.
