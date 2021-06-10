# Zenith DOOM
This project ports the DOOM BSP renderer to Zenith for use in custom games.
It includes a `zos/` directory in `src/` which has includes that emulate
Zenith types, functions, and globals. This is to make it easier on us to test
from our desktop operating systems while porting.

## Zenith Functions, Types, and Globals
These are accessable by including `zos/` header files. Includes from `zos/` as
well as c-specific code should be wrapped in `#ifdef NOT_ZENITH`. `main.c` is
for creating the executable to test outside of Zenith. Run the file named after
the game or application if you are in Zenith.

## Set Up With Visual Studio
Use `file->open->cmake` in Visual Studio to open this project. You can set the
configuration to `x64-debug` or `x64-release` (you might have to add them with
the `Manage Configurations...` button in the dropdown). It won't built x86
because I only copied x64 binaries into `libs/`.

You need to copy SDL2.dll to the `out/build/x64-` directory of your choice. For
some reason Visual Studio does not want to do this by default.

## Drawing a Pixel
This application uses fullscreen in Zenith and disables the OS rendering to give
complete unrestricted access to the framebuffer. You can draw to this framebuffer
with:

	text.fb_alias[y * GR_WIDTH + x] = color; // Color is a CBGR24

Colors in Zenith are defined as:

	class CBGR24
	{
		U8 b, g, r, pad;
	}

Macros such as `GR_WIDTH` and `GR_HEIGHT` can be used to get the screen size.