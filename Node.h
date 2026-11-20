#pragma once
#include <iostream>
#include "GameState.h"
using namespace std;
class Node {
public:
    Node* leftChild;
    Node* rightChild;
    int data;
   // battleMove battleMove;
    Node( int data) {
        leftChild = nullptr;
        rightChild = nullptr;
        this->data = data;
       // this->battleMove = battleMove;
    };
    void Display();
};


