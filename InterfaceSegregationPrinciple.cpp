/*
    1. Interface Segregation Principle(ISP) : which state that client should not be forced to depend on the interfaces they donot use,
    i.e interface shoould be specific to the need of the client and It should not have extra function which client's don't require or not use 
    By keeping interface focused and minimal we can avoid the unneccessary depwendencies and make the system more flexible, maintainable, and easier to understand.




*/


// First lets have a example which violtes the ISP
#include <bits/stdc++.h>
using namespace std;


// lets have an interface Printer which has 2 function:
// 1. print the document 
// 2. Scan the document

// Placeholder Document class
class Document {
    std::string content;

public:
    Document(const std::string& content) : content(content) {}

    std::string getContent() const {
        return content;
    }
};

class Printer{
    public:
    virtual void printDoc(Document& doc)=0;
    virtual void scanDoc(Document& doc)=0;
};

// Conceret class 
class AllInOnePrinter:public Printer{
    public:
    void printDoc(Document& doc){
        // print the document
    }
    void scanDoc(Document& doc){
        // scan the document
    }
};
// Here this Design violets the ISP  principle because we are forcing all cleint to use both print and scan function while client may be intertesd in photocopier function only 


class PhotoCopier:public Printer{
    Printer& m_printer;
    public:
    PhotoCopier(Printer& printer): m_printer(printer){}
    void makeCopy(Document& doc){

        // perform some operation 

        m_printer.printDoc(doc); // print the doc
        // perform some operation
        
   }
   };
    // Here Photocopier class depends on Printer intreface but just use only one fucntion that is printDoc, so its violtes the ISP, which state that 
    // Interface should be thin and we should not use any extra fucntiopn which we are not using so to follow ISP we can redesign the above code and refactor the code as below 

class Printer{
    public:
    virtual void printDoc(Document& doc) =0;
};

class Scanner{
    public:
    virtual void scanDoc(Document& doc) =0;
};
    

class AllInOnePrinter:public Printer, public Scanner{
    public:
    void printDoc(Document& doc) override{
        // print the doc
    }
    void scanDoc(Document& doc) override{ 
        // scan the doc
    }
};

class PhotoCopier:public Printer{
    Printer& m_printer;
    public:
    PhotoCopier(Printer& printer): m_printer(printer){}
    void makeCopy(Document& doc){

        // perform some operation 

        m_printer.printDoc(doc); // print the doc
        // perform some operation
        
   }

};

int  main(int argc, const char** argv) {
    return 0;
}
/*
Following the ISP benefits us in several ways:

Reduced Dependency: By separating the interfaces, the PhotoCopier class depends only on the Printer interface, eliminating the unnecessary dependency on the scan() method. This reduces the coupling between the PhotoCopier class and the Scanner functionality.

Interface Specificity: Each interface now represents a specific functionality, providing a clearer contract to clients. This promotes a more focused and understandable interaction between classes and interfaces.

Improved Maintainability: With more specific interfaces, changes to one functionality (e.g., scanning) are less likely to impact other unrelated functionalities 
*/