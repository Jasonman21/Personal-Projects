#include "beeInfestation.h"
#include <iostream>

void beeAirdrop(char world[10][10], int xCoord, int yCoord)
{
  if(xCoord >= 0 && xCoord < 10 && yCoord >= 0 && yCoord < 10)
  {
    if(world[xCoord][yCoord] == '_')
    {
      world[xCoord][yCoord] = 'B';
      return;
    }
    else if(world[xCoord][yCoord] == 'B')
    {
      const char midPoint = world[xCoord][yCoord];
      for(int yC = -1; yC <= 1; yC++)
        {
          for(int xC = -1; xC <= 1; xC++)
            { 
              if((xCoord - xC) < 0 || (yCoord - yC) < 0) 
              {
                continue;
              }
              else if(world[xCoord - xC][yCoord - yC] == '_')
              {
                world[xCoord - xC][yCoord - yC] = 'B';
              }
              else if(world[xCoord - xC][yCoord - yC] == 'B')
              {
                world[xCoord - xC][yCoord - yC] = 'W';
              }
              else
              world[xCoord - xC][yCoord - yC] = 'T';
                
            }
        }
       world[xCoord][yCoord] = midPoint;
    }
    else if(world[xCoord][yCoord] == 'W')
    {
      const char midPoint = world[xCoord][yCoord];
      for(int yC = -1; yC <= 1; yC++)
        {
          for(int xC = -1; xC <= 1; xC++)
            {
              if((xCoord - xC) < 0 || (yCoord - yC) < 0) 
                {
                  continue;
                }
              else if(world[xCoord - xC][yCoord - yC] == '_')
              {
                world[xCoord - xC][yCoord - yC] = 'W';
              }
              else if(world[xCoord - xC][yCoord - yC] == 'B')
              {
                world[xCoord - xC][yCoord - yC] = 'W';
              }
              else
              world[xCoord - xC][yCoord - yC] = 'T';
              
            }
        }
       world[xCoord][yCoord] = midPoint;
    }
    else
      for(int yC = -1; yC <= 1; yC++)
        {
          for(int xC = -1; xC <= 1; xC++)
            {
              world[xCoord - xC][yCoord - yC] = 'T';
            }
        } 
  }
}
