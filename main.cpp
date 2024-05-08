#include <iostream>
#include "utils.h"
#include "doubly-linked-list.h"
#include "bubble_sort.h"
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main(){

    srand(time(NULL));

    // linked list com 10 nós
    Node* head_10 = nullptr;
    for (int i = 0; i < 10; ++i) {
        insertEnd(&head_10, rand() % 100); 
    }

    Node* head_10_opt = nullptr;
    for (int i = 0; i < 10; ++i) {
        insertEnd(&head_10_opt, rand() % 100); 
    }

    cout << "linked list com 10 nós: " << endl;
    displayList(head_10);
    cout << " " << endl;

    cout << "linked list com 10 nós (pós bubble-sort): " << endl;
    auto timeStart10 = high_resolution_clock::now();
    bubbleSort(&head_10);
    auto timeStop10 = high_resolution_clock::now();

    auto timeStart10opt = high_resolution_clock::now();
    optimizedBubbleSort(&head_10_opt);
    auto timeStop10opt = high_resolution_clock::now();

    displayList(head_10);

    auto timeDuration10 = duration_cast<nanoseconds>(timeStop10 - timeStart10);
    cout << "Tempo decorrido: " << timeDuration10.count() << " nanosegundos." << endl;

    auto timeDuration10opt = duration_cast<nanoseconds>(timeStop10opt - timeStart10opt);
    cout << "Tempo decorrido (otimizado): " << timeDuration10opt.count() << " nanosegundos." << endl;

    iguais();

    // linked list com 100 nós
    Node* head_100 = nullptr;
    for (int i = 0; i < 100; ++i) {
        insertEnd(&head_100, rand() % 100); 
    }

    Node* head_100_opt = nullptr;
    for (int i = 0; i < 100; ++i) {
        insertEnd(&head_100_opt, rand() % 100); 
    }

    cout << "linked list com 100 nós: " << endl;
    displayList(head_100);
    cout << " " << endl;

    cout << "linked list com 100 nós (pós bubble-sort): " << endl;
    auto timeStart100 = high_resolution_clock::now();
    bubbleSort(&head_100);
    auto timeStop100 = high_resolution_clock::now();

    auto timeStart100opt = high_resolution_clock::now();
    optimizedBubbleSort(&head_100_opt);
    auto timeStop100opt = high_resolution_clock::now();

    displayList(head_100);

    auto timeDuration100 = duration_cast<nanoseconds>(timeStop100 - timeStart100);
    cout << "Tempo decorrido: " << timeDuration100.count() << " nanosegundos." << endl;

    auto timeDuration100opt = duration_cast<nanoseconds>(timeStop100opt - timeStart100opt);
    cout << "Tempo decorrido (otimizado): " << timeDuration100opt.count() << " nanosegundos." << endl;
    iguais();

    // linked list com 1000 nós
    Node* head_1000 = nullptr;
    for (int i = 0; i < 1000; ++i) {
        insertEnd(&head_1000, rand() % 100); 
    }

    Node* head_1000_opt = nullptr;
    for (int i = 0; i < 1000; ++i) {
        insertEnd(&head_1000_opt, rand() % 100); 
    }

    cout << "linked list com 1000 nós: " << endl;
    displayList(head_1000);
    cout << " " << endl;

    cout << "linked list com 1000 nós (pós bubble-sort): " << endl;
    auto timeStart1000 = high_resolution_clock::now();
    bubbleSort(&head_1000);
    auto timeStop1000 = high_resolution_clock::now();

    auto timeStart1000opt = high_resolution_clock::now();
    optimizedBubbleSort(&head_1000_opt);
    auto timeStop1000opt = high_resolution_clock::now();

    displayList(head_1000);

    auto timeDuration1000 = duration_cast<nanoseconds>(timeStop1000 - timeStart1000);
    cout << "Tempo decorrido: " << timeDuration1000.count() << " nanosegundos." << endl;

    auto timeDuration1000opt = duration_cast<nanoseconds>(timeStop1000opt - timeStart1000opt);
    cout << "Tempo decorrido (otimizado): " << timeDuration1000opt.count() << " nanosegundos." << endl;

    iguais();

    // insertEnd(&head, 7);
    // insertEnd(&head, 53);
    // insertEnd(&head, 42);
    // insertEnd(&head, 2);
    // insertEnd(&head, 666);

    // bubbleSort(&head);

    // displayList(head);
    
    return 0;
}