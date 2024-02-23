# include <iostream>

# include "Game.h"

using namespace std;

Game game;

int main() {

	cout << "----------------------\n";
	cout << "WELCOME TO PICK A CARD\n";
	cout << "----------------------\n\n";

	//instructions
	cout << "Instructions:\n";
	cout << "You are to pick a number between 1 - 5: \n";
	cout << "Your card is compared with the programs pick of card \n";
	cout << "The player to reach a score of 5 first wins!\n\n";
	cout << "Before starting:\n";

	game.RunGame();

	return 0;
}



