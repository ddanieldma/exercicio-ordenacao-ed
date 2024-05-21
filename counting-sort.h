int getGreatestList(Node**);
Node *createListSize(int);
Node* getNodeByIndex(Node**, int);
int ocurrencesElement(Node**, int);
int countElementsList(Node*);
int getListSize(Node**);

// int main(){
//     Node* head = nullptr;

//     insertEnd(&head, 2);
//     insertEnd(&head, 5);
//     insertEnd(&head, 3);
//     insertEnd(&head, 0);
//     insertEnd(&head, 2);
//     insertEnd(&head, 3);
//     insertEnd(&head, 0);
//     insertEnd(&head, 3);

//     cout << "Lista sem ordenação: " << endl;
//     displayList(head);

//     countingSort(&head);

//     cout << "Lista ordenada: " << endl;
//     displayList(head);

//     return 0;
// }

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
    // Pegando o maior elemento na lista.
    int iGreatest = getGreatestList(head);

    // Criando lista de contagem de tamanho <maior elemento> + 1
    Node *countList = createListSize(iGreatest + 1);

    // Setando count list
    for (int i = 0; i < (iGreatest + 1); i++){
        // Na lista de contagem, cada posição/índice armazena o número de ocorrências
        // na lista de input do número de valor igual àquela posição.

        // Percorreando lista como se fosse um array.
        Node* currentCountNode = getNodeByIndex(&countList, i);
        // Armzenando o número de ocorrências do elemento na lista de input.
        currentCountNode->iPayload = ocurrencesElement(head, i);
    }

    Node* current = countList;
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

    // Liberando memória da lista de input e da lista de contagem temporária.
    deleteList(head);
    deleteList(*countList);

    // Setando a head para a nova lista, agora ordenada.
    *head = outputList;

    return;
}