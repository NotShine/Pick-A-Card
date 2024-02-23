# include <ctime>
# include <cstdlib>

# include "Stack.h"

Stack::Stack() : top(-1) {}

void Stack::push(Card newCard) {
	if (top < MAXIMUMCARDS - 1) {  //if stack not full
		cards[top++] = newCard;  //add new card to stack
	}
}

void Stack::pop() {
	if (!isEmpty()) {
		top--;
	}
}

bool Stack::isEmpty() {
	return top == -1;
}

Card Stack::topCard() {
	if (!isEmpty())
		return cards[top];

	else {
		// Handle invalid index 
		return Card();
	}
}

void Stack::InitializeDeck() {
	// Initialize the deck for a stack
	for (int rank = Card::MINIMUM_RANK; rank <= Card::MAXIMUM_RANK; rank++) {
		for (int suit = Card::SPADES; suit <= Card::HEARTS; suit++) {
			Card newCard(rank, suit);
			push(newCard);
		}
	}
}

void Stack::ShuffleDeck() {
	Card temp;
	int m = 0;

	srand(static_cast<unsigned int>(time(0)));

	for (int n = 0; n < MAXIMUMCARDS; n++) {
		m = rand() % MAXIMUMCARDS;

		// Swap cards
		push(cards[m]);
		temp = cards[n];

		cards[m] = temp;
	}
}

Card Stack::DealCard() {
	if (!isEmpty()) {
		return cards[top];
	}
	else {
		// Handle invalid index 
		return Card();
	}
}

Card Stack::DealCardAtIndex(int x) {
	if (!isEmpty() && x > 0 && x <= top + 1) {
		return cards[top - x + 1];
	}
	else {
		// Handle invalid index 
		return Card();
	}
}