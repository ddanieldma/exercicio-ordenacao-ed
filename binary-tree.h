// #include <iostream>
// #include "queue-bt.h"

// using namespace std;

// // Operações com a árvore.
// NodeTree* createNodeTree(int);
// NodeTree* insertNodeTree(NodeTree*, int);
// NodeTree* lesserLeaf(NodeTree*);
// NodeTree* deleteNodeTree(NodeTree*, int);

// // Visitando a árvore.
// // Algorítmos DFS.
// // In Order: esquerda->raíz->direita.
// void inOrderTraverse(NodeTree* root);
// // Pre Order: raíz->esquerda->direita.
// void preOrderTraverse(NodeTree* root);
// // Post Order: esquerda->direita->raíz.
// void postOrderTraverse(NodeTree* root);
// // Algorítmo BFS.
// void bfsTraverse(NodeTree* root);


// // int main(){
// //     NodeTree* root = nullptr;
    
// //     root = insertNodeTree(root, 3);
// //     root = insertNodeTree(root, 1);
// //     root = insertNodeTree(root, 5);
// //     root = insertNodeTree(root, 7);
// //     root = insertNodeTree(root, 6);
// //     root = insertNodeTree(root, 42);
// //     root = insertNodeTree(root, 13);

// //     cout << "Percorrendo in order" << endl;
// //     inOrderTraverse(root);
// //     cout << endl;

// //     cout << "Percorrendo pre order" << endl;
// //     preOrderTraverse(root);
// //     cout << endl;

// //     cout << "Percorrendo post order" << endl;
// //     postOrderTraverse(root);
// //     cout << endl;
    
// //     cout << "Percorrendo bfs" << endl;
// //     bfsTraverse(root);
// //     cout << endl;

// //     return 0;
// // }


// NodeTree* createNodeTree(int iValue){
//     /*Cria nó da árvore binária.*/

//     // Alocando memória.
//     NodeTree* newNodeTree = (NodeTree*) malloc(sizeof(NodeTree));

//     if (newNodeTree != nullptr){
//         // Inicializando nó.
//         newNodeTree->iPayload = iValue;
//         newNodeTree->ptrLeft = nullptr;
//         newNodeTree->ptrRight = nullptr;
//     }

//     return newNodeTree;
// }

// NodeTree* insertNodeTree(NodeTree* startingNodeTree, int iValue){
//     /*Insere um nó na árvore binária.*/

//     // Se a árvore(ou subárvore) estiver vazia criamos a raíz.
//     if(startingNodeTree == nullptr){
//         return createNodeTree(iValue);
//     }

//     // Percorrendo a árvore de maneira recursiva para inserir o novo valor no 
//     // lugar certo.
//     if(iValue < startingNodeTree->iPayload){
//         startingNodeTree->ptrLeft = insertNodeTree(startingNodeTree->ptrLeft, iValue);
//     }
//     else{
//         startingNodeTree->ptrRight = insertNodeTree(startingNodeTree->ptrRight, iValue);
//     }

//     return startingNodeTree;
// }

// NodeTree* lesserLeaf(NodeTree* root){
//     /*Retorna o menor nó da árvore/subárvore.*/

//     if(root == nullptr) return nullptr;

//     NodeTree* current = root;

//     while(current && current->ptrLeft != nullptr) current = current->ptrLeft;

//     return current;
// }

// NodeTree* deleteNodeTree(NodeTree* root, int iValue){
//     /*Deleta um nó da árvore de acordo com seu valor.*/

//     // Árvore vazia.
//     if(root == nullptr) return nullptr;
    
//     // Indo para a direita.
//     if (iValue < root->iPayload) root->ptrLeft = deleteNodeTree(root->ptrLeft, iValue);
//     // Ou para esquerda
//     else if (iValue > root->iPayload) root->ptrRight = deleteNodeTree(root->ptrRight, iValue);
//     // Se tivermos encontrado o nó que queremos retirar.
//     else{
//         NodeTree* ptrTemp = nullptr;

//         // Se não tivermos o nó da esquerda.
//         if(root->ptrLeft == nullptr){
//             // Deletamos o nó em que estamos e retornamos o nó filho da direita
//             // para que este fique em seu lugar.
//             ptrTemp = root->ptrRight;
//             free(root);
//             return ptrTemp;
//         }
//         // De maneira semelhante se não tivermos o nó da esquerda.
//         else if(root->ptrRight == nullptr){
//             ptrTemp = root->ptrLeft;
//             free(root);
//             return ptrTemp;
//         }

//         // Se tivermos os dois nós filhos, colocamos o menor nó da subárvore
//         // da direita (o menor dos maiores) para ser o novo pai, depois deletamos
//         // esse menor nó na sua antiga posição.

//         // Encontrando menor nó da subárvore da direita.
//         ptrTemp = lesserLeaf(root->ptrRight);
//         // Colocando-o como novo nó pai.
//         root->iPayload = ptrTemp->iPayload;
//         // Deletando esse menor nó.
//         root->ptrRight = deleteNodeTree(root->ptrRight, ptrTemp->iPayload);
//     }

//     return root;
// }

// NodeTree* getNodeInOrder(NodeTree* root, int iValue){
//     /*Procura por um nó seguindo a travessia In Order.*/

//     if(root != nullptr){
//         // Printando a raíz
//         if(iValue == root->iPayload) return root;
        
//         // Indo primeiro para a esquerda.
//         inOrderTraverse(root->ptrLeft);

//         // Indo para a direita.
//         inOrderTraverse(root->ptrRight);
//     }

//     // return nullptr;
// }

// void inOrderTraverse(NodeTree* root){
//     /*Percorre a árvore na forma In Order Traverse*/

//     // Tomando cuidado para não tentar buscar o valor de um nó que não existe.
//     if(root != nullptr){
//         // Indo primeiro para a esquerda.
//         inOrderTraverse(root->ptrLeft);
        
//         // Printando a raíz
//         cout << root->iPayload << " ";

//         // Indo para a esquerda.
//         inOrderTraverse(root->ptrRight);
//     }
// }

// void preOrderTraverse(NodeTree* root){
//     /*Percorre a árvore na forma Pre Order Traverse*/
    
//     // Tomando cuidado para não tentar buscar o valor de um nó que não existe.
//     if(root != nullptr){
//         // Printando primeiro a raíz
//         cout << root->iPayload << " ";
        
//         // Indo para a esquerda.
//         inOrderTraverse(root->ptrLeft);

//         // E por fim para a direita.
//         inOrderTraverse(root->ptrRight);
//     }
// }

// void postOrderTraverse(NodeTree* root){
//     /*Percorre a árvore na forma Post Order Traverse*/

//     // Tomando cuidado para não tentar buscar o valor de um nó que não existe.
//     if(root != nullptr){
//         // Indo primeiro para a esquerda.
//         inOrderTraverse(root->ptrLeft);
//         // Indo para a direita.
//         inOrderTraverse(root->ptrRight);

//         // Por fim printando a raíz.
//         cout << root->iPayload << " ";
//     }
// }

// void bfsTraverse(NodeTree* root){
//     /*Percorre árvore na forma Breadth First.*/

//     // Criando fila para armzenar os nós que serão visitados.
//     Queue* queue = createQueue();

//     // Adicionando primeiro nó.
//     enQueue(queue, root);
    
//     while(!emptyQueue(queue)){
//         // Removendo um nó da fila, printando e adicionando seus filhos à fila.
//         NodeTree* current = deQueue(queue);
//         cout << current->iPayload << " ";
//         if(current->ptrLeft != nullptr) enQueue(queue, current->ptrLeft);
//         if(current->ptrRight != nullptr) enQueue(queue, current->ptrRight);
//     }

//     return;
// }