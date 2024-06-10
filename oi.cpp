template <typename T>
    Node<T>* searchNodeBFS(Node<T>* root, T iData) {
        if (root == nullptr) return nullptr;

        ListNode<T>* head = nullptr;
        insertEnd(&head, root);
        
        ListNode<T>* QueueFront = head;
        ListNode<T>* QueueRear = head;
        int iQueueFront = 0;

        while (QueueFront != nullptr) {
            Node<T>* currentNode = QueueFront->ptrTreeEquivalent;
            
            if (currentNode->iPayload == iData) {
                return currentNode;
            }

            if (currentNode->ptrLeft != nullptr) {
                insertEnd(&head, currentNode->ptrLeft);
            }

            if (currentNode->ptrRight != nullptr) {
                insertEnd(&head, currentNode->ptrRight);
            }

            QueueFront = QueueFront->ptrNext;
        }

        deleteListNode(&head);

        return nullptr;
    }

// Análise de desempenho.
    // Adicionando 10000 elementos.
    // Procurando 1000 elementos e tomando a média do tempo gasto com cada 
    // um dos métodos pra mesma árvore. Repetindo todo esse processo 10 vezes.

    // int iNumberOfTests = 10;
    // int iNumberOfNodes = 10000;
    // int iOffset = 0;
    // int iRange = 100000;

    // srand((unsigned) time(NULL));
    // int iRandom;