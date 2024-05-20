#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void countingSort(Node **);

int main() {
    int arri[10] = {3, 4, 2, 5, 6, 7, 6, 2, 4, 7};
    int iMaior = 0;

    // Encontre o maior elemento
    for (int i = 0; i < 10; i++) {
        if (arri[i] > iMaior)
            iMaior = arri[i];
    }

    // criar um vetor de contagem
    int arriVazio[iMaior + 1] = {0}; // Inicializa todos os elementos com zero

    // contagem de ocorrências de cada elemento
    for (int i = 0; i < 10; i++) {
        arriVazio[arri[i]]++;
    }

    // fazendo a soma cumulativa
    for (int i = 1; i <= iMaior; i++) {
        arriVazio[i] += arriVazio[i - 1];
    }

    int arriOutput[10] = {};

    for (int i = 0; i < 10; i++) {
        int posicaoCorreta = arriVazio[arri[i]]-1;
        arriOutput[posicaoCorreta] = arri[i];
        arriVazio[arri[i]]--;
    }

    for (int i = 0; i < 10; i++) {
        cout << arriOutput[i];
    }

    return 0;
}




