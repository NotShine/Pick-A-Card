#pragma once
#pragma once

#include "Card.h"
#include "LinkedDiscardPile.h"
#include "MAXIMUMCARDS.h"


class Game {
private:

    int rounds;
    LinkedDiscardPile DiscardPile;

public:



    Game(); // Constructor 
    ~Game();
    void RunGame(); // Method to run the game
    void PlayRound(int gameVersion);
    void DetermineHighestCardValue(Card PlayerCard, Card ProgramAICard); //comapare two players card
    void DisplayResults(); //display each round result
    void DiplayFinalResults(); //display overall winner after 5 rounds
    void DisplayHighestandLowestCardPlayed(); //function to display highest and lowest 
};