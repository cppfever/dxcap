#include "mainwindow.h"

using namespace nanogui;

namespace dxcap
{
MainWindow::MainWindow(const nanogui::Vector2i &size, const std::string &caption,
                       bool resizable, bool fullscreen, int colorBits,
                       int alphaBits, int depthBits, int stencilBits,
                       int nSamples,
                       unsigned int glMajor, unsigned int glMinor)
    :
      nanogui::Screen(size, caption, resizable, fullscreen, colorBits, alphaBits, depthBits, stencilBits, nSamples, glMajor, glMinor)
{
    setBackground(Color(127, 127, 127, 0.5));
    setResizeCallback([&](nanogui::Vector2i)
    {
        performLayout();
        drawAll();
    });

    performLayout();

    mBoxLayout = new BoxLayout(Orientation::Vertical, Alignment::Fill, 10, 10);
    this->setLayout(mBoxLayout);
}

MainWindow::~MainWindow()
{
}

bool MainWindow::keyboardEvent(int key, int scancode, int action, int modifiers)
{
    if (Screen::keyboardEvent(key, scancode, action, modifiers))
        return true;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        setVisible(false);
        return true;
    }
    return false;
}

void MainWindow::draw(NVGcontext* ctx)
{        
    //Screen::draw(ctx);
}
}//namespace fm
