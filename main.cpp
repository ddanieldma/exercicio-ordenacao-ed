#include <iostream>
#include "utils.h"
#include "doubly-linked-list.h"
#include "bubble_sort.h"
#include "selection-sort.h"
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


int main(){

    // Criar 10 listas com 10.000 elementos e ordená-las usando cada um dos algorítmos.
    
    int iRandom;
    
    // Declarando variáveis antes para melhoria de desempenho.
    auto timeStart = high_resolution_clock::now();
    auto timeEnd = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(timeEnd - timeStart);
    
    // Operações de arquivo.
    // Criando variável que permite manipulação de arquivos no modo de escrita.
    ofstream file;
    // Criando arquivo.
    file.open("tempos.csv");
    // Colocando cabeçalhos.
    file<<"bs,obs,ss,oss"<<endl;

    for (int i = 0; i < 10; i++){
        // Colocando cabeçalhos.
        
        // Criando nova lista.
        Node* head = nullptr;

        // Setando gerador de números aleatórios com seed dada pelo tempo atual, de forma que cada
        // nova lista é completamente diferente.
        srand((unsigned) time(NULL));

        for (int j = 0; j < 10000; j++){
            // Gerando número aleatório entre 0 e 10000.
            iRandom = rand() % 10000;
            insertEnd(&head, iRandom);
        }

        cout << "Lista " << i + 1 << " criada." << endl;

        // Bubble Sort.
        cout << "Ordenando com Bubble Sort" << endl;
        registraTempo(file, head, &bubbleSort, false);

        // Optimized Bubble Sort.
        cout << "Ordenando com Optimized Bubble Sort" << endl;
        registraTempo(file, head, &optimizedBubbleSort, false);


        // Selection Sort.
        cout << "Ordenando com Selection Sort" << endl;
        registraTempo(file, head, &selectionSort, false);


        // Optimized Selection Sort.
        cout << "Ordenando com Optimized Selection Sort" << endl;
        registraTempo(file, head, &optimizedSelectionSort, true);
    }
    
    return 0;
}