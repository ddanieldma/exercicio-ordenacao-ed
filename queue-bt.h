#include<iostream>

using namespace std;

typedef struct NodeTree{
    int iPayload;

    NodeTree* ptrLeft;
    NodeTree* ptrRight;
} NodeTree;

typedef struct Node
{
    NodeTree* iPayload;
    Node* ptrNext;
} Node;

typedef struct Queue
{
	Node* ptrFirst;
}Queue;


Node* createNode(NodeTree*);
Queue* createQueue();
bool emptyQueue(Queue*);
void enQueue(Queue* const, NodeTree*);
NodeTree* deQueue(Queue* queue);
void showElements(Queue* const);
void deleteQueue(Queue* const queue);


Node* createNode(NodeTree* iValue){
	/*Cria nó da fila.*/
	
	// Alocando memória.
	Node* temp = (Node*) malloc(sizeof(Node));
	
	// Inicializando nó.
	temp->iPayload = iValue;
	temp->ptrNext = nullptr;

	return temp;
}

Queue* createQueue(){
	/*Cria fila.*/
	
	// Alocando memória.
	Queue* temp = (Queue*) malloc(sizeof(Queue));
	
	// Inicializando estrutura.
	temp->ptrFirst = nullptr;

	return temp;
}

bool emptyQueue(Queue* queue){
	/*Diz se a fila está vazia ou não.*/
	
	if(queue->ptrFirst == nullptr) return true;

	return false;
}

void enQueue(Queue* const queue, NodeTree* iValue){
	/*Adiciona elemento na fila*/
	
	Node* newElement = createNode(iValue);

	// Se a fila estiver vazia.
	if(emptyQueue(queue)){
		queue->ptrFirst = newElement;

		return;
	}

	// Percorrendo a lista toda.
	Node* current = queue->ptrFirst;
	while(current->ptrNext != nullptr) current = current->ptrNext;

	// Adicionando novo elemento.
	current->ptrNext = newElement;

	return;
}

NodeTree* deQueue(Queue* queue){
	/*Remove elemento da fila.*/
	
	if(emptyQueue(queue)) return nullptr;

	// Vamos deletar o primeiro nó.
	Node* deletionNode = queue->ptrFirst;
	NodeTree* treeNode = deletionNode->iPayload;
	// E setamos o segundo para ser o novo primeiro.
	queue->ptrFirst = deletionNode->ptrNext;

	free(deletionNode);

	return treeNode;
}

void showElements(Queue* const queue){
	if(emptyQueue(queue)) return;
	
	cout << "Payload: ";
	Node* current = queue->ptrFirst;

	while(current != nullptr){
		cout << current->iPayload << " ";

		current = current->ptrNext;
	}
	
	cout << endl;

	return;
}

void deleteQueue(Queue* const queue){
	if(emptyQueue(queue)){
		free(queue);

		return;
	}

	// Removendo elementos até que a fila esteja vazia.
	while(!emptyQueue(queue)) deQueue(queue);

	// Liberando memória da fila.
	free(queue);

	return;
}