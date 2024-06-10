#include <iostream>
#include "utils.h"
#include "doubly-linked-list.h"
#include "sortings/bubble_sort.h"
#include "sortings/selection-sort.h"
#include "sortings/insertion-sort.h"
#include "sortings/counting-sort.h"
#include "queue-bt.h"
#include <chrono>
#include <time.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

// Transformando processo de medir tempo em função.
// Aqui será utilizado um ponteiro para função para que possamos usar qualquer
// método de ordenação e registrar seu tempo.

template <typename T>
void registraTempo(ofstream &file, Node<T>* head, void (*func)(Node<T>**), bool endLine){
    // Calcula o tempo gasto pelo algorítmo de ordenação, imprime no terminal
    // e armazena esse tempo no arquivo especificado.

    auto timeStart = high_resolution_clock::now();
    // Chamando função de ordenação da DLL.
    func(&head);
    auto timeEnd = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(timeEnd - timeStart);
    int iCountTimeTaken = timeTaken.count();

    // Colocando tempo de execução no csv.
    if (endLine)
        file << iCountTimeTaken << endl;
    else
        file << iCountTimeTaken << ",";
    
    cout << "Tempo de execucao: " << iCountTimeTaken << " nanossegundos." << endl;

    return;
}

template <typename T>
void registraTempoArvore(ofstream &file, int size, int offset, int range, bool endLine){
    // Calcula o tempo gasto para criar a árvore binária e armazena no arquivo especificado.

    auto timeStart = high_resolution_clock::now();
    NodeTree<T>* root = createNodeTree<T>(size, offset, range);
    auto timeEnd = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(timeEnd - timeStart);
    int iCountTimeTaken = timeTaken.count();

    // Colocando tempo de execução no csv.
    file << iCountTimeTaken << ",";
    
    cout << "Tempo de criação da árvore: " << iCountTimeTaken << " nanossegundos." << endl;

    return;
}

template <typename T>
Node<T>* criaLista(int iSize, int iOffset, int iRange){
    // Criando nova lista.
    Node<T>* head = nullptr;

    // Setando gerador de números aleatórios com seed dada pelo tempo atual, de forma que cada
    // nova lista é completamente diferente.
    srand((unsigned) time(NULL));
    T iRandom;
    
    for (int j = 0; j < iSize; j++) {
        // Gera número aleatório entre iOffset e iRange
        iRandom = iOffset + (rand() % (iRange + 1 - iOffset));
        insertEnd(&head, iRandom);
    }   

    return head;
}

template <typename T>
void registraTempoLista(ofstream &file, int size, int offset, int range, bool endLine){
    // Calcula o tempo gasto para criar a lista duplamente ligada e armazena no arquivo especificado.

    auto timeStart = high_resolution_clock::now();
    Node<T>* head = criaLista<T>(size, offset, range);
    auto timeEnd = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(timeEnd - timeStart);
    int iCountTimeTaken = timeTaken.count();

    // Colocando tempo de execução no csv.
    if (endLine)
        file << iCountTimeTaken << endl;
    else
        file << iCountTimeTaken << ",";
    
    cout << "Tempo de criação da lista: " << iCountTimeTaken << " nanossegundos." << endl;

    return;
}

// Função para registrar o tempo das travessias
template <typename T>
void registraTempoTravessia(ofstream &file, NodeTree<T>* root, void (*func)(NodeTree<T>*), const string &name, bool endLine) {
    auto timeStart = high_resolution_clock::now();
    func(root);
    auto timeEnd = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(timeEnd - timeStart);
    int iCountTimeTaken = timeTaken.count();

    if (endLine)
        file << iCountTimeTaken << endl;
    else
        file << iCountTimeTaken << ",";

    cout << "Tempo de execução da " << name << ": " << iCountTimeTaken << " nanossegundos." << endl;
}

int main(){
    // Criar 100 listas com 10.000 elementos e ordená-las usando cada um dos algorítmos.
    
    // Declarando variáveis antes para melhoria de desempenho.
    auto timeStart = high_resolution_clock::now();
    auto timeEnd = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(timeEnd - timeStart);

    // Configurações das listas
    int iSize = 10000;
    int iOffset = 1;
    int iRange = 100;
    int iNumberOfLists = 100;

    // Ponteiro que conterá as listas.
    Node<int>* head = criaLista<int>(iSize, iOffset, iRange);
    
    // Operações de arquivo.
    // Criando variável que permite manipulação de arquivos no modo de escrita.
    // ofstream file1;
    // // Criando arquivo.
    // file1.open("tempos.csv");
    // if (!file1) {
    //     cerr << "Erro ao abrir o arquivo tempos.csv" << endl;
    //     return 1;
    // }
    // // Colocando cabeçalhos.
    // file1 << "bs,obs,ss,oss,is,cs,cl,ca" << endl;

    // for (int i = 0; i < iNumberOfLists; i++){
    //     cout << i + 1 << " sequência de listas." << endl;

    //     // Bubble Sort.
    //     head = criaLista<int>(iSize, iOffset, iRange);
    //     cout << "Ordenando com Bubble Sort" << endl;
    //     registraTempo(file1, head, BubbleSort::bubbleSort<int>, false);

    //     // Optimized Bubble Sort.
    //     head = criaLista<int>(iSize, iOffset, iRange);
    //     cout << "Ordenando com Optimized Bubble Sort" << endl;
    //     registraTempo(file1, head, BubbleSort::optimizedBubbleSort<int>, false);

    //     // Selection Sort.
    //     head = criaLista<int>(iSize, iOffset, iRange);
    //     cout << "Ordenando com Selection Sort" << endl;
    //     registraTempo(file1, head, SelectionSort::selectionSort<int>, false);

    //     // Optimized Selection Sort.
    //     head = criaLista<int>(iSize, iOffset, iRange);
    //     cout << "Ordenando com Optimized Selection Sort" << endl;
    //     registraTempo(file1, head, SelectionSort::optimizedSelectionSort<int>, false);

    //     // Insertion Sort.
    //     head = criaLista<int>(iSize, iOffset, iRange);
    //     cout << "Ordenando com Insertion Sort" << endl;
    //     registraTempo(file1, head, InsertionSort::insertionSort<int>, false);

    //     // Counting Sort.
    //     head = criaLista<int>(iSize, iOffset, iRange);
    //     cout << "Ordenando com Counting Sort" << endl;
    //     registraTempo(file1, head, CountingSort::countingSort<int>, true);
    // }

    // // Fechar o primeiro arquivo
    // file1.close();

    // Criar o segundo arquivo
    ofstream file2;
    file2.open("tempos_comparacao.csv");
    if (!file2) {
        cerr << "Erro ao abrir o arquivo tempos_comparacao.csv" << endl;
        return 1;
    }
    
    file2 << "criacao_arvore,criacao_lista,in_order,pre_order,post_order,bfs" << endl;

    for (int i = 0; i < iNumberOfLists; i++) {
        cout << i + 1 << " sequência de comparações." << endl;

        // Medindo o tempo de criação da árvore binária.
        NodeTree<int>* root = createNodeTree<int>(iSize, iOffset, iRange);
        registraTempoArvore<int>(file2, iSize, iOffset, iRange, false);

        // Medindo o tempo de criação da lista duplamente ligada.
        registraTempoLista<int>(file2, iSize, iOffset, iRange, false);

        // Medindo o tempo das travessias
        cout << "Medindo travessias In Order" << endl;
        registraTempoTravessia(file2, root, inOrderTraverse<int>, "In Order Traverse", false);

        cout << "Medindo travessias Pre Order" << endl;
        registraTempoTravessia(file2, root, preOrderTraverse<int>, "Pre Order Traverse", false);

        cout << "Medindo travessias Post Order" << endl;
        registraTempoTravessia(file2, root, postOrderTraverse<int>, "Post Order Traverse", false);

        cout << "Medindo travessia BFS" << endl;
        registraTempoTravessia(file2, root, bfsTraverse<int>, "BFS", true);
    }

    file2.close();

    return 0;
}