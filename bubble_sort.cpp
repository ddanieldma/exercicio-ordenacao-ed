#include "doubly-linked-list.h"
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void swapNodes(Node **, Node *, Node *);
void optimizedBubbleSort(Node **);
void bubbleSort(Node **);

int main()
{
    srand(time(NULL));
    Node* head = nullptr;

    // normal
    for (int j = 0; j < 100; j++)
    {
        head = nullptr;

        for (int i = 0; i < 10000; ++i) {
            insertEnd(&head, rand() % 10000); 
        }

        auto timeStart10 = high_resolution_clock::now();
        bubbleSort(&head);
        auto timeStop10 = high_resolution_clock::now();

        auto timeDuration10 = duration_cast<nanoseconds>(timeStop10 - timeStart10);
        cout << "Tempo decorrido: " << timeDuration10.count() << " nanosegundos." << endl;
    }

    // otimizado
    for (int j = 0; j < 100; j++)
    {
        head = nullptr;

        for (int i = 0; i < 10000; ++i) {
            insertEnd(&head, rand() % 10000); 
        }

        auto timeStart10 = high_resolution_clock::now();
        optimizedBubbleSort(&head);
        auto timeStop10 = high_resolution_clock::now();

        auto timeDuration10 = duration_cast<nanoseconds>(timeStop10 - timeStart10);
        cout << "Tempo decorrido: " << timeDuration10.count() << " nanosegundos." << endl;
    }

    return 0;
}; 

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

void optimizedBubbleSort(Node **head) 
{
    if (*head == nullptr){
        return;
    }

    Node *end = nullptr; 
    bool swapped;

    do {
        swapped = false;
        Node *current = *head;
        Node *previous = nullptr; 

        while (current->ptrNext != end) {
            Node *next = current->ptrNext;
            if (current->iPayload > next->iPayload) {
                swapNodes(head, current, next);
                swapped = true;
            }
            previous = current;
            current = next;
        }
        end = current; 
    } while (swapped);
}
void bubbleSort(Node **head)
{
    if (*head == nullptr){
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