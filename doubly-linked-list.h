#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Estrutura de nó da lista duplamente encadeada.
template<typename T>
struct Node {
    T iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

template<typename T>
Node<T>* createNode(T);

template<typename T>
bool emptyList(Node<T>**);

template<typename T>
void insertFront(Node<T>**, T);

template<typename T>
Node<T>* getLastNode(Node<T>**);

template<typename T>
void insertEnd(Node<T>**, T);

template<typename T>
void displayList(Node<T>*);

template<typename T>
void insertAfter(Node<T>*, T);

template<typename T>
void deleteNode(Node<T>**, Node<T>*);

template<typename T>
void insertBefore(Node<T>**, Node<T>*, T);

template<typename T>
Node<T>* searchNodeByValue(Node<T>**, T);

template<typename T>
void deleteNodeByValue(Node<T>**, T);

template<typename T>
void deleteList(Node<T>**);

template<typename T>
Node<T>* createNode(T iPayload) {
    // Cria e inicializa um nó.
    Node<T>* temp = new Node<T>();
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

template<typename T>
bool emptyList(Node<T>** head) {
    if (*head == nullptr) {
        cout << "Lista vazia" << endl;
        return true;
    }
    return false;
}

template<typename T>
void displayList(Node<T>* node) {
    // Exibe todos os elementos da lista.
    // Se o nó passado é apenas um ponteiro nulo.
    if (node == nullptr) {
        cout << "Lista vazia" << endl;
        return;
    }
    // Se o nó anterior não foi o nullptr (apenas no começo da lista).
    if (node->ptrPrev != nullptr) {
        cout << "Meio ou Fim da Lista" << endl;
        return;
    }
    Node<T>* temp = node;
    cout << "Payload: ";
    while (temp != nullptr) {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    cout << endl;
}

template<typename T>
void insertFront(Node<T>** head, T iPayload) {
    // Insere novo valor no começo da lista.
    Node<T>* newNode = createNode(iPayload);
    // Se a lista já tiver algum elemento.
    if ((*head) != nullptr) {
        newNode->ptrNext = (*head);
        newNode->ptrNext->ptrPrev = newNode;
        (*head) = newNode;
    } else {
        // Se não, newNode passa a ser nosso único elemento.
        (*head) = newNode;
    }
    return;
}

template<typename T>
Node<T>* getLastNode(Node<T>** head) {
    if (emptyList(head)) {
        return nullptr;
    }
    Node<T>* last = *head;
    while (last->ptrNext != nullptr)
        last = last->ptrNext;
    return last;
}

template<typename T>
void insertEnd(Node<T>** head, T iPayload) {
    Node<T>* newNode = createNode(iPayload);
    if (*head == nullptr) {
        (*head) = newNode;
        return;
    }
    Node<T>* last = getLastNode(head);
    newNode->ptrPrev = last;
    last->ptrNext = newNode;
}

template<typename T>
void insertAfter(Node<T>* ptrLocation, T iPayload) {
    // Insere um nó com o valor recebido após um nó determinado.
    if (ptrLocation == nullptr) {
        cout << "Location é NULL" << endl;
        return;
    }
    Node<T>* newNode = createNode(iPayload);
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

template<typename T>
void deleteNode(Node<T>** head, Node<T>* ptrDelete) {
    // Deleta um nó dado head da lista e o nó que deve ser deletado.
    if (head == nullptr || ptrDelete == nullptr) {
        cout << "Não é possível fazer a operação de deleção." << endl;
        return;
    }
    cout << "Deletando valor: " << ptrDelete->iPayload << endl;
    // Se formos deletar o primeiro elemento.
    if (ptrDelete == (*head)) {
        (*head)->ptrNext->ptrPrev = nullptr;
        (*head) = (*head)->ptrNext;
        delete ptrDelete;
    } else if (ptrDelete->ptrNext != nullptr) {
        // Se o elemento estiver no meio.
        // Nós em volta do nó que será deletado apontam um para o outro.
        ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
        ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
        delete ptrDelete;
    } else {
        // Se o elemento estiver no final.
        ptrDelete->ptrPrev->ptrNext = nullptr;
        delete ptrDelete;
    }
    return;
}

template<typename T>
void insertBefore(Node<T>** head, Node<T>* ptrLocation, T iPayload) {
    // Insere um nó com o valor recebido antes de um nó determinado.
    if (ptrLocation == nullptr) {
        cout << "ptrLocation é NULL" << endl;
        return;
    }
    if ((*head) == nullptr) {
        cout << "Lista vazia" << endl;
        return;
    }
    Node<T>* newNode = createNode(iPayload);
    // Se o ptrPrev do ptrLocation for nullptr estamos na head da lista.
    if (ptrLocation->ptrPrev == nullptr) {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    // Corrigir nó a ser inserido.
    newNode->ptrNext = ptrLocation;
    newNode->ptrPrev = ptrLocation->ptrPrev;
    // Corrigir ponto de inserção.
    ptrLocation->ptrPrev = newNode;
    // Corrigir nó antes.
    newNode->ptrPrev->ptrNext = newNode;
    return;
}

template<typename T>
Node<T>* searchNodeByValue(Node<T>** head, T iValue) {
    // Procura um nó na lista pelo valor nele contido e o retorna.
    if ((*head) == nullptr) {
        cout << "Lista vazia." << endl;
        return nullptr;
    }
    Node<T>* temp = (*head);
    while (temp != nullptr) {
        if (temp->iPayload == iValue)
            return temp;
        temp = temp->ptrNext;
    }
    cout << "Valor não encontrado." << endl;
    return nullptr;
}

template<typename T>
void deleteNodeByValue(Node<T>** head, T iValue) {
    // Deleta um nó da lista pelo valor nele contido.
    // Não precisamos nos preocupar com as verificações e casos especiais
    // porque as funções de pesquisa pelo valor e de deletar um nó já
    // o fazem.
    Node<T>* search = searchNodeByValue(head, iValue);
    deleteNode(head, search);
    return;
}

template<typename T>
void deleteList(Node<T>** head) {
    if (emptyList(head)) {
        return;
    }
    // Ponteiro que terá memória liberada à cada iteração.
    Node<T>* temp = nullptr;
    // Ponteiro que vai andar "na frente" pela lista.
    Node<T>* current = *head;
    while (current != nullptr) {
        temp = current;
        current = current->ptrNext;
        delete temp;
    }
    return;
}