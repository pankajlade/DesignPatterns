#include "Widget.h"

int main()
{
    Widget obj{7};
    const Widget obj1{20};
    obj.draw();
    obj1.draw();
}