#include "chaining.h"

//Word class implementation
Word::Word(string val, Word *nPtr)
{

    word = val;
    next = nPtr;


} //END Word::Word(string val, Word *nPtr)

List::List(){
    header = nullptr;
    count = 0;
}

void List::clear(){
    cout << "running destructor" << endl;
    Word* temp = header;
    while(temp != nullptr){
        Word* temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
}

void List::push_front(string x){
    Word* temp = new Word(x);
    temp->next = header;
     header = temp;
}

bool ChainingHash::isPrime(int x){
    for(int i = 2; i < x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int ChainingHash::nextPrime(int x){
    while(!isPrime(x)){
        x++;
    }
    return x;
}

ChainingHash::ChainingHash(int b){
    b = (nextPrime(b));
    this->space = b;
    contents = new List*[space];
    for(int i = 0; i < space; i++){
        contents[i] = new List();
    }
}


int ChainingHash::hashFunction(const string & key){
    unsigned int hashVal = 0;
    for (char ch: key){
        hashVal = 37 * hashVal + ch;
    }
    return hashVal % space;
}

void ChainingHash::insertItem(string x){
    int index = hashFunction(x) % space;
    contents[index]->push_front(x);
}


void ChainingHash::displayHash(){
    for(int i = 0; i < space; i++){
        cout << "Bucket " << i << ": ";
        Word* curr = contents[i]->header;
        while(curr != NULL){
            cout << curr->word << " ";
            curr = curr->next;
            cout << " printed " << endl;
        }
        cout << endl;
    }
}

bool ChainingHash::findItem(string x){
    int index = hashFunction(x) % space;
    Word* curr = contents[index]->header;
    while(curr != NULL){
        if(curr->word == x){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

ChainingHash::~ChainingHash(){
    for (unsigned int i = 0; i < space; ++i)
    {
        contents[i]->clear();
        delete contents[i];
    }
    delete[] contents;
    space = 0;
}