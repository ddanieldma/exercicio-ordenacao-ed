namespace InsertionSort
{
    template <typename T>
    void insertInList(Node<T>**, Node<T>*, Node<T>*, T);

    template <typename T>
    void insertionSort(Node<T>**);

    template <typename T>
    void insertInList(Node<T>**, Node<T>*, Node<T>*, T);

    template <typename T>
    void insertInList(Node<T>** head, Node<T>* destination, Node<T>* origin, T iValue){
        if (*head == nullptr){
            cout << "Lista vazia" << endl;
            return;
        }

        // Essa implementação só funciona com lista duplamente encadeada.
        Node<T>* current = origin;
        for(current; current != destination; current = current->ptrPrev){
            current->iPayload = current->ptrPrev->iPayload;
        }

        destination->iPayload = iValue;
        return;
    }

    template <typename T>
    void insertionSort(Node<T>** head){
        if(*head == nullptr){
            cout << "Lista vazia" << endl;
            return;
        }

        Node<T>* outerLoop = nullptr;
        Node<T>* innerLoop = nullptr;

        for (outerLoop = *head; outerLoop != nullptr; outerLoop = outerLoop->ptrNext){
            for (innerLoop = *head; innerLoop != outerLoop; innerLoop = innerLoop->ptrNext){
                if(outerLoop->iPayload < innerLoop->iPayload){
                    insertInList(head, innerLoop, outerLoop, outerLoop->iPayload);
                }
            }
        }
    }
}