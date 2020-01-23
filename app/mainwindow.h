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

        mWindow = new Window(this, "Some window");

        mTabs = new TabWidget(mWindow);
        Widget* imagetab = mTabs->createTab("Captured Images");
        //imagetab->setSize(Vector2i(800, 600));

        mColumns.resize(3);
        mRows.resize(3);
        mLayout = new AdvancedGridLayout(mColumns, mRows, 0);
        mLayout->setColStretch(0, 0.33f);
        mLayout->setRowStretch(0, 0.33f);
        mLayout->setColStretch(1, 0.33f);
        mLayout->setRowStretch(1, 0.33f);

        imagetab->setLayout(mLayout);

        mAplyButton = new Button(imagetab, "Aply");
        mLayout->setAnchor(mAplyButton, AdvancedGridLayout::Anchor(2, 2, 1, 1, Alignment::Middle, Alignment::Middle));

        mImageView = new ImageView(imagetab, 0);
        //mImageView->setSize(Vector2i(800, 600));
        mLayout->setAnchor(mImageView, AdvancedGridLayout::Anchor(0, 0, 1, 1, Alignment::Middle, Alignment::Middle));

        setBackground(nanogui::Color(127, 127, 127, 0.5));
      /*  setResizeCallback([&](nanogui::Vector2i)
        {
            performLayout();
            drawAll();
        });*/

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

    bool resizeEvent(const Eigen::Vector2i & size) override
    {
        mWindow->setPosition(Eigen::Vector2i(0,0));
        mWindow->setSize(Eigen::Vector2i(width(), height()));

        mTabs->setPosition(Eigen::Vector2i(0,0));
        mTabs->setSize(Eigen::Vector2i(mWindow->width(), mWindow->height()));

        return true;
    }
//    void draw(NVGcontext* ctx)
//    {
//        Screen::draw(ctx);
//    }

private:


    std::vector<int> mColumns;
    std::vector<int> mRows;
    nanogui::AdvancedGridLayout* mLayout;

    nanogui::Window* mWindow;
    nanogui::TabWidget* mTabs;
    nanogui::Button* mAplyButton;
    nanogui::ImageView* mImageView;
    GLuint mBackImage;

};

}//namespace fm
