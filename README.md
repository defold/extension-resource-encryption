# extension-resource-encryption
This extension implements a buildtime plugin for encryption of resources in the game archive and a runtime counterpart to decrypt the resources. The extension uses the same encryption algorithm as in the official Defold source code, but since it can be forked it allows developers to replace the default encryption key with a private project specific key.

NOTE: Defold does not encrypt all resources in a game archive. Instead Defold encrypts a [subset of resource types](https://github.com/defold/defold/blob/dev/com.dynamo.cr/com.dynamo.cr.bob/src/com/dynamo/bob/archive/ArchiveBuilder.java#L55) where it may be desirable to apply additional protection.


## Installation
To use this library in your Defold project you need to [make a fork of this repository](https://github.com/defold/extension-resource-encryption/fork) and then add the repository archive URL to your `game.project` dependencies. Example (replace `%YOUR_ORG%` with your GitHub user or organisation):

https://github.com/%YOUR_ORG%/extension-resource-encryption/archive/master.zip


## Modifying the extension
The extension consists of two parts:

* Buildtime encryption plugin for Bob - https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/pluginsrc/com/dynamo/bob/archive/CustomResourceEncryption.java
* Runtime decryption in the engine - https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/src/plugin.cpp

NOTE: When the buildtime encryption part of the plugin has changed it needs to be compiled and packaged as a .jar file for Bob to use. Run the `build_plugin.sh` script to build the jar file and copy it to the correct location (`resourceencryption/plugins/share/`). The script needs a copy of bob.jar.

### Replace the key
When you [fork this repository](https://github.com/defold/extension-resource-encryption/fork) make sure to change the key in both the buildtime and runtime part of the extension:

* Buildtime: https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/pluginsrc/com/dynamo/bob/archive/CustomResourceEncryption.java#L7
* Runtime: https://github.com/defold/extension-resource-encryption/blob/master/resourceencryption/src/plugin.cpp#L7

### Use your own encryption
Use this extension as a base to apply your own encryption algorithm to the resources. Using custom encryption will add another layer of security as the encryption algorithm will not be know to an attacker.
