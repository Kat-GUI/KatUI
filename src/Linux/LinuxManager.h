#ifndef LINUX_MANAGER
#define LINUX_MANAGER
#include"../Manager.h"
#include<X11/Xlib.h>
//When CMake report: Could not find X11
//sudo apt-get install libx11-dev
namespace kat{
    namespace native{
        class linuxFormController:public formController {
        public:

            virtual void Terminate() {

            }
            virtual void Minimize() {

            }
            virtual void Maximize() {

            }
            virtual void Hide() {

            }
            virtual Rect getRect() {

            }
            virtual void setRect(Rect rect) {

            }

            virtual void show() {

            }
        };
        class linuxManager:public Manager{
            virtual std::shared_ptr<formController> createForm(int x, int y, int width, int height, std::wstring title) {

            }

            virtual void MainLoop(std::shared_ptr<formController> form) {

            }

            virtual std::shared_ptr<Presenter> CreatePresenter(std::shared_ptr<formController> form) {

            }

            virtual std::shared_ptr<timerController> CreateTimer(int interval) {

            }
        };
    }
    const std::shared_ptr<Manager> Manager::singleton((Manager*)new native::linuxManager);

}
#endif