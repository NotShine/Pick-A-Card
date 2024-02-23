#pragma once
#pragma once

#include <string>
#include <iostream>

using namespace std;

class Card {

private:


    int Rank; //value of rank
    int Suit; //value of suit

public:

    Card();
    ~Card();
    Card(int rank, int suit);

    // Constants for ranks
    static const int MINIMUM_RANK = 2; //card with 2
    static const int MAXIMUM_RANK = 14; //ACE

    // Constants for suits
    static const int HEARTS = 4;
    static const int DIAMONDS = 3;
    static const int CLUBS = 2;
    static const int SPADES = 1;

    //setters
    void setRank(int rankNumber);
    void setSuit(int suitNumber);

    //getters
    int getRank();
    int getSuit();

    //calculate card value
    int CalculateCardValue(int rank, int suit);

    //display card dealt to both players
    void DisplayCardDealt();


};
