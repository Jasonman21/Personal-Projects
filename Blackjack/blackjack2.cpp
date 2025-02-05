/// Programmer: Jason Dieckhaus Jr
// Date: 10/9/24
// File: blackjack2.cpp
// Assignment: HW5
// Purpose: This program will simulate a game of blackjack while using the requirements from HW5 to ensure the proper success.
#include "blackjack2.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 52, MIN = 1, MAX = 52;


int main()
{
  int drawn[52];
  int playerTotal = 0, dealerTotal = 0, playerSize = 0, dealerSize = 0, playerWinState = 0, gameTies = 0, gameWins = 0, gameBlackjack = 0, gameLoss = 0, netGainLoss = 0, roundCount = 0;
  char hitStayDD;
  CARD playerHand[20], dealerHand[20];
  CARD deck[SIZE];
  char playAgain;
  double startingMoney, currentBalance, wager;
  string playerName;

  cout << "Hello Player, please enter your name : ";
  cin >> playerName;
  srand(370);

  startingMoney = rand() % 7000 + 12;
  currentBalance = startingMoney;
  cout << "\nCongratulations " << playerName << "! You have $" << fixed << setprecision(2) << startingMoney;
  do
  {
    resetDealt(SIZE, drawn);
    ++roundCount;
    cout << "\nRound " << roundCount << endl << "**********";
    cout << "\nYou currently have $" << fixed << setprecision(2) << currentBalance;
    cout << "\nHow much would you like to wager? : ";
    cin >> wager;
    while(currentBalance < wager)
    {
      while(wager <= 0)
      {
        cout << "\nYou cannot bet a negative amount of money or zero. Please enter a valid wager : ";
        cin >> wager;
      }
      cout << "\nInsuffcient funds, You have " << currentBalance << " please use a valid amount : $";
      cin >> wager;
    }
  
    initializeDeck(deck, 52);
  
    playerHand[0] = deck[generateRandomCard(MIN,MAX, drawn)];
    dealerHand[0] = deck[generateRandomCard(MIN,MAX, drawn)];
    playerHand[1] = deck[generateRandomCard(MIN,MAX, drawn)];
    dealerHand[1] = deck[generateRandomCard(MIN,MAX, drawn)];
    playerSize +=1;
    dealerSize +=1;
  
    cout << "\n\nYour Hand : ";
    printHand(playerHand, playerSize);
    playerTotal = calculateHand(playerHand, 2);
    cout << "\nYour Hand Total Is : " << playerTotal;
    cout << "\n\nDealer Hand : " << dealerHand[0] << ", [HIDDEN CARD]";
    dealerTotal = calculateHand(dealerHand, 1);
    cout << "\nDealer Hand Total Is : " << dealerTotal;
    if(playerTotal == 21)
    {
      cout << "\n\nYou have blackjack!";
      break;
    }
    // START OF PLAYERS TURN //
    cout << "\n\nWould you like to Hit, Stay, Or Double Down? (h/s/d) : ";
    cin >> hitStayDD;
    // ASK IF USER IS DOUBLE DOWNING, THEN GIVE CARD AND STOP TURN
    if(hitStayDD == 'd' || hitStayDD == 'D')
    {
      currentBalance -= wager;
      cout << "\n\nYou Have chosen to Double Down!";
      playerHand[2] = deck[generateRandomCard(MIN,MAX, drawn)];
      cout << "\n\nYour Hand : "; 
      printHand(playerHand, playerSize);
      playerTotal = calculateHand(playerHand, 3);
      cout << "\nYour Hand Total Is : " << playerTotal;
    }
    else if(hitStayDD == 's' || hitStayDD == 'S')
    {
      cout << "\nYou Have chosen to Stay!";
    }
    while(hitStayDD != 's' || hitStayDD != 'S' || playerTotal > 21)
    {
      if(hitStayDD == 's' || hitStayDD == 'S')
        break;
      if(hitStayDD == 'd' || hitStayDD == 'D')
        break;
      playerSize+=1;
      cout << "You have chosen to Hit!" << endl;
      playerHand[playerSize] = deck[generateRandomCard(MIN,MAX, drawn)];
      cout << "\nYour Hand : ";
      printHand(playerHand, playerSize);
      playerTotal = calculateHand(playerHand, playerSize+1);
      cout << "\nYour Hand Total is : " << playerTotal;
      if(playerTotal > 21)
        {
          cout << "\nYou Bust!";
          playerTotal = 0;
          break;
        }
      cout << "\nWould you like to hit or stay? (h/s) : ";
      cin >> hitStayDD;
    }
    // START OF DEALERS TURN //
    cout << "\n\nDealer's Turn!" << "\nDealer's Hand :  "; printHand(dealerHand, dealerSize);
    ++dealerSize;
    dealerTotal = calculateHand(dealerHand, dealerSize);
    cout << "\nDealer's Total : " << dealerTotal;
    
    while(dealerTotal < 16)
    {
      cout << "\nThe Dealer Hits!";
      dealerHand[dealerSize] = deck[generateRandomCard(MIN,MAX, drawn)];
      cout << "\nDealer's Hand : ";
      printHand(dealerHand, dealerSize);
      cout << "\nDealer's Total : ";
      dealerSize++;
      dealerTotal = calculateHand(dealerHand, dealerSize);
      cout << dealerTotal;
    }
    if(dealerTotal > 21)
      dealerTotal = 0;
    if(isBlackjack(playerHand, 2) == true)
    {
      ++gameBlackjack;
      ++gameWins;
      playerWinState = 1;
    }
    else if(dealerTotal < playerTotal)
      {
        if(hitStayDD == 'd' || hitStayDD == 'D')
        {
          playerWinState = 5;
          gameWins ++;
        }
        else
        {
          gameWins ++;
          playerWinState = 2;
        }
      }
    else if(dealerTotal > playerTotal)
    {
      gameLoss++;
      playerWinState = 0;
    }
    else if(dealerTotal == playerTotal)
    {
      gameTies++;
      playerWinState = 3;
    }

    
    currentBalance = displayOutcome(currentBalance, playerWinState, wager);
    cout << "\n*****************************************";
    if(currentBalance == 0)
      {
        cout << "\n\nSorry, the Casino has taken all of your money, come back with a new mortage!";
        break;
      }

    cout << "\n\nWould you like to play again? (y/n) : ";
    cin >> playAgain;
  }while(playAgain == 'y' || playAgain == 'Y');

  netGainLoss = currentBalance - startingMoney;
  cout << endl << endl;
  displayGameSummary(roundCount, gameWins, gameBlackjack, gameLoss, gameTies, currentBalance, netGainLoss);

  
  cout << "\nThank you for playing CodeJack, The Blackjack Simulator!";
  return 0;
}

