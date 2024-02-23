#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Deck.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedDiscardPile.h"
#include "BinaryTree.h"
#include "MAXIMUMCARDS.h"

using namespace std;

Game::Game() : rounds(0) {}//constructor

Game::~Game() {}//destructor

Deck StandardDeck;

BinaryTree Tree;

LinkedDiscardPile DiscardPile;

int HumanPlayerScore, ComputerPlayerScore;

void Game::RunGame() {

    int continuechoice = -1;

    do {
        // Get user input for continuechoice and validate it
        cout << "Please enter 1 to continue or 0 to exit: ";
        cin >> continuechoice;
        cout << endl << endl;
        // If the user entered 0, exit the loop

        // Validate input
        while (cin.fail() || continuechoice < 0 || continuechoice > 1) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter 1 to continue or 0 to exit: ";
            cin >> continuechoice;
        }


        // If user chooses to continue
        if (continuechoice == 1) {
            // Reset scores and play another round
            HumanPlayerScore = 0;
            ComputerPlayerScore = 0;

            if (continuechoice == 0)
                break;




            //input for game version
            while (HumanPlayerScore < 5 && ComputerPlayerScore < 5) {
                int gameVersion = 0;
                cout << "Choose your game version\n";
                cout << "1. Stack Version" << endl;
                cout << "2. Queue Version" << endl;
                cin >> gameVersion;

                while (cin.fail() || gameVersion < 1 || gameVersion > 2) {
                    cout << "Invalid input. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> gameVersion;
                }

                PlayRound(gameVersion);
            }

            if (HumanPlayerScore == 5 || ComputerPlayerScore == 5) {
                DiplayFinalResults();
            }

            int ViewCards = 0;
            cout << "Press 2 to see the highest and lowest card played: ";
            cin >> ViewCards;

            //validate input
            while (cin.fail() || ViewCards != 2) {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> ViewCards;
            }

            if (ViewCards == 2) {
                DisplayHighestandLowestCardPlayed();
            }
        }

    } while (continuechoice == 1);

    if (continuechoice == 0) {

        cout << endl;
        cout << "The elite gamers are elite for a reason :)\n";
    }
}


void Game::PlayRound(int gameVersion) {


    int NumberChoice = 0;
    //take user input
    cout << "Please pick a number from below: \n";
    cout << "  1 , 2 , 3 , 4 , 5\n";
    cin >> NumberChoice;

    //validate input
    while (cin.fail() || NumberChoice < 1 || NumberChoice > 5) {
        cout << "Invalid input. Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> NumberChoice;

    }

    Card PlayerCard, ProgramAICard;

    if (gameVersion == 1) {
        StandardDeck.InitializeDeckWithStack(); //initaise deck w stack 
        StandardDeck.ShuffleDeckWithStack();   //shuffle deck

        PlayerCard = StandardDeck.DealCardWithStackAtIndex(NumberChoice); //deal player card
        ProgramAICard = StandardDeck.DealCardWithStack(); //deal programs card

        //show card dealt
        cout << "Your card: \n"; PlayerCard.DisplayCardDealt();
        cout << "ProgramAI  card: \n"; ProgramAICard.DisplayCardDealt();

        DetermineHighestCardValue(PlayerCard, ProgramAICard); // determine score

        cout << endl;
        DisplayResults(); //display results

        // Move dealt cards to the discard pile
        DiscardPile.AddCardToDiscardPile(PlayerCard);
        DiscardPile.AddCardToDiscardPile(ProgramAICard);

    }
    else if (gameVersion == 2) {
        StandardDeck.InitializeDeckWithQueue();
        StandardDeck.ShuffleDeckWithQueue();

        PlayerCard = StandardDeck.DealCardWithQueueAtIndex(NumberChoice);
        ProgramAICard = StandardDeck.DealCardWithQueue();

        //show card dealt
        cout << endl;
        cout << "Your card: \n"; PlayerCard.DisplayCardDealt();
        cout << endl;
        cout << "ProgramAI  card: \n"; ProgramAICard.DisplayCardDealt();

        DetermineHighestCardValue(PlayerCard, ProgramAICard); // determine score

        cout << endl;
        DisplayResults(); //display results

        // Move dealt cards to the discard pile
        DiscardPile.AddCardToDiscardPile(PlayerCard);
        DiscardPile.AddCardToDiscardPile(ProgramAICard);

    }
}


void Game::DisplayHighestandLowestCardPlayed() {

    // Insert cards from the linked discard pile into the binary tree
    Tree.InsertFromLinkedList(DiscardPile);

    // Find and display the highest and lowest cards played in the game
    Tree.FindHighestLowestCard(DiscardPile);

}

void Game::DetermineHighestCardValue(Card PlayerCard, Card ProgramAICard) {


    //calculate card value

    //human player card > computer player card
    if (PlayerCard.CalculateCardValue(PlayerCard.getRank(), PlayerCard.getSuit()) >
        ProgramAICard.CalculateCardValue(ProgramAICard.getRank(), ProgramAICard.getSuit())) {
        HumanPlayerScore++;
    }

    //human player card < computer player card
    else if (PlayerCard.CalculateCardValue(PlayerCard.getRank(), PlayerCard.getSuit()) <
        ProgramAICard.CalculateCardValue(ProgramAICard.getRank(), ProgramAICard.getSuit())) {
        ComputerPlayerScore++;
    }

    else if (PlayerCard.CalculateCardValue(PlayerCard.getRank(), PlayerCard.getSuit()) ==
        ProgramAICard.CalculateCardValue(ProgramAICard.getRank(), ProgramAICard.getSuit())) {
        cout << "It's a tie";

        // if either player scores are 0, return
        if (HumanPlayerScore == 0 || ComputerPlayerScore == 0) {
            return;
        }

        // if either is > 0, then decrement 
        else if (HumanPlayerScore > 0 || ComputerPlayerScore > 0) {
            HumanPlayerScore--;
            ComputerPlayerScore--;

        }

    }
}

//displays one round result
void Game::DisplayResults() {

    cout << "Scores - Human: " << HumanPlayerScore << " | ProgramAI: " << ComputerPlayerScore << endl << endl;

}

//final (after 5 round result)
void Game::DiplayFinalResults() {

    if (HumanPlayerScore > ComputerPlayerScore) {
        cout << "You Win!!\n\n";
    }

    else if (HumanPlayerScore < ComputerPlayerScore) {
        cout << "ProgramAI Wins. Better luck next time\n\n";
    }
}

