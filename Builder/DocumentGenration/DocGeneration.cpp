#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// Product class representing the complex object to be created 
class PDFDocument{
    std::string content{""};
    public:
    void addHeader(const std::string & text){
        content += "Header " + text + "\n";
    }
    void addParagraph(const std::string & text){
        content += "Paragraph " + text + "\n";
    }
    void addImagePath(const std::string &imgPath){
        content += "ImagePath " + imgPath + "\n";
    }
    std::string getContent(){
        return content;
    }
};

// Abstract builder class defining the interfce for building the product.
class DocumentBuilder{
    public: 
        virtual ~DocumentBuilder() = default;
        virtual void buildHeader(const std::string & text)=0;
        virtual void buildParagraph(const std::string & text) = 0;
        virtual void buildImage(const std::string & imgPath) = 0;
        virtual PDFDocument getResult() const = 0;
};

// concrete Builder class implementing the DocumentBuilder interface.
class PDFDocumentBuilder : public DocumentBuilder{
    private :
        PDFDocument pdfDocument;
    public:
        void buildHeader(const std::string & text) override{
            pdfDocument.addHeader(text);
        }
        void buildParagraph(const std::string & text) override{
            pdfDocument.addParagraph(text);
        }
        void buildImage(const std::string & imgPath) override{
            pdfDocument.addImagePath(imgPath);
        }
        PDFDocument getResult() const override{
            return pdfDocument;
        }
    
};

// Director class responsible for constructing the object using the builder
class DocumentDirector{
    DocumentBuilder* builder{};
    public:
    DocumentDirector(DocumentBuilder* myBuilder):builder{myBuilder} {}
    void buildDocument(){
        builder->buildHeader("Sample PDF Document");
        builder->buildParagraph("This is a paragraph in the PDF Document.");
        builder->buildImage("https://www.myArt.com/image.png");
    }
};

int main()
{
    PDFDocumentBuilder pdfbuilder;
    DocumentDirector director{&pdfbuilder};
    director.buildDocument();

    PDFDocument pdfDocument = pdfbuilder.getResult();
    std::string content = pdfDocument.getContent();

    cout << "Generated PDF Document : \n" << content ;
}