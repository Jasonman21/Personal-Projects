#ifndef BEEINFESTATION_H
#define BEEINFESTATION_H


//Desc: This function will take the world array and x & y coordinates to vizualize the world, and then will summon airdrops at the respective locations utilizing the input.txt file's lines
//Pre: Requires the world array to have a 10x10 array filled with '_', 'B', 'W', and 'T' characters only and requires a seperate loop to take in the board from the inputFile.txt file
//Post: The function modifies the world array using the x and y coordinates taken from the inputFile.txt file.
void beeAirdrop(char world[10][10], int xCoord, int yCoord);

#endif
