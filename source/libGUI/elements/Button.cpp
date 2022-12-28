#include <citro2d.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
#include "libGUI/logging/Logger.cpp"
#include "libGUI/Colors.cpp"
#include "libGUI/elements/Text.cpp"

#pragma once

class Button {
    public:
    int xaxis = 0;
    int yaxis = 0;
    int width = 0;
    int height = 0;
    std::string text = "";
    u32 backgroundColor = clrWhite;
    u32 foregroundColor = clrBlack;
    Text te;
    Logger log;
    void draw() {
        C2D_DrawRectangle(xaxis,yaxis,0,width,height,backgroundColor,backgroundColor,backgroundColor,backgroundColor);
        if(text!="") {
            te.text = text;
            te.size = 0.5f;
            te.xaxis = xaxis;
            te.yaxis = yaxis;
            te.draw();
        }
        log.debugXYWH("Button", xaxis, yaxis, width, height);
        return;
    };
};