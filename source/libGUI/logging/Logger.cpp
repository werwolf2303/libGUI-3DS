#include <string>
#include <3ds.h>

#pragma once

class Logger {
private:
gfxScreen_t stw;
public:

void info(std::string text) {
    printf("[INFO] %s\n", text.c_str());
    return;
}
void warning(std::string text) {
    printf("[WARN] %s\n", text.c_str());
    return;
}
void error(std::string text) {
    printf("[ERROR] %s\n", text.c_str());
    return;
}
void panic(std::string text) {
    printf("[PANIC] %s\n", text.c_str());
    return;
}
void debug(std::string text) {
    printf("[DEBUG] %s\n", text.c_str());
    return;
}
void debugXY(std::string elemname, int x, int y) {
    printf("[DEBUG] Drawing %s at: x:%d y:%d \n", elemname.c_str(), x, y);
}
void debugXYWH(std::string elemname, int x, int y, int width, int height) {
    printf("[DEBUG] Drawing %s at: x:%d y:%d width:%d height:%d\n", elemname.c_str(), x, y, width, height);
}
void debugXYWHP(std::string elemname, int x, int y, int width, int height, std::string path) {
    printf("[DEBUG] Drawing %s at: x:%d y:%d width:%d height:%d Path:%s\n", elemname.c_str(), x, y, width, height, path.c_str());
}
void init(gfxScreen_t screen) {
    stw = screen;
    gfxInitDefault();
	consoleInit(stw, NULL);
    return;
}
void deinit() {
    gfxExit();
    return;
}
};