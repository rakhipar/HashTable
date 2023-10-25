#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using std::string;
using std::endl;
using std::cout;

class Word {
public:
    string word;
    Word* next;
    
    Word(string word = "", Word *next = NULL);
};

class List {
public:
    Word* header;
    int count;
    
    List();
    ~List(){clear();}
    void push_front(string x);
    void clear();

};




class ChainingHash{
private:
    int space;
  //  List* head;
    List** contents;

public:
    ChainingHash(int x);
    ~ChainingHash();
    bool isPrime(int x);
    int nextPrime(int x);
    void insertItem(string x);
    int hashFunction(const string & x);
    void displayHash();
    bool findItem(string x);

};