//
// Created by Yorkin on 2020/4/29.
//

#ifndef KATMANAGER_WIN32MANAGER_H
#define KATMANAGER_WIN32MANAGER_H
#ifndef UNICODE
#define UNICODE
#endif
#include"../Manager.h"
#include"windows.h"
#include"GDIPresenter.h"
#include<string>
namespace kat {
    namespace native {
        class win32FormController : formController {
        public:
            HWND hwnd;
            win32FormController(HWND hwnd) : hwnd(hwnd) {

            }

            virtual void Terminate() override {

            };

            virtual void Minimize() override {

            };

            virtual void Maximize() override {

            };

            virtual void Hide() override {

            };

            virtual void show() override {
                ShowWindow(hwnd, SW_SHOW);
            }


            virtual Rect getRect() override {

            };

            virtual void setRect(Rect rect) override {

            };
        };

        class win32TimerController {
        };

        LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
            switch (uMsg) {
                case WM_DESTROY:
                    PostQuitMessage(0);
                    return 0;

                case WM_PAINT: {

                }
                    return 0;

            }
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

        class win32Manager : public Manager {
        public:
            win32Manager() {
                WNDCLASS wc = {};
                wc.style = CS_HREDRAW | CS_VREDRAW;
                wc.lpfnWndProc = WindowProc;
                wc.hInstance = GetModuleHandle(0);
                wc.lpszClassName = L"KatUI";
                wc.hbrBackground = CreateSolidBrush(RGB(220, 220, 220));
                RegisterClass(&wc);
            }

            virtual std::shared_ptr<formController>
            createForm(int x, int y, int width, int height, std::wstring title) {
                HWND hwnd = CreateWindowEx(
                        0,
                        L"KatUI",
                        title.c_str(),
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
                        NULL,       // Parent window
                        NULL,       // Menu
                        GetModuleHandle(0),  // Instance handle
                        NULL        // Additional application data
                );
                std::shared_ptr<formController> form((formController *) new win32FormController(hwnd));
                forms.push_back(form);
                return form;
            };

            virtual void MainLoop(std::shared_ptr<formController> form) {
                form->show();
                MSG msg = {};
                while (GetMessage(&msg, NULL, 0, 0)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            };

            virtual std::shared_ptr<Presenter> CreatePresenter(std::shared_ptr<formController> form) {
                std::shared_ptr<Presenter> ptr(new gdiPresenter(((win32FormController*)form.get())->hwnd));
                return ptr;
            };

            virtual std::shared_ptr<timerController> CreateTimer(int interval) {

            };
        };
    }
    const std::shared_ptr<Manager> Manager::singleton((Manager*)new native::win32Manager);
}
#endif //KATMANAGER_WIN32MANAGER_H
