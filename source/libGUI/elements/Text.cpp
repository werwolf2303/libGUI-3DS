#include <citro2d.h>
#include <3ds.h>
#include <string>
#include "libGUI/logging/Logger.cpp"

#pragma once

class Text {
    public:
    int xaxis = 0;
    int yaxis = 0;
    float size = 0;
    std::string text = "";
    Logger log;
    void draw() {
        C2D_TextBuf g_staticBuf;
        C2D_Text g_staticText[4];
        g_staticBuf  = C2D_TextBufNew(4096);
        C2D_TextParse(&g_staticText[0], g_staticBuf, text.c_str());
        C2D_TextOptimize(&g_staticText[0]);
        C2D_DrawText(&g_staticText[0], C2D_WithColor, xaxis, yaxis, 0, 0.5f, 0.75f, C2D_Color32f(1.0f,0.0f,0.0f,1.0f));
        log.debugXY("Text", xaxis, yaxis);
        return;
    }
};