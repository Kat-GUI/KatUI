//
// Created by Yorkin on 2020/4/29.
//
#ifndef KATPRESENTER_PRESENTER_H
#define KATPRESENTER_PRESENTER_H
#include<memory>
#include"Layout.h"
namespace kat {
    class Color{};
    class Bitmap{};
    class Font{};
    using colorPtr = std::shared_ptr<Color>;
    using bitmapPtr = std::shared_ptr<Bitmap>;
    using fontPtr = std::shared_ptr<Font>;
    class Presenter {
    public:
        virtual void begin() = 0;
        virtual void clear(Color color) = 0;
        virtual void fillRectangle(Region region, colorPtr color) = 0;
        virtual void drawRectangle(Region region, colorPtr color, float strokeWidth = 1.0) = 0;
        virtual void fillRoundRectangle(Region region, colorPtr color, float corner) = 0;
        virtual void drawRoundRectangle(Region region, colorPtr color, float corner, float strokeWidth = 1.0) = 0;
        virtual void drawEllipse(Region region, colorPtr color, float strokeWidth = 1.0) = 0;
        virtual void fillEllipse(Region region, colorPtr color) = 0;
        virtual void resize(int width, int height) = 0;
        virtual void drawLine(int beginX,int beginY,int endX,int endY,colorPtr color,int Stroke = 1.0) = 0;
        virtual void drawBitmap(Region region, std::shared_ptr<Bitmap> bitmap, float opacity = 1) = 0;
        virtual void drawString(Region region, colorPtr color,fontPtr font,std::wstring text) = 0;
        virtual bitmapPtr createImage(std::wstring path) = 0;
        virtual fontPtr createFont(std::wstring name)=0;
        virtual colorPtr RGBA(char r,char g,char b,char a=255)=0;
        virtual colorPtr color(long hex)=0;
        virtual void end() = 0;
    };
}
#endif //KATPRESENTER_PRESENTER_H
