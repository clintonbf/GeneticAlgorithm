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

#ifndef INC_3522_A02_TOURDNA_HPP
#define INC_3522_A02_TOURDNA_HPP

#include <vector>
#include "Tour.hpp"

using namespace std;

class TourDNA {
private:
    vector<Tour> tours;

    /*
     * Finds the fittest Tour in a group of Tours.
     */
    int findIndexOfEliteTour(vector<Tour> &toursVector);

    /**
     * Gets a random integer, inclusive of specified lower and upper bounds.
     *
     * @param lowerBound int, lower bound to generate from
     * @param upperBound  int, upper bound to generate from, not inclusive
     * @return int
    */
    int getRandomInteger(int lowerBound, int upperBound);

    /**
     * Creates a pool of candidate Tours to select parents from.
     *
     * @return vector<Tour>
     */
    vector<Tour> createParentPool();

    /**
     * Performs crossover over of two parent Tours.
     *
     * @param buck a parent Tour.
     * @param doe a parent Tour.
     * @return Tour
     */
    Tour crossParents(const Tour& buck, const Tour& doe);

public:
    TourDNA() = default;

    explicit TourDNA( vector<Tour> &tours);
    double getBestFitness() { return tours[0].getFitness(); };
    Tour getElite() { return tours[0]; };
    /**
    * Performs the cross-over step of the genetic algorithm.
    *
    * @return vector<Tour>
    */
    void improve();
};


#endif //INC_3522_A02_TOURDNA_HPP
