#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Message{
    public:
        std::string sender{};
        std::string recipient{};
        std::string content{};
        std::string subject{};

        void display() const{
            cout << "Messaging Details \n";
            cout << "Sender : " << sender << endl;
            cout << "Recipient : " << recipient << endl;
            cout << "Content : "<< content << endl;
            cout << "Subject : " << subject << endl;
        }
};

// Builder class for constructing Message objects.
class MessageBuilder{
    Message msg;
    public:
        MessageBuilder & setSender(const std::string snd){
            msg.sender = snd ;
            return *this;
        }
        MessageBuilder& setRecipient(const std::string rec){
            msg.recipient = rec;
            return *this;
        }
        MessageBuilder& setContent(const std::string con){
            msg.content = con;
            return *this;
        }
        MessageBuilder& setSubject(const std::string & sub){
            msg.subject = sub;
            return *this;
        }
        Message build(){
            return msg;
        }
};

int main()
{
    Message myMsg = MessageBuilder().setSender("Pankaj")
                                    .setRecipient("Vicky")
                                    .setContent("India is a my Country")
                                    .setSubject("VLSI")
                                    .build();

    myMsg.display();
}