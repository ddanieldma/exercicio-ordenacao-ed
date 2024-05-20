#include <iostream>
#include "doubly-linked-list.h"

using namespace std;

void displayArr(int* arri, int iSize){
    cout << "Payload: ";
    
    for (int i = 0; i < iSize; i++){
        cout << arri[i] << " ";
    }

    cout << endl;
}

int greatestArr(int* arri, int iSize){
    // Greater is the first.
    int iGreatest = arri[0];

    for (int i = 0; i < iSize; i++){
        if(arri[i] > iGreatest)
            iGreatest = arri[i];
    } 

    return iGreatest;
}

int ocurrencesElement(Node** head, int iValue){
    Node* current = *head;
    int iCount = 0;

    while (current != nullptr){
        if (current->iPayload == iValue)
            iCount++;

        current = current->ptrNext;
    }

    return iCount;
}

Node* getNodeByIndex(Node** head, int iIndex){
    if (*head == nullptr){
        cout << "Lista vazia" << endl;

        return nullptr;
    }

    if (iIndex == 0)
        return *head;

    int currentIndex = 0;
    Node* current = *head;

    while(current->ptrNext != nullptr){
        current = current->ptrNext;
        currentIndex++;

        if(currentIndex == iIndex)
            return current;
    }

    cout << "Index inválido" << endl;

    return nullptr;
}

void countingSort(Node** head){
    // 1. Encontra maior elemento no input array.
    // 2. Cria count array.
    
    // 3. Seta count array
    // O index é o número e o valor o número de ocorrências.

    // 4. executa os passos voltando no input array.

    int iGreatest = getGreatestList(head);
    cout << "Maior elemento da lista: " << iGreatest << endl;

    Node *countList = createListSize(iGreatest + 1);

    cout << "Tamanho da nova lista: " << getListSize(&countList) << endl;

    int iElement = 5;
    cout << "Ocorrencias do numero " << iElement << ": " << ocurrencesElement(head, iElement) << endl;

    int iIndex = 2;
    Node* nodeIndex = getNodeByIndex(head, iIndex);
    cout << "Elemento no index " << iIndex << ": " << nodeIndex->iPayload << endl;

    // Setando count list
    for (int i = 0; i < (iGreatest + 1); i++){
        // Percorreando lista como se fosse um array.
        Node* currentCountNode = getNodeByIndex(&countList, i);
        currentCountNode->iPayload = ocurrencesElement(head, i);
    }

    displayList(countList);
    
    Node* current = countList;
    while(current != nullptr){
        // Se estivermos no primerio elemento da lista.
        if(current->ptrPrev == nullptr){
            current = current->ptrNext;
            continue;
        }
        
        current->iPayload = current->iPayload + current->ptrPrev->iPayload;

        // Node* backward = current->ptrPrev;
        // while (backward != nullptr){
        //     current->iPayload = current->iPayload + backward->iPayload;

        //     backward = backward->ptrPrev;
        // }


        current = current->ptrNext;
    }
    // while(current != nullptr){
    //     // Se estivermos no primerio elemento da lista.
    //     if(current->ptrPrev == nullptr){
    //         current = current->ptrNext;
    //         continue;
    //     }

    //     Node* backward = current->ptrPrev;
    //     while (backward != nullptr){
    //         current->iPayload = current->iPayload + backward->iPayload;

    //         backward = backward->ptrPrev;
    //     }


    //     current = current->ptrNext;
    // }

    // Criando lista que será a versão ordenada.
    Node* outputList = createListSize(getListSize(head));

    // Iterando a partir do final da lista inicial.
    current = getLastNode(head);

    while(current != nullptr){
        int iCurrentValue = current->iPayload;
        
        // Índice na lista de saída é o valor na lista de contagem de índice
        // dado pelo valor atual da lista de entrada -1.
        // Variável para fazer operações nas listas com índices.
        Node* indexNode = getNodeByIndex(&countList, iCurrentValue);
        int iIndexOutput = indexNode->iPayload - 1;

        // Colocando valor na lista de saída.
        indexNode = getNodeByIndex(&outputList, iIndexOutput);
        indexNode->iPayload = iCurrentValue;

        // Atualizando lista de contagem.
        indexNode = getNodeByIndex(&countList, iCurrentValue);
        indexNode->iPayload--;

        current = current->ptrPrev;
    }

    *head = outputList;
}


int main(){
    Node* head = nullptr;

    insertEnd(&head, 2);
    insertEnd(&head, 5);
    insertEnd(&head, 3);
    insertEnd(&head, 0);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 0);
    insertEnd(&head, 3);

    cout << "Lista sem ordenação: " << endl;
    displayList(head);

    countingSort(&head);

    cout << "Lista ordenada: " << endl;
    displayList(head);

    return 0;
}