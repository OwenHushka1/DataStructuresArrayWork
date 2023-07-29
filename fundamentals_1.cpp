#include "fundamentals_1.hpp"

int addToArrayAsc(float sortedArray[], int numElements, float newValue) {
    // TODO
    if(numElements >= 100){ //if there are as many elements or more than the array can hold
        cout << "The array is full" << endl;
        return -1;
    }

    if(numElements == 0){  //if there are no elements in the array, add the value to the first position
        sortedArray[0] = newValue;
        numElements++;
        return numElements;
    }


    int ind = -1;
    for(int i = 0; i < numElements; i++){//loop through the array
        if(sortedArray[i] >= newValue){ //if the new value is the next smallest value in the array
            ind = i;
            break;            
        }

    }
    if(ind != -1){
        for(int j = numElements; j >= ind; j--){
            sortedArray[j] = sortedArray[j-1]; //shift all of the values in the array over
        }
    }

    if(ind == -1){
        ind = numElements;
    }

    sortedArray[ind] = newValue;//if the new element is larger than any values in the array, add it to the end of the array
    numElements++;

    return numElements;//return the new number of elements in the array
}

