#include "quadratic.h"

QuadraticHash::QuadraticHash(int size){
    //cout << "size: " << size << endl;
    this->space = (nextPrime(size*2));
    contents = new string[space];
    for(int i = 0; i < space; i++){
        contents[i] = "";
    }
}

bool QuadraticHash::isPrime(int x){
    for(int i = 2; i < x/2; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int QuadraticHash::nextPrime(int x){
    while(!isPrime(x)){
        x++;
    }
    return x;
}

int QuadraticHash::hashFunction(const string & key){
    //cout << "In hash function" << endl;
    unsigned int hashVal = 0;
    for (char ch: key){
        hashVal = 37 * hashVal + ch;
    }
   // cout << "hashVal: " << hashVal << endl;
    //cout << "space: " << space << endl;
    //cout << "hashVal mod space = " << hashVal % space << endl;
    return hashVal % space;
}

void QuadraticHash::insertItem(string x){
    //cout << "In insertItem" << endl;
    int index = findPos(x);
    //cout << "index of: " << x << " is " << index << endl;
    contents[index] = x;
   // cout << "inserted " << x << " at index " << index << endl;
}

int QuadraticHash::findPos(string x){
    //cout << "In findPos" << endl;
    int index = hashFunction(x);
    //cout << " index of " << x << " after hash function is " << index << endl;
    int i = 0;
    while(contents[index] != ""){
        i++;
        index = (index + (i * i));
        //cout << "index of " << x << " while quadratic-ing is " << index << " after i is " << i << endl;
    }
    //cout << "index of " << x << " after quadratic is " << index << endl;
    if (index >= space){
        index = index - space;
    }
    //cout << "index of " << x << " after subtraction is " << index << endl;
    return index;
}

void QuadraticHash::displayHash(){
    for(int i = 0; i < space; i++){
        cout << i << ": " << contents[i] << endl;
    }
}
bool QuadraticHash::findItem(string x){
 //   cout<< "Before seg fault just entered findItem " << x << endl;
    int index = hashFunction(x);
    //cout << endl;
   //cout << "index of " << x << " is " << index << endl;
   //cout << "contents of " << index << " is " << contents[index] << endl;
    if(contents[index] == x){
        return true;
    }
    else{
        int i = 0;
        while(contents[index] != x && contents[index] != ""){
            i++;
            index = (index + (i * i));
            if(index >= space){
                index = index - space;
            }
            if(contents[index] == x){
                return true;
            }
        }
    }
    //else{
        return false;
    //}
}

