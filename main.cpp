#include "main.h"

int main(int argc, char *argv[]){
    try{
        if(argc < 3){
            throw std::invalid_argument("Not enough arguments\n");
        }

        string dictFileName = argv[1];
        std::ifstream dictFile(dictFileName);
        if(!dictFile){
            throw std::invalid_argument("Dictionary file not found\n");
        }

        string inputFileName = argv[2];
        std::ifstream inputFile(inputFileName);
        if(!inputFile){
            throw std::invalid_argument("Could not open input file\n");
        }

        string dword;
        int count = 0;
      
        while(dictFile >> dword){
            count++;
        }
        dictFile.close();
        dictFile.open(dictFileName);
        
        auto start1 = std::chrono::steady_clock::now();
        //ChainingHash* hash = new ChainingHash(count);
        ChainingHash hash(count);
        cout << "After creating tables" << endl;
        while(dictFile >> dword){
            for(unsigned i = 0; i < dword.length(); i++){
                if(dword[i] >= 65 && dword[i] <= 90){
                    dword[i] = dword[i] + 32;
                }
            }
            hash.insertItem(dword);
        }
        auto finish1 = std::chrono::steady_clock::now();
        auto ChainingTimeElapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish1-start1);

        auto start2 = std::chrono::steady_clock::now();
       string iword = "";
       int Cmisspelled = 0;
while(inputFile >> iword){
    bool found = false;
            if(hash.findItem(iword)){
                found = true;
            }
            else if (found == false){
                string cleanWord = "";
                string cleanWord2 = "";
                string firststring = "";
                string secondstring = "";
                for(unsigned i = 0; i < iword.length(); i++){
                    if(iword[i] >= 65 && iword[i] <= 90){
                        iword[i] = iword[i] + 32;
                    }

                    if(iword[i] >= 97 && iword[i] <= 122){
                        cleanWord+= iword[i];
                    }
                }
                if(cleanWord != ""){
                    if(hash.findItem(cleanWord)){
                        found = true;
                    }
                        else if (found == false){
                            bool doubledash = false;
                            for(unsigned i = 0; i < iword.length(); i++){ 
                                if(iword[i] == '-' && iword[i+1]=='-'){
                                    firststring = iword.substr(0, i);
                                    secondstring = iword.substr(i+2);
                                    doubledash = true;
                                    break;
                                }
                                else if(iword[i] == '-' && iword[i+1] != '-'){
                                    firststring = iword.substr(0, i);
                                    secondstring = iword.substr(i+1);
                                    doubledash = true;
                                    break;
                                }
                            
                            }
                            if(doubledash){
                                if(firststring != ""){
                                    for(unsigned i = 0; i < firststring.length(); i++){
                                        if(firststring[i] >= 97 && firststring[i] <= 122){
                                            cleanWord += firststring[i];
                                        }
                                    }
                                }
                                if(secondstring!= ""){
                                    for(unsigned i = 0; i < secondstring.length(); i++){
                                        if(secondstring[i] >= 97 && secondstring[i] <= 122){
                                            cleanWord2 += secondstring[i];
                                        }
                                    }
                                }
                                if(cleanWord!=""){
                                    if(hash.findItem(cleanWord)){
                                        found = true;
                                    }
                            }
                                if(cleanWord2!=""){
                                    if(hash.findItem(cleanWord2)){
                                        found = true;
                                    }
                                }
                        }   
                        }
                }

                    }
                if(found == false){
                    Cmisspelled++;
                }
            }
 
        cout << Cmisspelled << " words were misspelled according to chaining hash" << endl;
        auto finish2 = std::chrono::steady_clock::now();
        auto ChainingInputTimeElapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish2-start2);


        //QUADRATIC HASH TABLE
        inputFile.close();
        inputFile.open(inputFileName);
        dictFile.close();
        dictFile.open(dictFileName);

        auto start3 = std::chrono::steady_clock::now();
        //QuadraticHash* hash2 = new QuadraticHash(count);
        QuadraticHash hash2(count);
        dword = "";
        while(dictFile >> dword){
            for(unsigned i = 0; i < dword.length(); i++){
                if(dword[i] >= 65 && dword[i] <= 90){
                    dword[i] = dword[i] + 32;
                }
            }

            hash2.insertItem(dword);
        }
        auto finish3 = std::chrono::steady_clock::now();
        auto QuadraticTimeElapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish3-start3);


        auto start4 = std::chrono::steady_clock::now();
       iword = "";
       int Qmisspelled = 0;
while(inputFile >> iword){
    bool found = false;
            if(hash2.findItem(iword)){
                found = true;
            }
            else if (found == false){
                string cleanWord = "";
                string cleanWord2 = "";
                string firststring = "";
                string secondstring = "";
                for(unsigned i = 0; i < iword.length(); i++){
                    if(iword[i] >= 65 && iword[i] <= 90){
                        iword[i] = iword[i] + 32;
                    }

                    if(iword[i] >= 97 && iword[i] <= 122){
                        cleanWord+= iword[i];
                    }
                }
                if(cleanWord != ""){
                    if(hash2.findItem(cleanWord)){
                        found = true;
                    }
                        else if (found == false){
                            bool doubledash = false;
                            for(unsigned i = 0; i < iword.length(); i++){ 
                                if(iword[i] == '-' && iword[i+1]=='-'){
                                    firststring = iword.substr(0, i);
                                    secondstring = iword.substr(i+2);
                                    doubledash = true;
                                    break;
                                }
                                else if(iword[i] == '-' && iword[i+1] != '-'){
                                    firststring = iword.substr(0, i);
                                    secondstring = iword.substr(i+1);
                                    doubledash = true;
                                    break;
                                }
                            
                            }
                            if(doubledash){
                                if(firststring != ""){
                                    for(unsigned i = 0; i < firststring.length(); i++){
                                        if(firststring[i] >= 97 && firststring[i] <= 122){
                                            cleanWord += firststring[i];
                                        }
                                    }
                                }
                                if(secondstring!= ""){
                                    for(unsigned i = 0; i < secondstring.length(); i++){
                                        if(secondstring[i] >= 97 && secondstring[i] <= 122){
                                            cleanWord2 += secondstring[i];
                                        }
                                    }
                                }
                                if(cleanWord!=""){
                                    if(hash2.findItem(cleanWord)){
                                        found = true;
                                    }
                            }
                                if(cleanWord2!=""){
                                    if(hash2.findItem(cleanWord2)){
                                        found = true;
                                    }
                                }
                        }   
                        }
                }

                    }
                if(found == false){
                    Qmisspelled++;
                }
            }
        auto finish4 = std::chrono::steady_clock::now();
        auto QuadraticInputTimeElapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish4-start4);
        cout << Qmisspelled << " words were misspelled according to quadratic hash" << endl;

        cout << "Time to construct hash table (chaining): " << ChainingTimeElapsed.count() << "ns" << endl;
        cout << "Time taken to perform spell checking (chaining): " << ChainingInputTimeElapsed.count() << "ns" << endl;
        cout << "Time to construct hash table (quadratic): " << QuadraticTimeElapsed.count() << "ns" << endl;
        cout << "Time taken to perform spell checking (quadratic): " << QuadraticInputTimeElapsed.count() << "ns" << endl;
        if(ChainingInputTimeElapsed.count() < QuadraticInputTimeElapsed.count()){
            cout << "Chaining hash table is faster to spell check" << endl;
        }
        else{
            cout << "Quadratic hash table is faster to spell check" << endl;
        }
    }

    catch(std::invalid_argument &e){
        cout << "Invalid argument" << endl;
    }
    catch(...){
        cout << "Error" << endl;
    }
    return 0;
}

