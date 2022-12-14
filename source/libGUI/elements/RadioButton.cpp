#include <3ds.h>
#include <string>
#include <citro2d.h>
#include "libGUI/elements/Text.cpp"
#include "libGUI/Colors.cpp"

#pragma once

class RadioButton {
    public:
    int xaxis = 0;
    int yaxis = 0;
    std::string text = "";
    bool selected = false;
    Text rt;
    Logger log;
    void draw() {
        if(text!="") {
            rt.text = text;
            rt.size = 0.5f;
            rt.xaxis = xaxis + 3;
            rt.yaxis = yaxis;
            rt.draw();
        }
        if(selected) {
            C2D_DrawCircleSolid(xaxis, yaxis, 0, 4, clrBlack);
        }
        log.debugXY("RadioButton", xaxis, yaxis);
        C2D_DrawCircle(xaxis, yaxis, 0, 10, clrWhite, clrWhite, clrWhite, clrWhite);
    }
};