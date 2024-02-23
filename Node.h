#pragma once
#pragma once

#include "Card.h"

class Node {

	friend class LinkedDiscardPile;
	friend class BinaryTree;

private:

	Card DiscardedCard;
	Node* next;


public:

	// Constructor for linked list
	Node(Card card, Node* nextNode = nullptr);


};