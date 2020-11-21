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

#include <iostream>
#include "TourDriver.hpp"

void TourDriver::generateTours( const int numberOfTours ) {
    for ( int i = 0; i < numberOfTours; ++i ) {
        tours.emplace_back( Tour{ cities } );
    }
}

void TourDriver::generateCities( const int numberOfCities ) {
    for ( int i = 0; i < numberOfCities; ++i ) {
        cities.emplace_back( City());
    }
}

void TourDriver::report( const Tour &newTour, const Tour &oldTour, const double firstBestDistance,
                         const int iterations ) const {
    cout << "ITERATION: " << iterations << endl;
    cout << "Best previous distance: " << oldTour.getDistance() << endl;
    cout << "New distance: " << newTour.getDistance() << endl;
    cout << "Distance improvement: " << oldTour.getDistance() - newTour.getDistance() << endl;
    cout << "Total improvement: " << firstBestDistance - newTour.getDistance() << "\n" << endl;
}

void TourDriver::finalReport( const Tour &newTour, const Tour &baseTour, const int iterations ) {
    cout << "FINAL REPORT: " << endl;
    report( newTour, baseTour, baseTour.getDistance(), iterations );
    cout << "Fitness target achieved: " << boolalpha << ( fitnessThreshold <= newTour.getFitness()) << endl;
    cout << "The best tour: " << newTour << endl;
    cout << "The initial tour: " << baseTour << endl;
}

void TourDriver::makeBestTour() {
    Tour baseTour = dna.getElite();
    double firstBestDistance = baseTour.getDistance();
    Tour currentEliteTour = baseTour;
    int totalIterations{ 0 };
    while ( currentEliteTour.getFitness() < fitnessThreshold && totalIterations < MAX_ITER_COUNT ) {
        dna.improve();
        Tour newPossibleElite = dna.getElite();
        totalIterations++;
        report( newPossibleElite, currentEliteTour, firstBestDistance, totalIterations );
        if ( currentEliteTour.getFitness() < newPossibleElite.getFitness()) {
            currentEliteTour = newPossibleElite;
        }
    }
    this->bestTour = currentEliteTour;
    finalReport(baseTour, currentEliteTour, totalIterations);
}

TourDriver::TourDriver( const int numberOfCities, const int numberOfTours, double fitness_threshold )
        : fitnessThreshold( fitness_threshold ), bestTour() {
    generateCities(numberOfCities);
    generateTours(numberOfTours);
    dna = TourDNA{tours};
    makeBestTour();
}

const Tour &TourDriver::get_best_tour() const {
    return bestTour;
}
