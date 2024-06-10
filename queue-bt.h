#ifndef QUEUE_BT_H
#define QUEUE_BT_H

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
struct NodeTree {
    T iPayload;
    NodeTree* ptrLeft;
    NodeTree* ptrRight;
};

template <typename T>
struct Queue {
    Node<T>* ptrFirst;
};

template <typename T>
Queue<T>* createQueue();

template <typename T>
bool emptyQueue(Queue<T>* queue);

template <typename T>
void enQueue(Queue<T>* const queue, T iValue);

template <typename T>
T deQueue(Queue<T>* queue);

template <typename T>
void showElements(Queue<T>* const queue);

template <typename T>
void deleteQueue(Queue<T>* const queue);

template <typename T>
NodeTree<T>* createNodeTree(T iValue);

template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>*, T);

template <typename T>
NodeTree<T>* lesserLeaf(NodeTree<T>*);

template <typename T>
NodeTree<T>* deleteNodeTree(NodeTree<T>*, T);

template <typename T>
void inOrderTraverse(NodeTree<T>* root);

template <typename T>
void preOrderTraverse(NodeTree<T>* root);

template <typename T>
void postOrderTraverse(NodeTree<T>* root);

template <typename T>
void bfsTraverse(NodeTree<T>* root);

template <typename T>
NodeTree<T>* createNodeTree(int, int, int);

template <typename T>
Queue<T>* createQueue() {
    /*Cria fila.*/
    Queue<T>* temp = new Queue<T>;
    temp->ptrFirst = nullptr;
    return temp;
}

template <typename T>
bool emptyQueue(Queue<T>* queue) {
    /*Diz se a fila está vazia ou não.*/
    return queue->ptrFirst == nullptr;
}

template <typename T>
void enQueue(Queue<T>* const queue, T iValue) {
    /*Adiciona elemento na fila*/
    Node<T>* newElement = createNode(iValue);

    if (emptyQueue(queue)) {
        queue->ptrFirst = newElement;
        return;
    }

    Node<T>* current = queue->ptrFirst;
    while (current->ptrNext != nullptr) current = current->ptrNext;

    current->ptrNext = newElement;
}

template <typename T>
T deQueue(Queue<T>* queue) {
    /*Remove elemento da fila.*/
    if (emptyQueue(queue)) return nullptr;

    Node<T>* deletionNode = queue->ptrFirst;
    T treeNode = deletionNode->iPayload;
    queue->ptrFirst = deletionNode->ptrNext;

    delete deletionNode;
    return treeNode;
}

template <typename T>
void showElements(Queue<T>* const queue) {
    if (emptyQueue(queue)) return;

    cout << "Payload: ";
    Node<T>* current = queue->ptrFirst;
    while (current != nullptr) {
        cout << current->iPayload << " ";
        current = current->ptrNext;
    }
    cout << endl;
}

template <typename T>
void deleteQueue(Queue<T>* const queue) {
    if (emptyQueue(queue)) {
        delete queue;
        return;
    }

    while (!emptyQueue(queue)) deQueue(queue);
    delete queue;
}

// Funções de árvore binária
template <typename T>
NodeTree<T>* createNodeTree(T iValue) {
    /*Cria nó da árvore binária.*/
    NodeTree<T>* newNodeTree = new NodeTree<T>;
    newNodeTree->iPayload = iValue;
    newNodeTree->ptrLeft = nullptr;
    newNodeTree->ptrRight = nullptr;
    return newNodeTree;
}

template <typename T>
NodeTree<T>* insertNodeTree(NodeTree<T>* startingNodeTree, T iValue) {
    /*Insere um nó na árvore binária.*/
    if (startingNodeTree == nullptr) {
        return createNodeTree(iValue);
    }
    if (iValue < startingNodeTree->iPayload) {
        startingNodeTree->ptrLeft = insertNodeTree(startingNodeTree->ptrLeft, iValue);
    } else {
        startingNodeTree->ptrRight = insertNodeTree(startingNodeTree->ptrRight, iValue);
    }
    return startingNodeTree;
}

template <typename T>
NodeTree<T>* lesserLeaf(NodeTree<T>* root) {
    /*Retorna o menor nó da árvore/subárvore.*/
    if (root == nullptr) return nullptr;
    NodeTree<T>* current = root;
    while (current && current->ptrLeft != nullptr) current = current->ptrLeft;
    return current;
}

template <typename T>
NodeTree<T>* deleteNodeTree(NodeTree<T>* root, T iValue) {
    /*Deleta um nó da árvore de acordo com seu valor.*/
    if (root == nullptr) return nullptr;
    if (iValue < root->iPayload) root->ptrLeft = deleteNodeTree(root->ptrLeft, iValue);
    else if (iValue > root->iPayload) root->ptrRight = deleteNodeTree(root->ptrRight, iValue);
    else {
        NodeTree<T>* ptrTemp = nullptr;
        if (root->ptrLeft == nullptr) {
            ptrTemp = root->ptrRight;
            delete root;
            return ptrTemp;
        } else if (root->ptrRight == nullptr) {
            ptrTemp = root->ptrLeft;
            delete root;
            return ptrTemp;
        }
        ptrTemp = lesserLeaf(root->ptrRight);
        root->iPayload = ptrTemp->iPayload;
        root->ptrRight = deleteNodeTree(root->ptrRight, ptrTemp->iPayload);
    }
    return root;
}

template <typename T>
void inOrderTraverse(NodeTree<T>* root) {
    /*Percorre a árvore na forma In Order Traverse*/
    if (root != nullptr) {
        inOrderTraverse(root->ptrLeft);
        cout << root->iPayload << " ";
        inOrderTraverse(root->ptrRight);
    }
}

template <typename T>
void preOrderTraverse(NodeTree<T>* root) {
    /*Percorre a árvore na forma Pre Order Traverse*/
    if (root != nullptr) {
        cout << root->iPayload << " ";
        preOrderTraverse(root->ptrLeft);
        preOrderTraverse(root->ptrRight);
    }
}

template <typename T>
void postOrderTraverse(NodeTree<T>* root) {
    /*Percorre a árvore na forma Post Order Traverse*/
    if (root != nullptr) {
        postOrderTraverse(root->ptrLeft);
        postOrderTraverse(root->ptrRight);
        cout << root->iPayload << " ";
    }
}

template <typename T>
void bfsTraverse(NodeTree<T>* root) {
    /*Percorre árvore na forma Breadth First.*/
    if (root == nullptr) return;
    queue<NodeTree<T>*> q;
    q.push(root);
    while (!q.empty()) {
        NodeTree<T>* current = q.front();
        q.pop();
        cout << current->iPayload << " ";
        if (current->ptrLeft != nullptr) q.push(current->ptrLeft);
        if (current->ptrRight != nullptr) q.push(current->ptrRight);
    }
}

template <typename T>
NodeTree<T>* createNodeTree(int size, int offset, int range) {
    /*Cria uma árvore binária com um número específico de elementos.*/
    NodeTree<T>* root = nullptr;
    srand((unsigned) time(NULL));
    T iRandom;
    
    for (int i = 0; i < size; ++i) {
        iRandom = offset + (rand() % (range + 1 - offset));
        root = insertNodeTree(root, iRandom);
    }
    
    return root;
}

#endif
