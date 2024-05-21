namespace InsertionSort
{
    void insertInList(Node**, Node*, Node*, int);
    void insertionSort(Node**);

    void insertInList(Node** head, Node* destination, Node* origin, int iValue){
        if (*head == nullptr){
            cout << "Lista vazia" << endl;

            return;
        }
        
        // Essa implementação só funciona com lista duplamente encadeada.
        Node* current = origin;
        for(current; current != destination; current = current->ptrPrev){
            current->iPayload = current->ptrPrev->iPayload;
        }

        destination->iPayload = iValue;

        return;
    }

    void insertionSort(Node** head){
        if(*head == nullptr){
            cout << "Lista vazia" << endl;
            
            return;
        }
        
        Node* outerLoop = nullptr;
        Node* innerLoop = nullptr;

        for (outerLoop = *head; outerLoop != nullptr; outerLoop = outerLoop->ptrNext){
            for (innerLoop = *head; innerLoop != outerLoop; innerLoop = innerLoop->ptrNext){
                if(outerLoop->iPayload < innerLoop->iPayload){
                    insertInList(head, innerLoop, outerLoop, outerLoop->iPayload);
                }
            }
        }
    }
}