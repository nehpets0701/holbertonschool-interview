#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void topple(int grid1[3][3], int grid2[3][3]);
void addPiles(int grid1[3][3], int grid2[3][3]);
int isStable(int grid[3][3]);
void copy(int grid1[3][3], int grid2[3][3]);

#endif
