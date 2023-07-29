#ifndef READFILE2_H__
#define READFILE2_H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct emissionInfo { 
    string countryName; 
    double emission_in_2015;
    double emission_in_2016; 
    double emission_in_2017;
    double emission_in_2018;
    double emission_in_2019;
    double average; 
};

// TODO add detailed explanation on what the function should do
//function should create a new instance of emissionInfo and add the correct country name and emission information to the instance. It then should add the instance to the co2_emissions array
void insertEmissionInfo(emissionInfo co2_emissions[], string countryName, double emission_in_2015, double emission_in_2016, double emission_in_2017, double emission_in_2018, double emission_in_2019, int length); 

string calcEmissionZone(double average); //function should figure out which clasification the country is (red, orange, yellow, green) based on the average emissions


#endif // READFILE2_H__