#include <iostream>
#include <fstream>
#include "../code_2/fundamentals_2.hpp"
#include <sstream>
#include <string>

using namespace std;


int split(string to_be_split, char separator, string split_apart_storage[], int size_of_array){
    int counter1 = 0;
    int counter2 = 0;
    int length_of_initial_string = to_be_split.length();
    int position_finder = 0;
    
    if(separator < 32 || separator > 255){
        return 1;
    }
    else if(to_be_split == ""){
        return 0;
    }
    else{
        for(int i = 0; i <= length_of_initial_string; i++){
            if(to_be_split[i] == separator || i == length_of_initial_string){
                counter1++;
                split_apart_storage[counter2] = to_be_split.substr(position_finder, i - position_finder);
                position_finder = i+1;
                counter2++;

                if(size_of_array < counter1){
                    return -1;
                }
            } 
        }

        return counter1;
    }   
}

int main(int argc, char* argv[]) {
    // TODO

    if(argc < 5){ //make sure there are the correct number of arguments

        cout << "missing command line arguments" << endl;
        return -1;
    } 

    string splitStorage[6];
    string name;
    double emissions[5];
    emissionInfo arr[119];


    string filename = argv[1];
    string outputFileName = argv[2];
    string line = "";

    ifstream file;
    file.open(filename);

    int ind = -1;
    int numCountries = 0;

    emissionInfo temporary;

        
    if(file.is_open()){ //make sure the file opens correctly
        while(getline(file, line)){ //loops while there are still lines to read in the file
    

            split(line, ',', splitStorage, 6);

            int k = 0;
            for(int i = 1; i < 6; i++){
                emissions[k] = stod(splitStorage[i]);
            }
            

            //insertEmissionInfo(arr, splitStorage[0], emissions[0], emissions[1], emissions[2], emissions[3], emissions[4], numCountries);
            insertEmissionInfo(arr, splitStorage[0], stod(splitStorage[1]), stod(splitStorage[2]), stod(splitStorage[3]), stod(splitStorage[4]), stod(splitStorage[5]), numCountries);
            //cout << splitStorage[0] << splitStorage[1] << splitStorage[2] << endl;

            numCountries++;

        }

           
    file.close();

    }
    else{
        cout << "Failed to open the file." << endl;
        return 0;
    }
        

    ofstream myfile;
    myfile.open(outputFileName);


    for(int k = 0; k < numCountries; k++){
        if(arr[k].average >= stod(argv[3]) && arr[k].average <= stod(argv[4])){
            myfile << arr[k].countryName << "," << arr[k].average  << "," << calcEmissionZone(arr[k].average) << endl;
            cout << arr[k].countryName << "," << arr[k].average  << "," << calcEmissionZone(arr[k].average) << endl;
       }
    }
    myfile.close();

    return 0;
    
    
}