#include <iostream>

using namespace std;

void iguais(){
    cout << "=====================================" << endl;
}

void swapNodesValues(int& iVal1, int& iVal2){
	int iTemp = iVal1;
	iVal1 = iVal2;
	iVal2 = iTemp;
}