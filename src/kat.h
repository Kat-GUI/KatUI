//
// Created by Yorkin on 2020/4/30.
//
#ifndef KATUI_KAT_H
#define KATUI_KAT_H

#include<string>
#include"Layout.h"

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

#include"Presenter.h"
#include"Manager.h"
#ifdef _WIN32
#include"Windows/windowsPkg.h"
#elif __linux__
#include"Linux/linuxPkg.h"
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
