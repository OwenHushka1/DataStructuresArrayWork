#include "fundamentals_2.hpp"

string calcEmissionZone(double avg) {
    // TODO

    if(avg >= 10.0){
        return "RED";  //if the average is in the red zone, return red
    }
    else if(avg < 10 && avg >=5){
        return "ORANGE"; //if the average is in the orange zone, return orange
    }
    else if(avg < 5 && avg >= 2.5){ //if the average is in the yellow zone, return yellow
        return "YELLOW";
    }
    else
        return "GREEN"; //if the average is not in any of the other zones, it must be in the green zone
}

void insertEmissionInfo(emissionInfo co2_emissions[], string countryName, double emission_in_2015, double emission_in_2016, double emission_in_2017, double emission_in_2018, double emission_in_2019, int index) {
    // TODO

    emissionInfo temporary; //create an emissionInfo instance
    double sum = emission_in_2015 + emission_in_2016 + emission_in_2017 + emission_in_2018 + emission_in_2019; 
    temporary.average = sum / 5.0; //find the average
    temporary.countryName = countryName;
    temporary.emission_in_2015 = emission_in_2015;
    temporary.emission_in_2016 = emission_in_2016;
    temporary.emission_in_2017 = emission_in_2017;     //set the country name of temporary and the emission levels
    temporary.emission_in_2018 = emission_in_2018;
    temporary.emission_in_2019 = emission_in_2019;

    co2_emissions[index] = temporary; //add temporary to the co2_emissions array

    return;
}