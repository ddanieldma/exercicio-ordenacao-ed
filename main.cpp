#include <iostream>
#include "utils.h"
#include "doubly-linked-list.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(){
    Node* head = nullptr;
    displayList(head);

    iguais();

    insertEnd(&head, 7);
    insertEnd(&head, 13);
    insertEnd(&head, 42);
    insertEnd(&head, 666);

    displayList(head);
    
    return 0;
}