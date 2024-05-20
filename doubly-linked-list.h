#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


// Estrutura de nó da lista duplamente encadeada.
typedef struct Node{
    int iPayload;
    Node *ptrNext;
    Node *ptrPrev;
} Node;


void iguais();
Node *createNode(int);
void insertFront(Node **, int);
void insertEnd(Node **, int);
void displayList(Node *);
void insertAfter(Node*, int);
void deleteNode(Node**, Node*);
void insertBefore(Node**, Node*, int);
Node *searchNodeByValue(Node**, int);
void DeleteNodeByValue(Node**, int);
int countElementsList(Node*);
int getGreatestList(Node**);
Node *createListSize(Node);


Node *createNode(int iPayload){
    // Cria e inicializa um nó.
    
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

void displayList(Node *node){
    // Exibe todos os elementos da lista.

    // Se o nó passado é apenas um ponteiro nulo.
    if (node == nullptr){
        cout << "Lista vazia" << endl;
        return;
    }

    // Se o nó anterior não foi o nullptr (apenas no começo da lista).
    if (node->ptrPrev != nullptr){
        cout << "Meio ou Fim da Lista" << endl;
        return;
    }

    Node *temp = node;

    cout << "Payload: ";

    while (temp != nullptr){
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertFront(Node** head, int iPayload){
    // Insere novo valor no começo da lista.
    
    Node *newNode = createNode(iPayload);

    // Se a lista já tiver algum elemento.
    if ((*head) != nullptr){
        newNode->ptrNext = (*head);
        newNode->ptrNext->ptrPrev = newNode;
        (*head) = newNode;
    }
    // Se não, newNode passa a ser nosso único elemento.
    else
        (*head) = newNode;

    return;
}

void insertEnd(Node** head, int iPayload){
    Node *newNode = createNode(iPayload);

    if (*head == nullptr){
        (*head) = newNode;
        return;
    }

    Node *temp = (*head);

    while (temp->ptrNext != nullptr)
        temp = temp->ptrNext;

    newNode->ptrPrev = temp; 
    temp->ptrNext = newNode;
}

void insertAfter(Node* ptrLocation, int iPayload){
    // Insere um nó com o valor recebido após um nó determinado.
    
    if (ptrLocation == nullptr){
        cout << "Location é NULL" << endl;
        return;
    }

    Node* newNode = createNode(iPayload);
    // Corrigir nó a ser inserido.
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;

    // Corrigir ponto de inserção.
    ptrLocation->ptrNext = newNode;

    // Corrigir ponto após.
    if (newNode->ptrNext != nullptr)
        newNode->ptrNext->ptrPrev = newNode;

    return;
}

void deleteNode(Node** head, Node*ptrDelete){
    // Deleta um nó dado head da lista e o nó que deve ser deletado.

    if (head == nullptr || ptrDelete == nullptr){
        cout << "Não é possível fazer a operação de deleção." << endl;
        return;
    }

    cout << "Deletando valor: " << ptrDelete->iPayload << endl;

    // Se formos deletar o primeiro elemento.
    if (ptrDelete == (*head)){
        (*head)->ptrNext->ptrPrev = nullptr;
        (*head) = (*head)->ptrNext;

        free(ptrDelete);
    }
    // Se o elemento estiver no meio.
    else if (ptrDelete->ptrNext != nullptr){
        // Nós em volta do nó que será deletado apontam um para o outro.
        ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
        ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

        free(ptrDelete);
    }
    // Se o elemento estiver no final.
    else{
        ptrDelete->ptrPrev->ptrNext = nullptr;

        free(ptrDelete);
    }

    return;
}

void insertBefore(Node** head, Node* ptrLocation, int iPayload){
    // Insere um nó com o valor recebido antes de um nó determinado.
    
    if(ptrLocation == nullptr){
        cout << "ptrLocation é NULL" << endl;

        return;
    }
    if((*head) == nullptr){
        cout << "Lista vazia" << endl;

        return;
    }
    
    Node* newNode = createNode(iPayload);

    // Se o ptrPrev do ptrLocation for nullptr estamos na head da lista.
    if(ptrLocation->ptrPrev == nullptr){
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head)->ptrNext;
        (*head) = newNode;

        return;
    }

    // Corrigir nó a ser inserido.
    newNode->ptrNext = ptrLocation;
    newNode->ptrPrev = ptrLocation->ptrPrev;

    // Corrigir ponto de inserção.
    ptrLocation->ptrPrev = newNode;

    // Corrigr nó antes.
    newNode->ptrPrev->ptrNext = newNode;

    return;
}

Node *searchNodeByValue(Node **head, int iValue){
    // Procura um nó na lista pelo valor nele contido e o retorna. 
    
    if((*head) == nullptr){
        cout << "Lista vazia." << endl;
        return nullptr;
    }

    Node* temp = (*head);

    while(temp != nullptr){
        if(temp->iPayload == iValue)
            return temp;

        temp = temp->ptrNext;
    }

    cout << "Valor não encontrado." << endl;
    return nullptr;
}

void DeleteNodeByValue(Node** head, int iValue){
    // Deleta um nó da lista pelo valor nele contido.

    // Não precisamos nos preocupar com as verificações e casos especiais
    // por que as funções de pesquisa pelo valor e de deletar um nó já 
    // o fazem.

    Node* search = searchNodeByValue(head, iValue);
    deleteNode(head, search);

    return;
}

int countElementsList(Node* node){
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

    Node* temp = node;
    int iCount = 0;

    while(temp != nullptr){
        iCount++;
        temp = temp->ptrNext;
    }

    return iCount;
}

int getGreatestList(Node** head){
    if(*head == nullptr){
        cout << "Lista vazia" << endl;
        return -1;
    }
    
    Node* current = *head;
    int iGreatest = current->iPayload;

    while(current->ptrNext != nullptr){
        if(current->iPayload > iGreatest)
            iGreatest = current->iPayload;

        current = current->ptrNext;
    }

    return iGreatest;
}

Node* createListSize(int iSize){
    // Cria lista do tamanho especificado toda inicializada com 0's.
    
    Node* head = nullptr;

    for (int i = 0; i < iSize; i++){
        insertEnd(&head, 0);
    }

    return head;
}