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

#include "TourDriver.hpp"

void TourDriver::generateTours( const int numberOfTours) {
    for ( int i = 0; i < numberOfTours; ++i ) {
        tours.emplace_back(Tour{cities});
    }
}

void TourDriver::generateCities( const int numberOfCities ) {
    for ( int i = 0; i < numberOfCities; ++i ) {
        cities.emplace_back(City());
    }
}

Tour TourDriver::makeBestTour() {
    Tour bestTour = dna.getBestTour();
    int iterations{ 0 };
    while (bestTour.get_fitness() < fitness_threshold && iterations < MAX_ITER_COUNT ) {
        dna.improve();
        bestTour = dna.getBestTour();
        iterations++;
    }
    return dna.getBestTour();
}

TourDriver::TourDriver( const int numberOfCities, const int numberOfTours, double fitness_threshold )
        : fitness_threshold( fitness_threshold), bestTour(){
    generateCities(numberOfCities);
    generateTours(numberOfTours);
    dna = TourDNA{tours};
}
