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


#include "TourDna.hpp"

using namespace std;

class TourDriver {
private:
    static constexpr int MAX_ITER_COUNT = 1000;
    TourDNA dna;
    Tour bestTour;
    vector<Tour> tours;
    vector<City> cities;
    double fitnessThreshold;

    /**
     * Print final report.
     * @param newTour the last best tour
     * @param baseTour the first best tour
     */
    void finalReport( const Tour &newTour, const Tour &baseTour, int iterations);

    /**
     * Print iteration report.
     * @param newTour the new best tour
     * @param baseTour the previous best tour
     */
    void report( const Tour &newTour, const Tour &oldTour, double firstBestDistance, int iterations ) const;

    /**
     * Generates a given number of tours based on the instance cities.
     * @param numberOfTours the number of tours
     */
    void generateTours( int numberOfTours );

    /**
     * Generate a given number of cities.
     * @param numberOfCities the number of cities
     */
    void generateCities( int numberOfCities );

    /**
     * Get the most evolved tour.
     */
    void makeBestTour();

public:

    /**
     * Create a tour driver with a given number of cities, tours and target fitness.
     *
     * Will automatically generate cities, tours and evolve into the best tour
     *
     * @param numberOfCities the number of cities in the tour
     * @param numberOfTours the number or tours to evaluate
     * @param fitness_threshold the desired fitness threshold
     */
    TourDriver( int numberOfCities, int numberOfTours, double fitness_threshold );

    /**
     * Get the best tour.
     * @return
     */
    const Tour &get_best_tour() const;

    vector<Tour> getTours() { return tours; }
};


#endif //INC_3522_A02_TOURDRIVER_HPP
