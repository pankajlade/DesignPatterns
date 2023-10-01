#if 0
    Let's implement the Builder pattern to create a configuration object for a hypothetical application. 
    The configuration object will have various optional parameters, and we'll use the Builder pattern to construct it step by step.

#endif

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Configuration{

public:    
    std::string appName;
    std::string databaseName;
    bool isDebugMode;
    int port;

    // Private constructor to enforce object construction throgh the builder.
    Configuration(){}
    void display() const{
        cout << "Configuration \n";
        cout << "App Name : " << appName <<endl;
        cout << "DataBaseName : " << databaseName << endl;
        cout << "isDebugMode : " << isDebugMode << endl;
        cout << "Port : " << port << endl;
    }

    // Builder class for configuration objects .
    class Builder;
};


// In this example, the Configuration class has private member variables for application name, database host, port, and debug mode. 
// The Builder class is nested inside the Configuration class and is responsible for constructing the Configuration objects step by step.


// Builder class for configuration Objects.
class Configuration::Builder {
    Configuration config;
    public:
        Builder & setAppName(const std::string & name){
            config.appName = name ;
            return *this;
        }

        Builder & setDatabaseName(const std::string & dbname){
            config.databaseName = dbname;
            return *this;
        }

        Builder & setDebugMode(bool dmode){
            config.isDebugMode = dmode;
            return *this;
        }

        Builder & setPort(int myport){
            config.port = myport;
            return *this;
        }
        Configuration build() const{
            return config;
        }
};

// The client code demonstrates how to use the Configuration::Builder to create a Configuration object with specific parameters. 
// The display() method is used to print the configuration details.

int main()
{
    Configuration myConfig = Configuration::Builder().setAppName("MyApp")
                                                        .setDatabaseName("My DataBase")
                                                        .setDebugMode(true)
                                                        .setPort(8080)
                                                        .build();

    myConfig.display();
}
