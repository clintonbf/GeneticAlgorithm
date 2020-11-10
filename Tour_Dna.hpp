/**
 * 11/9/2020
 * Created by Karel Chanivecky Garcia.
 * A01052674
 *
 * BCIT CST
 * Set O Datacomm
 *
 * 3522_A02
 */

#ifndef INC_3522_A02_TOUR_DNA_HPP
#define INC_3522_A02_TOUR_DNA_HPP

#include <vector>
#include "Tour.hpp"

using namespace std;

class TourDNA {
private:
    vector<Tour> tours;
    void findNewElite();
    void crossover();
    vector<Tour> selectParents();
public:
    TourDNA() = default;
    TourDNA( vector<Tour> &tours);
    double getBestFitness();
    void improve();
    Tour getBestTour();
};


#endif //INC_3522_A02_TOUR_DNA_HPP
