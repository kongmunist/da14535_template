# Project

The project builds off a makefile using the clang compiler and uses VSCode as an editor. For direct Renesas/ Dialog support you would need to use one of there eclipse based IDEs (either SmartSnippets or e² Studio) which I find too painful to actually use. The DA14531 has very limited RAM and clang / LLVM produces significantly smaller binaries than arm-none-eabi-gcc can produce. For this project this likely does not matter, but this makes it easier to extend this project in the future.

# Building project

Information for building and debugging project can be pulled from the vscode project. Alternatively you can `cd build/release` and run `make`. If you do not already have `arm-none-eabi toolchain` and `clang` (Not Mac's default as this does not support cross compilation to Arm M0+) you will need to install them. The current paths in the makefile should line up with where they will be put on a mac with HomeBrew.

# Programming Development Kit

[ezFlashCLI](https://github.com/ezflash/ezFlashCLI) is the easiest way to clear and program flash. If you want to put the program into OTP you may need to alter ezFlashCLI or use one of Renesas's supported tools such as SmartSnippets Toolbox. 