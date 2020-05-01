//
// Created by Yorkin on 2020/5/1.
//

#ifndef KATUI_GDIPRESENTER_H
#define KATUI_GDIPRESENTER_H
#include"../Presenter.h"
#include<windows.h>
namespace kat{
    namespace native{
        class gdiColor:public Color{
        public:
            HBRUSH brush;
            HPEN pen;
            void setPen(HDC hdc){
                SelectObject(hdc,brush);
            }
            void setBrush(HDC hdc){
                SelectObject(hdc,pen);
            }
            ~gdiColor(){
                DeleteObject(brush);
                DeleteObject(pen);
            }
        };
        class gdiPresenter:public Presenter{
            HDC hdc;
            HWND hwnd;
            PAINTSTRUCT ps;
            LPRECT rtr(const Region& region){

            }
        public:
            gdiPresenter(HWND hwnd):hwnd(hwnd){}
            virtual void begin(){
                HDC hdc = BeginPaint(hwnd, &ps);
            };
            virtual void clear(Color color){

            };
            virtual void fillRectangle(Region region, colorPtr color){
                ((gdiColor*)color.get())->setBrush(hdc);
                Rectangle(hdc,region.l,region.t,region.r,region.b);
            };
            virtual void drawRectangle(Region region, colorPtr color, float strokeWidth = 1.0){

            };
            virtual void fillRoundRectangle(Region region, colorPtr color, float corner){

            };
            virtual void drawRoundRectangle(Region region, colorPtr color, float corner, float strokeWidth = 1.0){

            };
            virtual void drawEllipse(Region region, colorPtr color, float strokeWidth = 1.0){

            };
            virtual void fillEllipse(Region region, colorPtr color){

            };
            virtual void resize(int width, int height){

            };
            virtual void drawLine(int beginX,int beginY,int endX,int endY,colorPtr color,int Stroke = 1.0){

            };
            virtual void drawBitmap(Region region, std::shared_ptr<Bitmap> bitmap, float opacity = 1){

            };
            virtual void drawString(Region region, colorPtr color,fontPtr font,std::wstring text){

            };
            virtual bitmapPtr createImage(std::wstring path){

            };
            virtual fontPtr createFont(std::wstring name){

            };
            virtual colorPtr RGBA(char r,char g,char b,char a=255){
                auto p = new gdiColor;
                p->brush=CreateSolidBrush(RGB(r,g,b));
                p->pen=CreatePen(1,1,RGB(r,g,b));
                colorPtr ptr(p);
                return ptr;
            };
            virtual colorPtr color(long hex){

            };
            virtual void end(){
                EndPaint(hwnd, &ps);
            };
        };
    }
}
#endif //KATUI_GDIPRESENTER_H
