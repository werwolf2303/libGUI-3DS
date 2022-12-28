#include <3ds.h>
#include <list>
#include <citro2d.h>
#include "logging/Logger.cpp"
#include "libGUI/Colors.cpp"
#include "libGUI/elements/Button.cpp"
#include "libGUI/elements/RadioButton.cpp"
#include "libGUI/elements/Text.cpp"
#include "libGUI/Threading.cpp"

class Window {
    private:
    bool debug = false;
    gfxScreen_t logscreen;
    gfxScreen_t winscreen;
    Logger log;
    u32 bgColor  = clrBlack;
    C3D_RenderTarget* scr;
    std::list<Button> buttons;
    std::list<Text> texts;
    std::list<RadioButton> radiobuttons;
    touchPosition touch;
    Threading thread;
    public:
    void setDebug(gfxScreen_t screen) {
        logscreen = screen;
        log.init(screen);
        log.info("Logging enabled");
        debug = true;
        return;
    }
    void drawElements() {
        for(Button b : buttons) {
            b.draw();
        }
        for(Text t : texts) {
            t.draw();
        }
        for(RadioButton rb : radiobuttons) {
            rb.draw();
        }
        return;
    }
    int getTouchY() {
        return touch.py;
    }
    int getTouchX() {
        return touch.px;
    }
    void repaint() {
        drawElements();
    }
    void addText(Text t) {
        texts.push_back(t);
        return;
    }
    void addRadioButton(RadioButton rb) {
        radiobuttons.push_back(rb);
        return;
    }
    void addButton(Button b) {
        buttons.push_back(b);
        return;
    }
    void init(gfxScreen_t windowscreen) {
        winscreen = windowscreen;
        C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
        C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
        C2D_Prepare();
        scr = C2D_CreateScreenTarget(winscreen, GFX_LEFT);
		hidTouchRead(&touch);
        return;
    }
    void setBackgroundColor(u32 color) {
        bgColor = color;
        return;
    }
    void initDrawing() {
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(scr, bgColor);
		C2D_SceneBegin(scr);
        return;
    }
    void EndDrawing() {
        C3D_FrameEnd(0);
        return;
    }
    void draw() {
        initDrawing();
        drawElements();
        EndDrawing();
    }
    Logger getLogger() {
        return log;
    }
    void deinit() {
        C2D_Fini();
        C3D_Fini();
        if(debug) {
            log.deinit();
        }
        return;
    }
};