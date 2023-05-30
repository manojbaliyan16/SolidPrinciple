#include <bits/stdc++.h>


using namespace std;



enum class vechileType{
    Car, 
    Truck,
};


class VechicleProcessor{
    public:
    double calculateToll(vechileType type){
        double toll =0.0;
        if(type==vechileType::Car){
            toll=50.0;
        }else if(type==vechileType::Truck){
            toll=100.0;
        }
    }
};

// This class violtes the OCP because if we wants to add the new vechileType as bike in that case we have to modifies the existing class vechileProcessor 
// so this is not the ideal case 

// let see how can we change the design using abstraction and polymorphism 


class Vechile{
    public:
    virtual double calculateToll() =0;
};

class car:public Vechile{
    public:
    double calculateToll() override {
        // calculate Toll for a car
        return 50.0;
    }
};


class Truck:public Vechile{
    public:
    double calculateToll() override {
        // calculate Toll for a Truck
        return 100.0;
    }
};

class Bike:public Vechile{
    public:
    double calculateToll() override {
        // calculate Toll for a Bike
        return 25.0;
    }
};


// Here using abstract class and ploymorphism we can extend the existing functionilty of the system, with out modifying the existing software entity.


// This design helps to make system more flexible, extendable and maitainnable 