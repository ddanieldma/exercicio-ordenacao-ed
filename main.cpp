#include <iostream>
#include "utils.h"
#include "doubly-linked-list.h"
#include "sortings/bubble_sort.h"
#include "sortings/selection-sort.h"
#include "sortings/insertion-sort.h"
#include "sortings/counting-sort.h"
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
void registraTempo(ofstream &file, Node* head, void (*func)(Node**), bool endLine){
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

Node* criaLista(int iSize, int iOffset, int iRange){
    // Criando nova lista.
    Node* head = nullptr;

    // Setando gerador de números aleatórios com seed dada pelo tempo atual, de forma que cada
    // nova lista é completamente diferente.
    srand((unsigned) time(NULL));
    int iRandom;
    
    for (int j = 0; j < 10000; j++) {
        // Gera número aleatório entre 1 e 100
        iRandom = iOffset + (rand() % (iRange + 1 - iOffset));
        insertEnd(&head, iRandom);
    }   

    return head;
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
    Node* head = criaLista(iSize, iOffset, iRange);
    
    // Operações de arquivo.
    // Criando variável que permite manipulação de arquivos no modo de escrita.
    ofstream file;
    // Criando arquivo.
    file.open("tempos.csv");
    // Colocando cabeçalhos.
    file<<"bs,obs,ss,oss,is"<<endl;

    for (int i = 0; i < iNumberOfLists; i++){
        cout << i + 1 << " sequência de listas." << endl;

        // Bubble Sort.
        head = criaLista(iSize, iOffset, iRange);
        cout << "Ordenando com Bubble Sort" << endl;
        registraTempo(file, head, BubbleSort::bubbleSort, false);

        // Optimized Bubble Sort.
        head = criaLista(iSize, iOffset, iRange);
        cout << "Ordenando com Optimized Bubble Sort" << endl;
        registraTempo(file, head, BubbleSort::optimizedBubbleSort, false);

        // Selection Sort.
        head = criaLista(iSize, iOffset, iRange);
        cout << "Ordenando com Selection Sort" << endl;
        registraTempo(file, head, SelectionSort::selectionSort, false);

        // Optimized Selection Sort.
        head = criaLista(iSize, iOffset, iRange);
        cout << "Ordenando com Optimized Selection Sort" << endl;
        registraTempo(file, head, SelectionSort::optimizedSelectionSort, false);

        // Insertion Sort.
        head = criaLista(iSize, iOffset, iRange);
        cout << "Ordenando com Insertion Sort" << endl;
        registraTempo(file, head, InsertionSort::insertionSort, true);

        // Couting Sort.
        head = criaLista(iSize, iOffset, iRange);
        cout << "Ordenando com Counting Sort" << endl;
        registraTempo(file, head, CountingSort::countingSort, true);
    }
    
    return 0;
}