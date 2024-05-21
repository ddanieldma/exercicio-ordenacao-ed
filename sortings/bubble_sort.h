namespace BubbleSort
{
    template <typename T>
    void swapNodes(Node<T> **, Node<T> *, Node<T> *);

    template <typename T>
    void optimizedBubbleSort(Node<T> **);

    template <typename T>
    void bubbleSort(Node<T> **);

    template <typename T>
    void swapNodes(Node<T> **head, Node<T> *node1, Node<T> *node2) {
        if (node1 == node2) return;

        if (node1->ptrNext == node2) // caso onde os nós estão adjacentes
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
            Node<T> *tempNext = node1->ptrNext;
            Node<T> *tempPrev = node1->ptrPrev;

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

    template <typename T>
    void optimizedBubbleSort(Node<T> **head) 
    {
        if (*head == nullptr){
            return;
        }

        Node<T> *end = nullptr; 
        bool swapped;

        do {
            swapped = false;
            Node<T> *current = *head;
            Node<T> *previous = nullptr; 

            while (current->ptrNext != end) {
                Node<T> *next = current->ptrNext;
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

    template <typename T>
    void bubbleSort(Node<T> **head)
    {
        if (*head == nullptr){
            return;
        }

        bool swapped;
        Node<T> *temp1 = nullptr;
        Node<T> *temp2 = nullptr;

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
}