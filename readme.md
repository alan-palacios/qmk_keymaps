# QMK Keymaps
Custom keymaps for mechanical keyboards running QMK Firmware

## Compile

```sh
cp -r qmk_keymaps/keyboards/bm60poker/keymaps/alply-winc qmk_firmware/keyboards/bm60poker/keymaps
cd qmk_firmware
qmk compile -kb bm60poker -km alply-winc
```

This should result in an `alply-winc.hex` file being generated
in the `qmk_firmware` root directory.
