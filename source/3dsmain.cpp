#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include "libGUI/Colors.cpp"
#include "libGUI/Window.cpp"


int main(int argc, char* argv[])
{
    Window win;
    win.init(GFX_TOP);
    win.setDebug(GFX_BOTTOM);
	Button button;
	button.text = "ButtonText";
	button.height = 20;
	button.width = 160;
	button.xaxis = 50;
	button.yaxis = 40;
	Button button2;
	button2.text = "ButtonText2";
	button2.height = 20;
	button2.height = 160;
	button2.xaxis = 50;
	button2.yaxis = 130;
	win.addButton(button);
	win.addButton(button2);
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