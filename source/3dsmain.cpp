#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include "libGUI/Colors.cpp"
#include "libGUI/Window.cpp"


int main(int argc, char* argv[])
{
    Window win;
    win.init(GFX_BOTTOM);
	win.setDebug(GFX_TOP);
	Button button;
	button.text = "ButtonText";
	button.height = 20;
	button.width = 160;
	button.xaxis = 50;
	button.yaxis = 40;
	win.addButton(button);
	win.draw();
	while (aptMainLoop())
	{
		hidScanInput();

		// Your code goes here
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
	}
    win.deinit();
	return 0;
}