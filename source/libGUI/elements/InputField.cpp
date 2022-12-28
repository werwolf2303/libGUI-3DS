#include <citro2d.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
#include "libGUI/logging/Logger.cpp"
#include "libGUI/Colors.cpp"

#pragma once

class InputField {
    public:
    std::string ph = "";
    std::string v = "";

    void setPlaceholder(std::string placeholder) {
        ph = placeholder;
    }
    void setValue(std::string value) {
        v = value;
    }
    std::string getPlaceholder() {
        return ph;
    }
    std::string getValue() {
        return v;
    }
};

