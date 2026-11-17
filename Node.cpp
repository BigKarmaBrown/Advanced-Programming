#include "Node.h"

Node::Node(GameState::BattleMove battleMove, int data) {
    this->data = data;
    leftChild = 0;
    rightChild = 0;
}

void Node::Display() {
    cout << this->data << endl;
}
