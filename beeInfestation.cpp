//Programmer Name: Jason Dieckhaus Jr
//Date : 10/28/24
//file: HW6jasond.cpp
//Assignment: Homework 6
//Purpose: To Fulfill all requirements of the assignment HW6 from class and used within this program

#include "beeInfestation.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  char world[10][10];

  
  ifstream inputFile("input.txt");
  if(!inputFile.is_open())
  {
    cout << "Error opening input file." << endl;
    return 1;
  }
  ofstream outputFile("output.txt");
  if(!outputFile.is_open())
  {
    cout << "Error opening output file." << endl;
    return 1;
  }
    
    for(int col = 0; col < 10; col++)
    {
      string inputLine;
      if(getline(inputFile, inputLine))
      {
        for(int row = 0; row < 10; row++)
          {
            world[col][row] = inputLine[row];
          }
      }
    }
  int xcoord, ycoord;
  while(inputFile >> xcoord)
    {
      inputFile >> ycoord;
      beeAirdrop(world, xcoord, ycoord);
    }


  for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
        {
          outputFile << world[i][j] << " ";
          if(j % 9 == 0 && j != 0)
          outputFile << endl;
        }
      cout << endl;
    }

  return 0;
}
