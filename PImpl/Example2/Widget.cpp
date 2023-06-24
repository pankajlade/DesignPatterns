#include "Widget.h"

class Widget::Impl
{
    int l;
public:
    void draw(const Widget& obj) const{
        if(obj.shown())
            cout << "Drawing a const Widget " << l << endl;
    }
    void draw(const Widget& obj){
        if(obj.shown())
            cout << "Drawing a Non-const Widget " << l << endl;
    }

    Impl(int n):l{n} {}
};

Widget::Widget()=default;
Widget::~Widget()=default;

void Widget::draw() const{
    pImpl->draw(*this);
}

void Widget::draw(){
    pImpl->draw(*this);
}

Widget::Widget(int m):pImpl{ std::make_unique<Widget::Impl> (m) }{}
// copy Constructor
// Widget::Widget(const Widget&) = delete ;
// Widget& Widget::operator =(const Widget&)=delete ;

// Move Constructor
Widget::Widget(Widget &&) = default;
Widget& Widget::operator =(Widget &&) = default;