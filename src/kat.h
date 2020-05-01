//
// Created by Yorkin on 2020/4/30.
//
#ifndef KATUI_KAT_H
#define KATUI_KAT_H

#include<string>
#include"Layout.h"
#include"Presenter.h"
#include"Manager.h"
namespace kat {
    enum Message {
        paint
    };
    class Form;
    class Widget : public Layout {
        friend Form;
        virtual void processMessage(Message msg) {

        }
        virtual void refresh(std::shared_ptr<Presenter> presenter){};
    public:
        virtual int getBoxMinWidth()override{};
        virtual int getBoxMaxWidth()override{};
        virtual int getBoxMinHeight()override{};
        virtual int getBoxMaxHeight()override{};
        virtual bool extendableInWidth()override{};
        virtual bool extendableInHeight()override{};
        virtual int getBoxWidth()override{};
        virtual int getBoxHeight()override{};
        virtual void calcuRegion(Region anchor) {
            region = anchor;
        }
    };
}
#ifdef _WIN32
#include"Windows/windowsPkg.h"
#elif __linux__
#include"Linux/linuxPkg.h"
#endif

namespace kat {
    class Form:public Widget{
        bool loaded=false;
        std::wstring title;
        template<typename FORM>
        friend void startUp(std::wstring title,int left,int top,int width,int height);
        std::shared_ptr<formController> controller;
    public:
        std::shared_ptr<Presenter> presenter;
        void show(){
            if(loaded)return;
            controller=Manager::singleton->createForm(region.l,region.t,region.w,region.h,title);
            presenter=Manager::singleton->CreatePresenter(controller);
            loaded=true;
            load();
        }
        virtual std::wstring getTitle(){
            return title;
        }
        virtual void load()=0;
        virtual void processMessage(Message msg)override{

        }
    };

    template<typename FORM>
    void startUp(std::wstring title,int left,int top,int width,int height){
        FORM form;
        form.region.l=left;
        form.region.t=top;
        form.region.w=width;
        form.region.h=height;
        form.title=title;
        form.show();
        Manager::singleton->MainLoop(form.controller);
    };

    class Rectangle:public Widget{
    public:
        colorPtr background,foreground;
        Rectangle(colorPtr background,colorPtr foreground):background(background),foreground(foreground){}
        virtual void refresh(std::shared_ptr<Presenter> presenter)override{
            presenter->fillRectangle(region,background);
            presenter->drawRectangle(region,foreground);
        }
    };

#define startApp(myForm,title) int main(){startUp<myForm>(title,0,0,400,400);}
}

#endif //KATUI_KAT_H
