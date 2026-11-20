#pragma once
#include "Link.h"
#include "GameState.h"


struct battleMove {
    int turnNum;
    string person;
    string move;
    float damage;

    bool operator>(const battleMove& other) const
    {
        return turnNum > other.turnNum;
    }

};


class LinkedListMoves
{
public:
   

 //battleMove** data;


   

    Link* first;
    LinkedListMoves();
    ~LinkedListMoves();

    bool IsEmpty();
    void Insert(Link* newLink);
    void Display();
    Link* Find(int key);
    Link* Delete(int key);



   // LinkedListMoves<Link> battleHistory;
};

LinkedListMoves::LinkedListMoves() {
    
    first = nullptr;
}

LinkedListMoves::~LinkedListMoves() {

}

bool LinkedListMoves::IsEmpty() {
    return (first == nullptr);
}

void LinkedListMoves::Insert(Link* newLink) {
    newLink->next = first;
    first = newLink;
}

void LinkedListMoves::Display() {
    Link* current = first;
    while (current != nullptr) {
        current->Display();
        current = current->next;
    }
}

Link* LinkedListMoves::Find(int key) {
    Link* current = first;

    while (current != nullptr && current->data->turnNum != key) {
        current = current->next;


    }
    return current;
}

Link* LinkedListMoves::Delete(int key) {
    Link* current = first;
    Link* previous = first;

    while (current != nullptr && current->data->turnNum != key) {
        previous = current;
        current = current->next;
    }


    if (current == nullptr) {
        return nullptr;
    }


    if (current == first) {
        first = first->next;
    }

    else {
        previous->next = current->next;
    }

    return current;
}
