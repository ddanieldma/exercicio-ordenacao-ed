#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {

    cout << "\nO counting sort é um método de sorting que utiliza a frequência de aparições de um elemento para realizar a ordenação. \n\n1-	Primeiro iteramos sob a lista/array a fim de encontrar o seu maior elemento. Após isso, criamos uma nova lista/array de tamanho maior_elemento+1. Essa lista servirá para abrigar o count do número de aparições de cada elemento na lista original (como essa alocação será via index, se o maior numero for 10, por exemplo, a lista deverá ter o index 10, logo seu tamanho é 10+1). \n\n2-	Agora fazemos a soma cumulativa na lista criada. Isso significa que o valor no índice [i] será a soma dos valores dos índices [i, i-1, i-2, ..., 0]. \n\n3-	Por fim, podemos realocar nossos elementos nas suas posições corretas. Para isso, iteramos sob cada valor na lista original e os usamos como índices na lista de contagem da etapa 2. Após isso, subtraímos 1 do valor encontrado. Esse será o índice do valor do input na lista ordenada. Fazemos esse processo para todo i e o counting sort estará finalizado. \n\nPara explicar o counting sort vamos considerar que a nossa lista que abriga as contagens obteve, no index 4, um valor 7 após a soma acumulada. Isso quer dizer que existem 7 valores menores ou iguais a 4 na lista original. Desse modo, se temos um valor quatro, este ficará na posição 6 no output (index inicia no 0), caso tenhamos 2, ficarão na posição 6 e  5, etc." << endl;
    
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

    return 0;

}




