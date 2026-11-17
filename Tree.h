#pragma once
#include "Node.h"
#include "GameState.h"
class GameState;
#include "PriorityQueue.h"
class Tree
{
public:


    Node* root;
    Tree();
    Node* Find(int key);
    void DisplayInOrder(Node* localRoot);
    void Insert(GameState::BattleMove move, int data);

    PriorityQueue<GameState::BattleMove>* battleHistory;
};

