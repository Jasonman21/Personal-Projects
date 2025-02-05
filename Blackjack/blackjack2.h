#ifndef BLACKJACK2_H
#define BLACKJACK2_H
#include <iostream>
#include <string>
using namespace std;
/////////////////// Struct //////////////////
struct CARD{
  std::string suit;
  std::string face;
  int index;
  int value;
  bool drawn;  
};


//////////////Function Prototypes //////////////
// Description: overloads the < operator in order to compare the values of the cards
// Pre: Requires the CARD struct and the lhs and rhs of the cards
// Post: allows for the comparison of the CARD struct things
bool operator < (const CARD& lhs, const CARD& rhs);

// Description: Overloads the + operator to add the values the card totals to the total amount
// Pre: requires the deck to be intialized and the total to be intialized
// Post: allows for the addition of the values of the cards after being overloaded.
CARD operator+(const CARD& card1, const CARD& card2);

// Description: overloads the << operator to print the cards out directly
// Pre: requires deck to be intialized
// Post: allows the for use of the << operator to print out the array of cards
ostream& operator << (ostream & os,const CARD & deck);

// Description: resets the array of cards that have already been dealt.
// Pre: requires the deck to be intialized and for the size to be set
// Post: resets the array of dealt cards
void resetDealt(const int SIZE, int dealt[]);

// Description: will sort the hand from diamonds, to hearts, clubs, spades, then from ace to king
// Pre: requires deck to be intialized and for the size of the hand
// Post:\will sort the deck of cards in a specific order
void sortElements(CARD hand[], const int handSize);

// Description: will calulate the total of the players hand
// Pre: requires the deck to be intialized, size of hand, and also the overloading of the + operator
// Post: will calculate numeric value of the hand
int calculateHand(const CARD hand[], const int handSize);

// Description: will initialize the deck
// Pre: Nome
// Post: A welcome message it printed on the screen
void initializeDeck(CARD deck[], const int size);

// Description: Output a welcome message to the user
// Pre: Nome
// Post: A welcome message it printed on the screen
int generateRandomCard(int min, int max, int dealt[]);

// Description: Will check if the user has blackjack within the first two cards given to them.
// Pre: playerHand, Deck, and handSize must be initialized and set before this function can run
// Post: Will return a bool value of true or false, if the user has blackjack or not
bool isBlackjack(CARD playerHand[],const int handSize);

// Description: will print the hand of user or dealer.
// Pre: will utilize the sortElements function to sort the hand before printing.
// Post: will print the hand out to the user
void printHand(CARD hand[], const int handSize);

// Description: This function will use its parameters to check what type of win/loss the user has in their game, and then will use a switch statement to determine the outcome, it will return the totalbalance after taking the bet and modifying it depending on the type of winState.
// Pre: requires the total balance to be intialized
// Post: This will display the win/loss message to the user and will return a balance update along with how much they won or loss that round
int displayOutcome(int totalBalance, const int playerWinState, const int bet);

// Description: This function will use all of its parameters to track the programs attempts and total summary of the player's experience and will output it back to the user before ending the program
// Pre: Each parameter must be intialized and the user must tell the program that they would not like to play again. Finally each of the prior functions must be called before game summary as game summary is at the end of the program.
// Post: This will output the total attempts, wins, losses, ties, blackjacks, the total balance, and the netGainLoss to the screen in a summary of the user's experience.

void displayGameSummary(const int roundCount, const int totalWins, const int gameBlackjack, const int totalLosses, const int ties, const int totalBalance, const int netGainLoss);



#endif
