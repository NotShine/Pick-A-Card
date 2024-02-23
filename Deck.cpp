
# include <iostream>

#include "Deck.h"
#include "Card.h"
#include "Stack.h"
#include "Queue.h"
#include "MAXIMUMCARDS.h"

using namespace std;

Deck::Deck() {}
// Destructor
Deck::~Deck() {}



// Version A: Stack implementation
void Deck::InitializeDeckWithStack() {
    StackOfCards.InitializeDeck();
}

void Deck::ShuffleDeckWithStack() {
    StackOfCards.ShuffleDeck();
}

Card Deck::DealCardWithStack() {
    return StackOfCards.DealCard();
}

// Version B: Queue implementation
void Deck::InitializeDeckWithQueue() {
    QueueOfCards.InitializeDeck();
}

void Deck::ShuffleDeckWithQueue() {
    QueueOfCards.ShuffleDeck();
}

Card Deck::DealCardWithQueue() {
    return QueueOfCards.DealCard();
}

Card Deck::DealCardWithQueueAtIndex(int x) {
    return QueueOfCards.DealCardAtIndex(x);
}

Card Deck::DealCardWithStackAtIndex(int x) {
    return StackOfCards.DealCardAtIndex(x);
}
