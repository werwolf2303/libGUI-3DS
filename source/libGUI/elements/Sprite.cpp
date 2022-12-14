#include <3ds.h>
#include <string>
#include <citro2d.h>
#include "libGUI/logging/Logger.cpp"

#pragma once

class Sprite {
    public:
    int xaxis = 0;
    int yaxis = 0;
    float width = 0;
    float height = 0;
    std::string imagepath = "";
    Logger log;
    void draw() {
        if(imagepath!="") {
            C2D_Image image;
            const C2D_ImageTint *tint;
            C2D_DrawImageAt(image, xaxis, yaxis, 0, tint, width, height);
            log.debugXYWHP("Sprite", xaxis, yaxis, width, height, imagepath);
        }
    }
};