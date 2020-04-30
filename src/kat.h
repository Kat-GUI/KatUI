//
// Created by Yorkin on 2020/4/30.
//
#ifndef KATUI_KAT_H
#define KATUI_KAT_H

#include<string>
#include"Layout/src/Layout.h"

namespace kat {
    class Widget : public Layout {
        enum Enum {
            paint
        };

        virtual void processMessage(Enum msg) {

        }

    public:
        virtual void calcuRegion(Region anchor) {
            region = anchor;
        }
    };
}

#include"Presenter/src/Presenter.h"
#include"Manager/src/Manager.h"
#ifdef _WIN32
    #include"Manager/src/Win32Manager.h"
    #include"Presenter/src/D2DPresenter.h"
#elif __linux__
    #include"Manager/src/LinuxManager.h"
    #include"Presenter/src/XlibPresenter.h"
#endif

namespace kat {
    class Form:public Widget{
        friend void startUp(Form form);
        std::shared_ptr<formController> controller;
    public:
        Form(std::wstring title,int left,int top,int width,int height){
            controller=Manager::singleton->createForm(left,top,width,height,title);
        }
        virtual int getBoxMinWidth(){};
        virtual int getBoxMaxWidth(){};
        virtual int getBoxMinHeight(){};
        virtual int getBoxMaxHeight(){};
        virtual bool extendableInWidth(){};
        virtual bool extendableInHeight(){};
        virtual int getBoxWidth(){};
        virtual int getBoxHeight(){};
    };
    void startUp(Form form){
        Manager::singleton->MainLoop(form.controller);
    }
}

#endif //KATUI_KAT_H
