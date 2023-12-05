#include "init.h"

#include <cstdlib>
#include <ctime>

#define MAX_RAND 1000.0

void init_random(table &table) {
  int NUM_CELLS = table[0].size();
  int NUM_PLAYERS = table.size();
  for (int cell = 0; cell < NUM_CELLS; ++cell) {
    double sum = 0;
    for (int player = 0; player < NUM_PLAYERS; ++player) {
      double val = rand() % RAND_MAX;
      table[player][cell] = val;
      sum += val;
    }

    for (int player = 0; player < NUM_PLAYERS; ++player)
      table[player][cell] /= sum;
  }
}

void init_random_equal_mass(table &t) {}
