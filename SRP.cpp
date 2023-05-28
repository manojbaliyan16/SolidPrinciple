#include <bits/stdc++.h>


using namespace std;



class FileProcessor{
    public:
    void processFile(const string& inputFile, const string& outputFile ){
        // ReadData from InputFile
        // calculation
        // Write Data to output File
    }
    // This class is doing three task, so voilets the SRP principle means if we can change this class due to 3 reason one is while reading , 2  while doing calculation 
    // and 3. while doing writing 
    // Due to above violation it is not a good desing 
};

// As per SRP : Here code is more flexibile, readable and maintainable 
class FileReader{
    public:
    vector<int> readFromFile(const string &inputFile){
        // just read the data from file
        // return the data as vector 
    }

};


class Calculator{
    public:
    int performCalculation(vector<int> &data){
        // perform calculation on data and return the result
    }
};


class FileWriter{
    void writeToFile(const string& outputFile, int result){
        // write the result to outputFile
    }
};