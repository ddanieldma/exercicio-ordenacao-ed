#include "queue-bt.h"

int main() {
    NodeTree<int>* root = nullptr;

    root = insertNodeTree(root, 3);
    root = insertNodeTree(root, 1);
    root = insertNodeTree(root, 5);
    root = insertNodeTree(root, 7);
    root = insertNodeTree(root, 6);
    root = insertNodeTree(root, 42);
    root = insertNodeTree(root, 13);

    cout << "Percorrendo in order" << endl;
    inOrderTraverse(root);
    cout << endl;

    cout << "Percorrendo pre order" << endl;
    preOrderTraverse(root);
    cout << endl;

    cout << "Percorrendo post order" << endl;
    postOrderTraverse(root);
    cout << endl;

    cout << "Percorrendo bfs" << endl;
    bfsTraverse(root);
    cout << endl;

    return 0;
}
