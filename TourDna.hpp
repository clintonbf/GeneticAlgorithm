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
     * Makes a Tour the Elite tour.
     */
    void promoteElite();

    /**
     * Gets a random integer, inclusive of specified lower and upper bounds.
     *
     * @param lowerBound int, lower bound to generate from
     * @param upperBound  int, upper bound to generate from, not inclusive
     * @return int
    */
    static int getRandomInteger(int lowerBound, int upperBound);

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

    /**
     * Performs the crossing-over stage of the genetic algorithm.
     */
    void crossover();

    /**
     * Mutates every Tour (except the Elite)
     */
    void mutate();

public:
    TourDNA() = default;
    explicit TourDNA( vector<Tour> &tours ) : tours( tours ) {  }

    /**
     * Gets the current elite Tour in the set of Tours.
     *
     * @return Tour
     */
    Tour getElite();

    /**
     * Gets the Tours in the set.
     *
     * @return vector<Tour>
     */
    vector<Tour> getTours() const { return tours; }

    /**
    * Performs crossing-over and mutation in the genetic algorithm.
    */
    void improve();

    friend ostream& operator<< (ostream& os, const TourDNA& t);
};


#endif //INC_3522_A02_TOURDNA_HPP
