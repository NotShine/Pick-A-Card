#pragma once
#pragma once
# include "Node.h"

class LinkedDiscardPile {

	friend class BinaryTree;

private:

	Node* head;

public:

	LinkedDiscardPile(); //constructor
	~LinkedDiscardPile(); //destructor

	void AddCardToDiscardPile(Card card);
};