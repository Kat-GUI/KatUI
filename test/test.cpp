#include <iostream>
using namespace std;
#include"../src/kat.h"
using namespace kat;
class myApp:public Form{
public:
    virtual void load()override{
        //构造组件
        child.reset(new kat::Rectangle(presenter->RGBA(100,0,100),
                                          presenter->RGBA(100,0,0)));
    }
};

startApp(myApp,L"啦啦啦")
