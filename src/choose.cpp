#include "choose.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>


int choose_random(table &table)
{
  int NUM_PLAYERS = table.size();
  return rand()%NUM_PLAYERS;
}
