#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Queue.h"

using namespace std;

// Constructor
Queue::Queue() : front(-1), rear(-1) {}

// Enqueue operation
void Queue::enqueue(Card newCard) {
    // Check if the queue is full
    if ((front == 0 && rear == MAXIMUMCARDS - 1) ||
        ((rear + 1) % MAXIMUMCARDS == front)) {
        return; // Do nothing if the queue is full
    }

    // Enqueue the new card
    if (front == -1) {
        front = rear = 0;
        cards[rear] = newCard;
    }
    else if (rear == MAXIMUMCARDS - 1 && front != 0) {
        rear = 0;
        cards[rear] = newCard;
    }
    else {
        rear = (rear + 1) % MAXIMUMCARDS;
        cards[rear] = newCard;
    }
}

// Dequeue operation
void Queue::dequeue() {
    // Dequeue the front card
    if (!IsEmpty()) {
        front = (front + 1) % MAXIMUMCARDS;
    }
    else {
        cout << "Queue is empty. Cannot dequeue." << endl;
    }
}

// Check if the queue is full
bool Queue::IsFull() {
    if (front == -1) {
        // Queue is not full until the first element is added
        return false;
    }

    return (rear + 1) % MAXIMUMCARDS == front && (rear + 1) % MAXIMUMCARDS != front;
}

// Check if the queue is empty
bool Queue::IsEmpty() {
    return front == rear;
}

// Get the front card
Card Queue::frontCard() {
    if (!IsEmpty()) {
        return cards[front];
    }
    else {
        cout << "Card not found" << endl;
        return Card();
    }
}

// Initialize the deck
void Queue::InitializeDeck() {
    front = rear = 0;

    // Loop to initialize the deck with cards
    for (int rank = Card::MINIMUM_RANK; rank <= Card::MAXIMUM_RANK; rank++) {
        for (int suit = Card::SPADES; suit <= Card::HEARTS; suit++) {
            Card newCard(rank, suit);
            enqueue(newCard);
        }
    }
}

// Shuffle the deck
void Queue::ShuffleDeck() {
    Card temp;
    int m = 0;

    srand(static_cast<unsigned int>(time(0)));

    // Loop to shuffle the deck
    for (int n = front; n <= rear; n++) {
        m = rand() % (rear - front) + front;

        // Swap cards
        temp = cards[n];
        cards[n] = cards[m];
        cards[m] = temp;
    }
}

// Deal a card from the front
Card Queue::DealCard() {
    if (!IsEmpty()) {
        Card dealtCard = cards[front];
        dequeue();
        return dealtCard;
    }
    else {
        cout << "No cards left to deal. The queue is empty." << endl;
        return Card();
    }
}

// Deal a card at a specific index
Card Queue::DealCardAtIndex(int x) {
    if (!IsEmpty() && x >= 0 && x < (rear - front)) {
        return cards[(front + x) % MAXIMUMCARDS];
    }
    // Handle invalid index/ empty queue
    return Card();
}
