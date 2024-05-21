namespace CountingSort
{
    template <typename T>
    T getGreatestList(Node<T>**);

    template <typename T>
    T getGreatestList(Node<T>**);

    template <typename T>
    Node<T>* createListSize(int);

    template <typename T>
    Node<T>* getNodeByIndex(Node<T>**, int);

    template <typename T>
    int ocurrencesElement(Node<T>**, T);

    template <typename T>
    int getListSize(Node<T>**);

    template <typename T>
    int countElementsList(Node<T>*);

    template <typename T>
    void countingSort(Node<T>**);

    template <typename T>
    T getGreatestList(Node<T>** head){
        if(*head == nullptr){
            cout << "Lista vazia" << endl;
            return -1;
        }

        Node<T>* current = *head;
        T iGreatest = current->iPayload;

        while(current != nullptr){
            if(current->iPayload > iGreatest)
                iGreatest = current->iPayload;

            current = current->ptrNext;
        }

        return iGreatest;
    }
    
    template <typename T>
    Node<T>* createListSize(int iSize){
        // Cria lista do tamanho especificado toda inicializada com 0's.

        Node<T>* head = nullptr;

        for (int i = 0; i < iSize; i++){
            insertEnd(&head, static_cast<T>(0));
        }

        return head;
    }

    template <typename T>
    Node<T>* getNodeByIndex(Node<T>** head, int iIndex){
        if (*head == nullptr){
            cout << "Lista vazia" << endl;

            return nullptr;
        }

        if (iIndex == 0)
            return *head;

        int currentIndex = 0;
        Node<T>* current = *head;

        while(current->ptrNext != nullptr){
            current = current->ptrNext;
            currentIndex++;

            if(currentIndex == iIndex)
                return current;
        }

        cout << "Index inválido" << endl;

        return nullptr;
    }

    template <typename T>
    int ocurrencesElement(Node<T>** head, T iValue){
        Node<T>* current = *head;
        int iCount = 0;

        while (current != nullptr){
            if (current->iPayload == iValue)
                iCount++;

            current = current->ptrNext;
        }

        return iCount;
    }

    template <typename T>
    int getListSize(Node<T>** head){
        Node<T>* current = *head;
        int iCount = 0;

        while(current != nullptr){
            current = current->ptrNext;
            iCount++;
        }

        return iCount;
    }

    template <typename T>
    int countElementsList(Node<T>* node){
        // Se o nó passado é apenas um ponteiro nulo.
        if (node == nullptr){
            cout << "Lista vazia" << endl;
            return 0;
        }

        // Se o nó anterior não foi o nullptr (apenas no começo da lista).
        if (node->ptrPrev != nullptr){
            cout << "Meio ou Fim da Lista" << endl;
            return -1;
        }

        Node<T>* temp = node;
        int iCount = 0;

        while(temp != nullptr){
            iCount++;
            temp = temp->ptrNext;
        }

        return iCount;
    }

    template <typename T>
    void countingSort(Node<T>** head){
        // Pegando o maior elemento na lista.
        T iGreatest = getGreatestList(head);

        // Criando lista de contagem de tamanho <maior elemento> + 1
        Node<T> *countList = createListSize<int>(iGreatest + 1);

        // Setando count list
        for (int i = 0; i < (iGreatest + 1); i++){
            // Na lista de contagem, cada posição/índice armazena o número de ocorrências
            // na lista de input do número de valor igual àquela posição.

            // Percorreando lista como se fosse um array.
            Node<T>* currentCountNode = getNodeByIndex(&countList, i);
            // Armzenando o número de ocorrências do elemento na lista de input.
            currentCountNode->iPayload = ocurrencesElement(head, i);
        }

        Node<T>* current = countList;
        while(current != nullptr){
            // Se estiver no primerio elemento da lista.
            if(current->ptrPrev == nullptr){
                current = current->ptrNext;
                continue;
            }
            
            // O valor de cada nó (com exceção do primeiro) é o valor dele mais o valor
            // do nó anterior
            current->iPayload = current->iPayload + current->ptrPrev->iPayload;

            current = current->ptrNext;
        }

        // Criando lista que será a versão ordenada.
        Node<T>* outputList = createListSize<int>(getListSize(head));

        // Iterando a partir do final da lista inicial.
        current = getLastNode(head);

        while(current != nullptr){
            T iCurrentValue = current->iPayload;
            
            // Índice na lista de saída é o valor na lista de contagem de índice
            // dado pelo valor atual da lista de entrada -1.
            // Variável para fazer operações nas listas com índices.
            Node<T>* indexNode = getNodeByIndex(&countList, iCurrentValue);
            int iIndexOutput = indexNode->iPayload - 1;

            // Colocando valor na lista de saída.
            indexNode = getNodeByIndex(&outputList, iIndexOutput);
            indexNode->iPayload = iCurrentValue;

            // Atualizando lista de contagem.
            indexNode = getNodeByIndex(&countList, iCurrentValue);
            indexNode->iPayload--;

            current = current->ptrPrev;
        }

        // Liberando memória da lista de input e da lista de contagem temporária.
        deleteList(head);
        deleteList(&countList);

        // Setando a head para a nova lista, agora ordenada.
        *head = outputList;

        return;
    }
}