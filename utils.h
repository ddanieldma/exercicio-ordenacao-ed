#include <iostream>

using namespace std;

void iguais(){
    cout << "=====================================" << endl;
}

template <typename T>
void swapNodesValues(T& iVal1, T& iVal2){
    T iTemp = iVal1;
    iVal1 = iVal2;
    iVal2 = iTemp;
}