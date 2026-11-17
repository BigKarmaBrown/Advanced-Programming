#pragma once
#include <iostream>
#include "GameState.h"
using namespace std;
class Node {
public:
    Node* leftChild;
    Node* rightChild;
    int data;
    Node(GameState::BattleMove battleMove, int data);
    void Display();
};


