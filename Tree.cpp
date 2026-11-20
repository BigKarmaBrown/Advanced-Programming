#include "Tree.h"

Tree::Tree() {
    root = 0;
}

Node* Tree::Find(int key) {
    Node* current = root;
    while (current->data != key) {
        if (key < current->data)
            current = current->leftChild;
        else
            current = current->rightChild;
        if (current == 0)
            return 0;
    }
    return current;
}

void Tree::DisplayInOrder(Node* localRoot) {
    if (localRoot != 0) {
        DisplayInOrder(localRoot->leftChild);
        localRoot->Display();
        DisplayInOrder(localRoot->rightChild);
    }
}

void Tree::Insert( int data)
{
    Node* nodeptr = new Node(data);

    if (root == nullptr) {
        root = nodeptr;
    }
    else {
        Node* current = root;
        // current = root;
        Node* parent;
        while (true) {
            parent = current;
            if (data < current->data) {
                current  = current->leftChild;
                if (current == 0) {
                    parent->leftChild = new Node(data);
                    return;
                }
            }
            else {
                current = current->rightChild;
                if (current == 0) {
                    parent->rightChild = new Node( data);
                    return;
                }
            }
        }

    }


}

void Tree::displayRecentMoves()
{
    
}
