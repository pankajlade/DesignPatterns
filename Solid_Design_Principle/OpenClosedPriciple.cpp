/**
Open - Closed Priciple :
===> The Open-Closed Principle (OCP) is a fundamental principle in object-oriented programming, 
     and it states that software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. 
     In other words, you should be able to extend the behavior of a system without modifying its existing code.
 
===> In C++, you can apply the Open-Closed Principle by using techniques such as inheritance, polymorphism, and abstraction. 
     Here's how you can implement it:
  
*/


// Example 1
/*
#include <iostream>
#include <memory>
using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape{
    int r;
    public:
        Circle(int t):r{t}{}
        void draw() const override {
            cout << "Area of Circle : " << (3.14 * r* r) << endl;
        }
};

class Rectangle : public Shape{
    int l;
    int h;
    public:
        Rectangle(int r, int b):l{r},h{b}{}
        void draw() const override{
            cout << "Area of Reactangle : " << (l*h) << endl;
        }

};

class Drawing{
    public:
        void drawShape( std::shared_ptr<Shape>& shape){
            shape->draw();
        }
};

int main()
{
    Drawing dr;
    std::shared_ptr<Shape> cir = make_shared<Circle>(5.43);
    std::shared_ptr<Shape> rec = make_shared<Rectangle>(5, 7);
    dr.drawShape(cir);
    dr.drawShape(rec);
}

*/


// Example 2
/*
    Let's consider a scenario where we have a system that needs to calculate the total cost of a shopping cart. 
    The cart can contain various items, such as books, electronics, and clothing, each with its own pricing strategy. 
    We want to implement the calculation logic in a way that is open for extension but closed for modification.
*/

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Item{
    public:
    virtual double CalculateCost() = 0 ;
};

class Book : public Item{
    double bookPrice;
    public:
    Book(double b):bookPrice{b}{}
    double CalculateCost(){
        return bookPrice + (bookPrice * 10)/100 ;
    }

};

class Electronics : public Item{
    double ePrice;
    public:
    Electronics(double ep):ePrice{ep}{}
    double CalculateCost(){
        return ePrice + (ePrice * 20)/100;
    }
};

class Clothing : public Item
{
    double clothPrice;
public:
    Clothing(double cp):clothPrice{cp}{}
    double CalculateCost() override {
        return clothPrice + (clothPrice * 30)/100;
    }
};

class ShoppingCart{
    std::vector <std::shared_ptr<Item>> items; 
    public:
        void addItem(std::shared_ptr<Item>& vitem){
            items.push_back(vitem);
        }

        double CalculateTotalCost(){
            double totalcost = 0.0;
            for(auto &it : items){
                totalcost += it->CalculateCost();
            }
            return totalcost;
        }
};

int main()
{
    ShoppingCart scart;

    std::shared_ptr <Item> bk = make_shared<Book>(100.00);
    std::shared_ptr <Item> Elk = make_shared<Electronics> (500.00);
    std::shared_ptr <Item> Clk = make_shared<Clothing> (5000.000);

    scart.addItem(bk);
    scart.addItem(Elk);
    scart.addItem(Clk);

    cout << "Total Cost : " << scart.CalculateTotalCost() << "" << endl;

}