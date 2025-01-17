#include <iostream>
#include "TourDriver.hpp"

constexpr int NUMBER_OF_CITIES = 32;
constexpr int NUMBER_OF_TOURS = 32;
constexpr double FITNESS_THRESHOLD = 0.0000599945;
//constexpr int FITNESS_THRESHOLD = 25;

using namespace std;

int main() {
    TourDriver td{NUMBER_OF_CITIES, NUMBER_OF_TOURS, FITNESS_THRESHOLD};
    td.get_best_tour();

    return 0;
}

