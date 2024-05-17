#include <iostream>

using namespace std;

void displayArray(int*, int);
void insertionSort(int*, int);


int main(){
    int iarr[] = {13, 1, 666, 42, 2};
    int iArrSize = sizeof(iarr)/sizeof(iarr[0]);
    
    displayArray(iarr, iArrSize);

    return 0;
}


void displayArray(int* iarr, int iSize){
    cout << "Elementos do array: ";
    
    for (int i = 0; i < iSize; i++){
        cout << iarr[i] << " ";
    }

    cout << endl;
}

void insertionSort(int* , int iSize){
    for (int outerLoop = 0; outerLoop < iSize; outerLoop++){

    }
}
