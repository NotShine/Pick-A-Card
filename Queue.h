#pragma once
#pragma once

#include "Card.h"
#include "MAXIMUMCARDS.h"

class Queue {
private:

    Card cards[MAXIMUMCARDS];
    int front;
    int rear;

public:

    Queue();
    void enqueue(Card newCard); //add cards
    void dequeue(); //remove cards
    bool IsEmpty(); //check if queue is empty
    bool IsFull();  //check if queue is full
    Card frontCard();  //show next card to be removed , frontCard is defined

    void InitializeDeck();
    void ShuffleDeck();
    Card DealCard();
    Card DealCardAtIndex(int x);



};