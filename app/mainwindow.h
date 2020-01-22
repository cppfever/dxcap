#pragma once

#include "common.h"


namespace dxcap
{

class MainWindow : public nanogui::Screen
{
public:

    MainWindow(const nanogui::Vector2i &size, const std::string &caption,
               bool resizable = true, bool fullscreen = false, int colorBits = 8,
               int alphaBits = 8, int depthBits = 24, int stencilBits = 8,
               int nSamples = 0,
               unsigned int glMajor = 3, unsigned int glMinor = 3);
    ~MainWindow();

    bool keyboardEvent(int key, int scancode, int action, int modifiers) override;
    void draw(NVGcontext* ctx) override;

private:

    nanogui::BoxLayout* mBoxLayout {nullptr};
};

}//namespace fm
