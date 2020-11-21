#include <iostream>
#include "TourDriver.hpp"

constexpr int NUMBER_OF_CITIES = 32;
constexpr int NUMBER_OF_TOURS = 32;
constexpr int FITNESS_THRESHOLD = 100;

using namespace std;
void testTourDNA() {
    //Build a tour
    TourDriver td{10, 15, FITNESS_THRESHOLD};


}

int main() {
//    TourDriver td{NUMBER_OF_CITIES, NUMBER_OF_TOURS, FITNESS_THRESHOLD};
//    td.get_best_tour();

    testTourDNA();
    return 0;
}

