Project Name: Pick A Card

Author: Shindu Shirishna Chand

This project is largely based on the Stack and Queue data structure along with Classes. The concept of Binary Tree and Linked List has also been implemented in this project. On program start, a menu will be displayed on the console highlight the name and instruction on how to play the game. Another menu with the various game versions will be displayed to the user who will then be requested to choose the game version they wish to play in.

Version A is a stack implementation of a deck of cards which follows the principles of stack data structure whilst version B is the queue implementation. After which, a standard deck of cards will be created an initialised as per the chosen game version.

The user will now be requested to select a number between 1 to 5 which will randomly allocate a card to the user. Simultaneously, a random card will be assigned to the computer player, and it is decided which card is the strongest before allocating points to either player.

After each round where the player selects the card, they are given the option to switch between the game versions.

How is the Value of a Card Determined?

The value of the card is determined by adding the numbers that represent its suit and rank. In this game, the lowest rank is 2 whereas the highest-ranking card, Ace is given a value of 14. Similarly, Hearts being the strongest suit is given a value of 4 while Spades is given the lowest rank of 1. Adding the two values for suits and rank gives the value of the card.

Once, the user and computer card are valued, they are compared. If both players have the same card, then both lose a point. Otherwise, the player with the card that has the highest value wins. The player to first reach 5 points will win the game.

All dealt cards are discarded into a discard pile linked list. Afterwhich, a binary search tree is created.

Once a player reaches 5 points, the game will finish, and the user is asked to enter 2 to see the highest and lowest card drawn.

All of the major functionalities are enclosed in the various classes and all function calls are carried out in the Game class.

Classes: Card Deck Queue Stack LinkedDiscardPile //linked list BinaryTree TreeNode Node
