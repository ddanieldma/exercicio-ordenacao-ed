#include <iostream>

using namespace std;

void iguais();
bool invalidArray(int*);
void displayArray(int*, int);
void insertInArray(int*, int, int, int, int);
void insertionSort(int*, int);


int main(){
    int arri[] = {13, 1, 666, 42, 2};
    int iSize = sizeof(arri)/sizeof(arri[0]);
    
    displayArray(arri, iSize);
    iguais();

    insertionSort(arri, iSize);

    displayArray(arri, iSize);
    return 0;
}


void iguais(){
    cout << "======================================" << endl;
}

bool invalidArray(int* arri){
    if (arri = nullptr){
        cout << "Array inválido" << endl;

        return true;
    }

    return false;
}

void displayArray(int* arri, int iSize){
    if (invalidArray(arri))
        return;
    
    cout << "Elementos do array: ";
    
    for (int i = 0; i < iSize; i++){
        cout << arri[i] << " ";
    }

    cout << endl;
}

void insertInArray(int* arri, int iSize, int iDestIndex, int iOrigIndex, int iValue){
    // Insere um elemento no array no index especificado, movendo todos 
    // os outro elementos para frente.
    // 
    
    if(invalidArray(arri))
        return;

    for (int i = iOrigIndex; i > iDestIndex; i--){
        // Move todos os elementos uma posição pra frente.
        arri[i] = arri[i - 1];
    }

    // E insere na posição específca o valor.
    arri[iDestIndex] = iValue;

    return;
}

void insertionSort(int* arri, int iSize){
    // Ordena o array dado usando o algorítmo de Insertion Sort.
    
    if(arri == nullptr)
        return;

    for (int outerLoop = 0; outerLoop < iSize; outerLoop++){
        for (int innerLoop = 0; innerLoop < outerLoop; innerLoop++){
            if (arri[outerLoop] < arri[innerLoop]){
                insertInArray(arri, iSize, innerLoop, outerLoop, arri[outerLoop]);
            }
        }
    }

    return;
}
