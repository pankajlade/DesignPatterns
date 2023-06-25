#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class IObserver{
    public:
        virtual void newUpdateShow(float price) = 0;
};

class Shop : public IObserver{
    std::string name;
    float price ;
    public:
        Shop(const std::string & nam){
            this->name = nam;
        }
        
        void newUpdateShow(float price) override{
            this->price = price;
            cout << "Price at " << name << " is now "<< price << endl;
        }

};

class ShopOperationSubject{
    /*Let's keep a list of shop which you want to update whenever some update come.*/
    std::vector<Shop *> list;

    std::vector<Shop*>::iterator itr;
    public:
        void SubcribeInfo(Shop * shop){
            list.push_back(shop);
        }

        void UnSubscribeInfo(Shop * shop){
            /*
                Removing is done by shifting (by means of move assignment) the elements in the range 
                in such a way that the elements that are not to be removed appear in the beginning of the range.
                removable elements that remain is preserved in vector and it will shift to last of vector but
                remove will return new wnd of vector in which removeable element will not be there 
                so in short remove will define new beginning and end of the vector , it will not actual delete 
                element from vector and the physical size of the container 
                is unchanged and now erase's beginning is end of remove and end will be actual end of vector.
            */
            list.erase(std::remove(list.begin(),list.end(), shop), list.end());
        };

        void notifyInfo(float price){
            for(vector<Shop *>::const_iterator iter=list.begin(); iter != list.end(); ++iter){
                if(*iter != 0){
                    (*iter)->newUpdateShow(price);
                }
            }
        }
};

class UpdateProductInfo : public ShopOperationSubject{

    public:
        void changePrice(float price){
            notifyInfo(price);
        }
};

int main()
{
    cout << "Hello World "<< endl;
    
    UpdateProductInfo product;
    Shop shop1("Shop_1");
    Shop shop2("Shop_2");

    product.SubcribeInfo(&shop1);
    product.SubcribeInfo(&shop2);

    product.changePrice(10);

    product.UnSubscribeInfo(&shop2);
    cout << "Now shop2 has Unsubscribed " << endl;

    product.changePrice(20);

    return 0;
}

/**
 * Advantages :
 * 
 * 1) It supports the principle of loose coupling between objects that interact with each other 
 * 2) It allows sending data to other objects effectively without any change in the Subject OR 
 *      Observer Observes can be added / removed at any point in time.
 * 
 * Disadvantage :
 * 
 * 1) If not implemented correctly , the observer can add complexity and lead to inadvertent performance.
*/