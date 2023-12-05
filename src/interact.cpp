#include "interact.h"

void interact_simple(table &table, int p1, int p2)
{
  int NUM_CELLS = table[0].size();
  for (int cell = 0; cell < NUM_CELLS; ++cell)
  {
    double prod = table[p1][cell]*table[p2][cell];
    if (table[p1][cell] < table[p2][cell])
    {
      table[p1][cell] -= prod; 
      table[p2][cell] += prod; 
    }
    else
    {
      table[p1][cell] += prod; 
      table[p2][cell] -= prod; 
    }
  } 
}
