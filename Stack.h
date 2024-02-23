#pragma once
#pragma once

#include "Card.h"
#include "MAXIMUMCARDS.h"

class Stack {

private:

    Card cards[MAXIMUMCARDS];
    int top;

public:
    Stack();
    void push(Card newCard);
    void pop();
    bool isEmpty();
    Card topCard();

    void InitializeDeck(); // initialise a stack of cards
    void ShuffleDeck(); //shuffle deck of cards
    Card DealCard(); //deal deck of cards
    Card DealCardAtIndex(int x);

};
