#pragma once
#include "Node.h"
#include "GameState.h"
class GameState;
//#include "PriorityQueue.h"
class Tree      //store enemies
{
public:


    Node* root;
    Tree();
    Node* Find(int key);
    void DisplayInOrder(Node* localRoot);
    void Insert(int data);

    

    void displayRecentMoves();
};

