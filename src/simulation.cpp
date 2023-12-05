#include "simulation.h"
#include "model.h"
#include "types.h"
#include <fstream>

void simple_simulation(int NUM_PLAYERS, int NUM_CELLS, int NUM_IT,
                       std::function<void(table &)> init,
                       std::function<int(table &)> choose1,
                       std::function<int(table &)> choose2,
                       std::function<void(table &, int, int)> interact) {
  table t(NUM_PLAYERS, person(NUM_CELLS, 0));
  init(t);

  int it = 0;
  while (it < NUM_IT) {
    int p1 = choose1(t);
    int p2 = choose1(t);

    if (p1 != p2)
      interact(t, p1, p2);

    it++;
  }
}

void simple_simulation_statistics(
    int NUM_PLAYERS, int NUM_CELLS, int NUM_IT,
    std::function<void(table &)> init, std::function<int(table &)> choose1,
    std::function<int(table &)> choose2,
    std::function<void(table &, int, int)> interact) {

  time_t time_now = time(0);
  struct tm * now = localtime( & time_now );
  char buffer [80];
  strftime (buffer,80,"./simulations/simple_simulation-%Y-%m-%d.out",now);
  std::ofstream out(buffer);

  table t(NUM_PLAYERS, person(NUM_CELLS, 0));
  init(t);

  int it = 0;
  while (it < NUM_IT) {
    for(int p = 0; p < NUM_PLAYERS; p++)
      out << mass(t[p]) << "\t"; 
    out << std::endl;

    int p1 = choose1(t);
    int p2 = choose1(t);

    if (p1 != p2)
      interact(t, p1, p2);

    it++;
  }

  out.close();
  
    }
