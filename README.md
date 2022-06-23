# extension-resource-encryption
This extension implements a buildtime plugin for encryption of resources in the game archive and a runtime counterpart to decrypt the resources. The extension uses the same encryption algorithm as in the official Defold source code, but since it can be forked it allows developers to replace the default encryption key with a private project specific key.

NOTE: The plugin only works when bundling a project using the bob.jar command line tools. It does not work when bundling from the editor.

NOTE: Defold does not encrypt all resources in a game archive and instead encrypts only [certain resource extensions](https://github.com/defold/defold/blob/dev/com.dynamo.cr/com.dynamo.cr.bob/src/com/dynamo/bob/archive/ArchiveBuilder.java#L55).

## Installation
To use this library in your Defold project you need to [make a fork of this repository](https://github.com/defold/extension-resource-encryption/fork) and then add the repository archive URL to your `game.project` dependencies. Example (replace `%YOUR_ORG%` with your GitHub user or organisation):

https://github.com/%YOUR_ORG%/extension-resource-encryption/archive/master.zip

## Buildtime plugin for Bob
https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/pluginsrc/com/dynamo/bob/archive/CustomResourceEncryption.java

## Runtime decryption
https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/src/plugin.cpp

## Replace the key
When you [fork of this repository](https://github.com/defold/extension-resource-encryption/fork make sure to change the key in both the buildtime and runtime part of the extension:

* Buildtime: https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/pluginsrc/com/dynamo/bob/archive/CustomResourceEncryption.java#L7
* Runtime: https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/src/plugin.cpp#L7

## Use your own encryption
Use this extension as a base to apply your own encryption algorithm to the resources. Using custom encryption will add another layer of security as the encryption algorithm will not be know to an attacker.
