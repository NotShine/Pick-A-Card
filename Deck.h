#pragma once


#include "Card.h"
#include "Stack.h"
#include "Queue.h"

class Deck {

private:

    Stack StackOfCards;
    Queue QueueOfCards;

public:
    Deck(); //default constructor

    //  Destructor 
    ~Deck();

    void InitializeDeckWithStack();
    void ShuffleDeckWithStack();
    Card DealCardWithStack();
    Card DealCardWithStackAtIndex(int x);

    // Version B: Queue implementation
    void InitializeDeckWithQueue();
    void ShuffleDeckWithQueue();
    Card DealCardWithQueue();
    Card DealCardWithQueueAtIndex(int x);


};
