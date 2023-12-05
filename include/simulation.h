#ifndef __SIMULATION__
#define __SIMULATION__

#include "types.h"
#include <functional>

void simple_simulation(int NUM_PLAYERS, int NUM_CELLS, int NUM_IT,
                       std::function<void(table &)> init,
                       std::function<int(table &)> choose1,
                       std::function<int(table &)> choose2,
                       std::function<void(table &, int, int)> interact);

void simple_simulation_statistics(
    int NUM_PLAYERS, int NUM_CELLS, int NUM_IT,
    std::function<void(table &)> init, std::function<int(table &)> choose1,
    std::function<int(table &)> choose2,
    std::function<void(table &, int, int)> interact);

#endif // !__SIMULATION__
