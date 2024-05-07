#include <iostream>
#include "doubly-linked-list.h"


using namespace std;


void swapNodes(Node **head, Node *node1, Node *node2) {
    if (node1 == node2) return;

    if (node1->ptrNext == node2) //caso onde os nós estão adjacentes
    {
        node1->ptrNext = node2->ptrNext;

        if (node2->ptrNext != nullptr) 
            node2->ptrNext->ptrPrev = node1;
        
        node2->ptrPrev = node1->ptrPrev;

        if (node1->ptrPrev != nullptr) 
            node1->ptrPrev->ptrNext = node2;

        node2->ptrNext = node1;
        node1->ptrPrev = node2;
    } 
    else 
    { 
        Node *tempNext = node1->ptrNext;
        Node *tempPrev = node1->ptrPrev;

        node1->ptrNext = node2->ptrNext;

        if (node2->ptrNext != nullptr) 
            node2->ptrNext->ptrPrev = node1;

        node1->ptrPrev = node2->ptrPrev;

        if (node2->ptrPrev != nullptr) 
            node2->ptrPrev->ptrNext = node1;

        node2->ptrNext = tempNext;

        if (tempNext != nullptr) 
            tempNext->ptrPrev = node2;

        node2->ptrPrev = tempPrev;

        if (tempPrev != nullptr)
             tempPrev->ptrNext = node2;
    }

    // ajustando o head da lista se necessário
    if (*head == node1) *head = node2;
    else if (*head == node2) *head = node1;
}

void swapArray(int& iVal1, int& iVal2){
    int iTemp = iVal1;
    iVal1 = iVal2;
    iVal2 = iTemp;
}

void selectionSort(Node** head){
    if(*head == nullptr){
        cout << "Lista vazia" << endl;
        
        return;
    }
    
    bool bSwapped;
    Node* temp1 = nullptr;
    Node* temp2 = nullptr;

    do {
        bSwapped = false;
        temp1 = *head;

        while(temp1->ptrNext != nullptr){
            
        }
    } while(bSwapped)

    for(int outerLoop = 0; outerLoop < iSize; outerLoop++){
        for (int innerLoop = outerLoop; innerLoop < iSize; innerLoop++){
            if(iArray[innerLoop] < iArray[outerLoop]){
                swapArray(iArray[outerLoop], iArray[innerLoop]);
            }
        }
    }
}

void bubbleSort(Node **head)
{
    if (*head == nullptr){
        cout << "Lista vazia" << endl;

        return;
    }

    bool swapped;
    Node *temp1 = nullptr;
    Node *temp2 = nullptr;

    do {
        swapped = false;
        temp1 = *head;

        while (temp1->ptrNext != nullptr) {
            temp2 = temp1->ptrNext;
            if (temp1->iPayload > temp2->iPayload) {
                swapNodes(head, temp1, temp2);
                swapped = true;
            }
            temp1 = temp2;
        }
    } while (swapped);
}

void selectionSort(int iArray[], int iSize){
    for(int outerLoop = 0; outerLoop < iSize; outerLoop++){
        for (int innerLoop = outerLoop; innerLoop < iSize; innerLoop++){
            if(iArray[innerLoop] < iArray[outerLoop]){
                swapArray(iArray[outerLoop], iArray[innerLoop]);
            }
        }
    }
}

void optimizedSelectionSort(int iArray[], int iSize){
    int min_index;
    
    for(int outerLoop = 0; outerLoop < iSize; outerLoop++){
        min_index = outerLoop;

        for (int innerLoop = outerLoop; innerLoop < iSize; innerLoop++){
            if(iArray[innerLoop] < iArray[outerLoop]){
                min_index = innerLoop;
            }   
        }

        swapArray(iArray[outerLoop], iArray[min_index]);
    }
}


void displayArray(int iArray[], int iSize){
    cout << "Payload: ";
    for (int i = 0; i < iSize; i++){
        cout << iArray[i] << " ";
    }
    cout << endl;
}

int main(){
    int iArray[] = {42, 13, 666, 7};
    int iSize = sizeof(iArray)/sizeof(iArray[0]);

    displayArray(iArray, iSize);

    selectionSort(iArray, iSize);

    displayArray(iArray, iSize);

    int iArrayDois[] = {42, 13, 666, 7};

    displayArray(iArrayDois, iSize);

    selectionSort(iArrayDois, iSize);

    displayArray(iArrayDois, iSize);

    return 0;
}
