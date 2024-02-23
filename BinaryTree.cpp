// BinaryTree.cpp
#include "BinaryTree.h"
#include "LinkedDiscardPile.h"
#include "TreeNode.h"
#include <iostream>

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {}

void BinaryTree::InsertFromLinkedList(LinkedDiscardPile list) {
    Node* currentNode = list.head;

    while (currentNode != nullptr) {
        root = InsertRecursive(root, currentNode->DiscardedCard);
        currentNode = currentNode->next;

    }
}

TreeNode* BinaryTree::InsertRecursive(TreeNode* node, Card card) {
    if (node == nullptr) {
        return new TreeNode(card);
    }

    int currentCardRank = node->DiscardedCard.getRank();
    int currentCardSuit = node->DiscardedCard.getSuit();

    int comparisonResult = card.CalculateCardValue(card.getRank(), card.getSuit()) - node->DiscardedCard.CalculateCardValue(currentCardRank, currentCardSuit);

    if (comparisonResult == 0)
        return node;

    if (card.CalculateCardValue(card.getRank(), card.getSuit()) < node->DiscardedCard.CalculateCardValue(currentCardRank, currentCardSuit)) {
        node->left = InsertRecursive(node->left, card);
    }
    else {
        node->right = InsertRecursive(node->right, card);
    }

    return node;
}

void BinaryTree::FindHighestLowestCard(LinkedDiscardPile list) {

    Card HighestCard, LowestCard;

    Node* currentNode = list.head;

    if (currentNode != nullptr) {
        HighestCard = currentNode->DiscardedCard;
        LowestCard = currentNode->DiscardedCard;


        while (currentNode != nullptr) {

            // Access rank and suit of the current card
            int currentCardRank = currentNode->DiscardedCard.getRank();
            int currentCardSuit = currentNode->DiscardedCard.getSuit();

            // Compare current card with highest and lowest

            if (currentNode->DiscardedCard.CalculateCardValue(currentCardRank, currentCardSuit) >  //curent card > highest card

                HighestCard.CalculateCardValue(HighestCard.getRank(), HighestCard.getSuit()))

                HighestCard = currentNode->DiscardedCard;

            else if (currentNode->DiscardedCard.CalculateCardValue(currentCardRank, currentCardSuit) <
                LowestCard.CalculateCardValue(LowestCard.getRank(), LowestCard.getSuit()))
                LowestCard = currentNode->DiscardedCard;

            currentNode = currentNode->next;
        }


    }

    //Display highest and lowest card played

    cout << "The highest card played is:  ";

    if (HighestCard.getRank() == 14) {
        cout << "Ace";
    }
    else if (HighestCard.getRank() == 13) {
        cout << "King";
    }
    else if (HighestCard.getRank() == 12) {
        cout << "Queen";
    }
    else if (HighestCard.getRank() == 11) {
        cout << "Jack";
    }
    else {
        cout << HighestCard.getRank();
    }

     cout  << " of ";

    if (HighestCard.getSuit() == 4) {
        cout << "Hearts\n";
    }

    else if (HighestCard.getSuit() == 3) {
        cout << "Diamonds\n";
    }

    else if (HighestCard.getSuit() == 2) {
        cout << "Clubs\n";
    }

    else if (HighestCard.getSuit() == 1) {
        cout << "Spades\n";
    }
    cout << " The lowest card played is:  ";

    if (LowestCard.getRank() == 14) {
        cout << "Ace";
    }
    else if (LowestCard.getRank() == 13) {
        cout << "King";
    }
    else if (LowestCard.getRank() == 12) {
        cout << "Queen";
    }
    else if (LowestCard.getRank() == 11) {
        cout << "Jack";
    }
    else {
        cout << LowestCard.getRank();
    }

        cout <<" of ";

    if (LowestCard.getSuit() == 4) {
        cout << "Hearts\n";
    }

    else if (LowestCard.getSuit() == 3) {
        cout << "Diamonds\n";
    }

    else if (LowestCard.getSuit() == 2) {
        cout << "Clubs\n";
    }

    else if (LowestCard.getSuit() == 1) {
        cout << "Spades\n";
    }

}





