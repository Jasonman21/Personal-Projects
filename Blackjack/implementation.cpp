#include "blackjack2.h"
#include <iostream>
using namespace std;

ostream& operator << (ostream & os,const CARD & deck)
{
  os << deck.face << " of " << deck.suit;
  return os;
}

void sortElements(CARD hand[], const int handSize)
{
  for(int i = 0; i < handSize - 1; i++)
    {
      for(int j = 0; j < handSize - i - 1; j++)
        if(hand[j+1] < hand[j])
        {
          const CARD temp = hand[j];
          hand[j] = hand[j+1];
          hand[j+1] = temp;
        }
    }
}

bool operator < (const CARD& lhs, const CARD& rhs)
{
  return lhs.index < rhs.index;
}

int calculateHand(const CARD hand[], const int handSize)
{
  int total = 0, aceAmt = 0;
  for(int i = 0; i < handSize; i++)
    {
      if(hand[i].value == 1)
      {
        total += 11;
        ++aceAmt;
      }
      else
        total += hand[i].value;
    }
  while(total > 21 && aceAmt > 0)
    {
      total -= 10;
      aceAmt--;
    }
  return total;
}

void initializeDeck(CARD deck[], const int size)
{
  for(int i = 0; i < size; i++)
    {
      CARD card;
      card.value = (i % 13) + 1;
      if(i < 13)
      {
        card.suit = "Diamonds";
      }
      else if(i < 26)
      {
        card.suit = "Hearts";
      }
      else if(i < 39)
      {
        card.suit = "Clubs";
      }
      else
        card.suit = "Spades";

      if(card.value == 1)
      {
        card.face = "Ace";
      }
      else if(card.value == 11)
      {
        card.value = 10;
        card.face = "Jack";
      }
      else if(card.value == 12)
      {
        card.value = 10;
        card.face = "Queen";
      }
      else if(card.value == 13)
      {
        card.value = 10;
        card.face = "King";
      }
      else
        card.face = to_string(card.value);

      deck[i] = card;
    }
}

void resetDealt(const int SIZE, int dealt[])
{
  for(int i = 0; i < SIZE; i++)
    dealt[i] = false;
}

int generateRandomCard(int min, int max, int dealt[])
{
  int cardIndex;
  do {
        cardIndex = rand() % max + min; 
     }while(dealt[cardIndex]);
  dealt[cardIndex] = true; 
  return cardIndex; 
}
void printHand(CARD hand[], const int handSize)
{
  sortElements(hand, handSize);
  for(int i = 0; i <= handSize; i++)
    {
      if(i == handSize)
        {
          cout << hand[i];
        }
        else
          cout << hand[i] << ", ";
    }
}
bool isBlackjack(CARD playerHand[],const int handSize)
{
  if(calculateHand(playerHand, 2) == 21)
  {
    return true;
  }
  else
    return false;
}


int displayOutcome(int totalBalance, const int playerWinState, const int bet)
{

  switch(playerWinState)
    {
      case 0:
        cout << "\n\nSorry but you've lost!" << "\nBalance Update : -$" << bet << "\nYour new balance is : $" << (totalBalance -= bet);
        return totalBalance;
        break;
      case 1:
        (totalBalance += bet);
        (totalBalance += (bet/2));
        cout << "\n\nCongratulations! You've won with blackjack!" << "\nBalance Update : +$" << (bet + (bet / 2)) << "\nYour new balance is : $" << totalBalance;
        return totalBalance;
        break;
      case 2:
        cout << "\n\nCongratulations! You've won!" << "\nBalance Update : +$" << bet << "\nYour new balance is : $" << (totalBalance + bet);
        return (totalBalance + bet);
        break;
      case 3:
        cout << "\n\nSorry but you've tied!" << "\nBalance Update : $"  << totalBalance;
        return totalBalance;
        break;
      case 4:
        cout << "\n\nSorry but you've lost Double Down!" << "\nBalance Update : -$" << bet * 2 << "\nYour new balance is : $" << (totalBalance -= bet * 2);
        return totalBalance;
      break;
      case 5:
        cout << "\n\nCongratulations! You've won Double Down!" << "\nBalance Update : +$" << (2 * bet) << "\nYour new balance is : $" << (totalBalance + (2 * bet));
        return (totalBalance + (2 * bet));
        break;

    }    
  return totalBalance;
}

void displayGameSummary(const int roundCount, const int totalWins, const int gameBlackjack, const int totalLosses, const int ties, const int totalBalance, const int netGainLoss)
{
  cout << " === Game Summary === " << endl <<
  "Total Rounds Played: " << roundCount << endl <<
  "Total Wins (Regular): " << totalWins << endl <<
  "Total Wins (Blackjack): " << gameBlackjack << endl << 
  "Total Losses: " << totalLosses << endl << 
  "Total Ties: " << ties << endl <<
  "Final Balance: $" << totalBalance << endl <<
  "Net Gain/Loss: " << "$" << netGainLoss << endl;

}
