//It defines a contract between base class and derived class enusring that object of the derived classes can be substituted with the object of the base class with out 
// altering the correctness of the program, in simpler term we can say this principle estabilishes the guidelines for inheritance and polymorphism to avoid unexpected behaviour when subsituting the object.
// It promots good design pracrtices and code maintainability 

// To understand LSP, let's explore the principle's requirements and implications:
/*
1. Subtype requirement : A derived class must be substitutable for its base class, 
i.e (i) object of the derived class can be assigned to the variable of the base class type
  (ii) Methods that accepts the base class object should also accepts the derived class object without brealking the correctness of the object.
2. Behaviour Compitability : Derived class must preserv the behaviour of the base class. it should follow the same contract and uphold any invariants estabilished by the base class 


By ensuring behavioral compatibility, LSP allows for the substitution of objects in a polymorphic manner, making the code more modular, reusable, and flexible. It guarantees that derived classes can be seamlessly used in place of the base class, without compromising the correctness or expected behavior of the program


if a class violets the LSP i.e derived class is not compitable with the derived class 
advantage 
1. Modularity and extensibility 
2. Code reuse 
3. Polynorphim 
*/




// Behaviour Compitability 

#include <bits/stdc++.h>

using namespace std;



class Shape{
    public:

    virtual double CalculateArea() =0 ;
};


class Rectangle:public Shape{
    private : 
    double height;
    double length;
    public:
    Rectangle(double len, double hgt) : length(len), height(hgt){}
    double CalculateArea(){
        return height*length;
    }
};


class Square:public Shape{
    private : 
    double side;
    
    public:
    Square(double side) : side(side){}
    double CalculateArea(){
        return side*side;
    }
};

void PrintArea(Shape* shape){
    double area=shape->CalculateArea();
    cout << "Area of the shape is  "  << area << endl;
}


int main(){


    Rectangle *rect= new Rectangle(4.0,3.0);
    Square  *sqre= new Square(5.0);

    PrintArea(rect);
    PrintArea(sqre);
    delete rect;
    delete sqre;
    return 0;

}
