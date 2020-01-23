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
               unsigned int glMajor = 3, unsigned int glMinor = 3)
        :
          nanogui::Screen(size, caption, resizable, fullscreen, colorBits, alphaBits, depthBits, stencilBits, nSamples, glMajor, glMinor)
    {
        using namespace nanogui;
        mColumns.resize(3);
        mRows.resize(3);
        mLayout = new AdvancedGridLayout(mColumns, mRows, 20);
        setLayout(mLayout);
        mLayout->setColStretch(1, 0.33f);
        mLayout->setRowStretch(1, 0.33f);

        mAplyButton = new Button(this, "Aply");
        mLayout->setAnchor(mAplyButton, AdvancedGridLayout::Anchor(1, 1, 1, 1, Alignment::Middle, Alignment::Middle));
        mAplyButton->setVisible(true);

        setBackground(nanogui::Color(127, 127, 127, 0.5));
        setResizeCallback([&](nanogui::Vector2i)
        {
            performLayout();
            drawAll();
        });

        performLayout();
    }

    ~MainWindow()
    {
    }

    bool keyboardEvent(int key, int scancode, int action, int modifiers)
    {
        if (Screen::keyboardEvent(key, scancode, action, modifiers))
            return true;
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            setVisible(false);
            return true;
        }
        return false;
    }

//    void draw(NVGcontext* ctx)
//    {
//        Screen::draw(ctx);
//    }

private:

    std::vector<int> mColumns;
    std::vector<int> mRows;
    nanogui::AdvancedGridLayout* mLayout;
    nanogui::Button* mAplyButton;
};

}//namespace fm
