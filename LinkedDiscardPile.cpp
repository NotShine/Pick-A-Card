# include "LinkedDiscardPile.h"
# include "Node.h"

LinkedDiscardPile::LinkedDiscardPile() : head(nullptr) {} //constructor

LinkedDiscardPile::~LinkedDiscardPile() {} //destructor

void LinkedDiscardPile::AddCardToDiscardPile(Card card) {

	Node* newNode = new Node(card);
	newNode->next = head;
	head = newNode;

}