//
// Created by Yorkin on 2020/4/29.
//
#ifndef KATPRESENTER_PRESENTER_H
#define KATPRESENTER_PRESENTER_H
#include<memory>
#include"Layout.h"
namespace kat {
    class Color{};
    class Presenter {
    public:
        // Marign offset;
        virtual void Begin() = 0;

        virtual void Clear(Color color) = 0;

        virtual void FillRectangle(Region region, Color color) = 0;

        virtual void DrawRectangle(Region region, Color color, float strokeWidth = 1.0) = 0;

        virtual void FillRoundRectangle(Region region, Color color, float corner) = 0;

        virtual void DrawRoundRectangle(Region region, Color color, float corner, float strokeWidth = 1.0) = 0;

        virtual void DrawEllipse(Region region, Color color, float strokeWidth = 1.0) = 0;

        virtual void FillEllipse(Region region, Color color) = 0;

        virtual void DrawString(Region region, Color color, std::string text) = 0;

        virtual void Resize(int width, int height) = 0;

        virtual void End() = 0;

        //virtual void DrawLine(Point begin, Point end, int Stroke, Color color) = 0;
        //virtual void DrawArc(Point pos, int startAngle, int endAngle) = 0;
        //virtual void FillPie(Point pos, int startAngle, int endAngle) = 0;
        //virtual void DrawBitmap(Region region, std::shared_ptr<Bitmap> bitmap, float opacity = 1) = 0;
        //virtual IImageHander CreateImage(std::string path) = 0;
    };
}
#endif //KATPRESENTER_PRESENTER_H
