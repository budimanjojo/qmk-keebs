<div align="center">

### My QMK keyboards firmwares

</div>

## :book:&nbsp; Overview

This repository contains my QMK keyboard firmwares source code.
It's equivalent to the [QMK Userspace](https://github.com/qmk_userspace) repository.

All of my QMK powered keyboards will be in the [./keyboards](./keyboards) directory (currently only one which is my [Sofle](https://github.com/josefadamcik/SofleKeyboard) keyboard).

## :wrench:&nbsp; Flashing the keyboard

To flash the keyboard:

1. Clone this repository to your workstation, `cd` into the cloned directory.
2. Run `qmk setup -H <path-to-qmk_firmware>` if you haven't done so before. 
3. Run `qmk compile -kb <the-keyboard> -km <the-keymap>`. I.e: to build the keyboard in `./keyboards/sofle/rev1/keymaps/budimanjojo`, the command will be `qmk compile -kb sofle/rev1 -km budimanjojo`.
4. If the compilation finished without error, run `qmk flash -kb <the-keyboard> -km <the-keymap>` to flash the firmware into the keyboard.
