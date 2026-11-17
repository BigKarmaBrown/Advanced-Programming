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

void Tree::Insert(GameState::BattleMove battleMove, int data)
{
    Node* nodeptr = new Node(battleMove, data);

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
                    parent->leftChild = new Node(battleMove, data);
                    return;
                }
            }
            else {
                current = current->rightChild;
                if (current == 0) {
                    parent->rightChild = new Node(battleMove, data);
                    return;
                }
            }
        }

    }


}
