//
// Created by Yorkin on 2020/4/29.
//

#ifndef KATMANAGER_MANAGER_H
#define KATMANAGER_MANAGER_H
#include<string>
#include<memory>
namespace kat {
    struct Rect {
        int left, top, width, height;
    };

    class formController {
    public:
        virtual void Terminate() = 0;

        virtual void Minimize() = 0;

        virtual void Maximize() = 0;

        virtual void Hide() = 0;

        virtual Rect getRect() = 0;

        virtual void setRect(Rect rect) = 0;

        virtual void show() = 0;
    };

    class timerController {
    };

    class Manager {
    public:
        static const std::shared_ptr<Manager> singleton;
        std::list<std::shared_ptr<formController>> forms;
        std::vector<std::shared_ptr<timerController>> timers;

        virtual std::shared_ptr<formController> createForm(int x, int y, int width, int height, std::wstring title) = 0;

        virtual void MainLoop(std::shared_ptr<formController> form) = 0;

        virtual std::shared_ptr<Presenter> CreatePresenter(std::shared_ptr<formController> form) = 0;

        virtual std::shared_ptr<timerController> CreateTimer(int interval) = 0;
    };
}
#endif //KATMANAGER_MANAGER_H
