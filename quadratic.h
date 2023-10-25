#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using std::string;
using std::endl;
using std::cout;

class QuadraticHash{
private:
    int space;
    string *contents;
public:
    QuadraticHash(int size);
    ~QuadraticHash(){delete[] contents;}
    bool isPrime(int x);
    int nextPrime(int x);
    void insertItem(string x);
    int findPos(string x);
    int hashFunction(const string & x);
    void displayHash();
    bool findItem(string x);
};