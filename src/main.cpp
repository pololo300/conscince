#include <iostream>

#include "init.h"
#include "choose.h"
#include "interact.h"
#include "simulation.h"


int main (void)
{
  srand((unsigned int)(time(NULL)));

  simple_simulation_statistics(
      100,
      100,
      10000,
      init_random,
      choose_random,
      choose_random,
      interact_simple
  );
}
