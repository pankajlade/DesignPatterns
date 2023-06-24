#include <iostream>
#include <experimental/propagate_const>
#include <memory>

using namespace std;

class Widget{
    class Impl;
    std::experimental::propagate_const<std::unique_ptr<Impl>> pImpl;    public: 
        Widget();
        ~Widget();
        explicit Widget(int);
        Widget(const Widget&) = delete;
        Widget& operator =(const Widget&) = delete ;
        Widget(Widget &&);
        Widget& operator =(Widget &&);

        void draw() const;
        void draw();
        bool shown() const{
            return true;
        }
};