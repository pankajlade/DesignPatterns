#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Computer{
    public:
        std::string CPU;
        std::string RAM;
        std::string storage;
        std::string GPU;
        
        void display(){
            cout << "Computer Configuration \n";
            cout << "CPU : " << CPU << endl;
            cout << "RAM : " << RAM <<endl;
            cout << "Storage : " << storage << endl;
            cout << "GPU : " << GPU <<endl;
        }
};

// Builder class for consstructing computer objects.
class ComputerBuilder{
    Computer computer;
    public: 
        ComputerBuilder & setCPU(const std::string & cpu){
            computer.CPU = cpu;
            return *this;
        }
        ComputerBuilder & setRAM(const std::string & ram){
            computer.RAM = ram;
            return *this;
        }
        ComputerBuilder & setStorage(const std::string & store){
            computer.storage = store;
            return *this;
        }
        ComputerBuilder & setGPU(const std::string & gpu){
            computer.GPU = gpu;
            return *this;
        } 
        Computer build(){
            return computer;
        }
};

int main()
{
    ComputerBuilder builder;

    Computer compObj = builder.setCPU("I7-Core")
                                .setRAM("16 GB")
                                .setStorage("1 TB SSD   ")
                                .setGPU("NVIDIA GTX 1650")
                                .build();
    
    compObj.display();
    
}
