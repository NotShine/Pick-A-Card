#include "Card.h"


Card::Card() : Rank(0), Suit(0) {}
Card::Card(int rank, int suit) : Rank(rank), Suit(suit) {}
Card::~Card() {}

void Card::setRank(int rankNumber) {
	this->Rank = rankNumber;
}
void Card::setSuit(int suitNumber) {
	this->Suit = suitNumber;
}

int Card::getRank() {
	return Rank;
}
int Card::getSuit() {
	return Suit;
}

int Card::CalculateCardValue(int rank, int suit) {
	int CardValue = rank + suit;
	return CardValue;
}

void Card::DisplayCardDealt() {

	cout << "The card dealt has rank: ";

	if (getRank() == 14) {
		cout << "Ace";
	}
	else if (getRank() == 13) {
		cout << "King";
	}
	else if (getRank() == 12) {
		cout << "Queen";
	}
	else if (getRank() == 11) {
		cout << "Jack";
	}
	else {
		cout << getRank();
	}

	cout<< " belonging to the suit of : ";

	if (getSuit() == 4) {
		cout << "Hearts\n";
	}

	else if (getSuit() == 3) {
		cout << "Diamonds\n";
	}

	else if (getSuit() == 2) {
		cout << "Clubs\n";
	}

	else if (getSuit() == 1) {
		cout << "Spades\n";
	}

}

