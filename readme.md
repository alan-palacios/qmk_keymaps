# QMK Keymaps
Custom keymaps for mechanical keyboards running QMK Firmware

## Compile

```sh
cp -r qmk_keymaps/keyboards/air40/keymaps/alply qmk_firmware/keyboards/ymdk/ymd40/v2/keymaps
cd qmk_firmware
qmk compile -kb ymdk/ymd40/v2 -km alply
```

This should result in an `alply.hex` file being generated
in the `qmk_firmware` root directory.
