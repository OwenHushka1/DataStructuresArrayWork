#include <iostream>
#include <fstream>
#include "../code_1/fundamentals_1.hpp"



#include <string>
#include <cmath>
#include <cassert>


using namespace std;

int main(int argc, char* argv[]) {
    // TODO

    if(argc < 2){// making sure there are the correct number of arguments

        cout << "missing command line arguments" << endl;
        return -1;
    } 

    string filename = argv[1]; //the file name should be the second argument
    string line = "";
    float num;

 

    ifstream file;
    file.open(filename);//opening the file
    float arr[100];  
    int numElements = 0;
    int Elements;
    
    if(file.is_open()){ //make sure the file opens correctly
        while(getline(file, line)){ //loops while there are still lines to read in the file
            num = stof(line);
            Elements = addToArrayAsc(arr, numElements, num);

            if(Elements == -1){ //making sure that the value was added to the array correctly
                cout << "There was an error adding all of the values to the array. There may be more than 100 values in the file" << endl; 
                return -1;}
            else{ //if the value was not added correctly
                numElements = Elements;
            }
            for(int i = 0; i < numElements; i++){ 
                cout << arr[i];
                if(i < (numElements - 1))
                    cout << ",";
            }
            cout << endl;
        }
        file.close();

        return 0;
    }
    else{
        cout << "Failed to open the file." << endl;
        return 0;
    }

}