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

#ifndef INC_3522_A02_TOURDRIVER_HPP
#define INC_3522_A02_TOURDRIVER_HPP


#include "Tour_Dna.hpp"

using namespace std;

class TourDriver {
private:
    static constexpr int MAX_ITER_COUNT = 1000;
    TourDNA dna;
    Tour bestTour;
    vector<Tour> tours;
    vector<City> cities;
    double fitness_threshold;
    void generateTours( int numberOfTours);
    void generateCities( int numberOfCities );
public:
    TourDriver( const int numberOfCities, const int numberOfTours, const double fitness_threshold );
    Tour makeBestTour();
};


#endif //INC_3522_A02_TOURDRIVER_HPP
