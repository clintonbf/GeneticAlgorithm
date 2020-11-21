/**
*
* Author: C. Fernandes, Karel Chanivecky
* clintonf@gmail.com
* Copyright (c) 2020. All rights reserved.
**/

#include "City.hpp"

#include <vector>
#include <ostream>

#pragma once

using namespace std;

class Tour {
private:
    static constexpr double MUTATION_RATE = 0.15;
    vector<City> cities;
    double fitness = 0;

    /**
     * Swap the positions of two cities in the tour
     * @param a index of a city
     * @param b index of a city
     */
    void swapCities( unsigned long a, unsigned long b);

    /**
    * Randomize the order of the tour
    */
    void randomizeOrder();
public:

    Tour() = default;

    explicit Tour(vector<City> &newCities): cities(newCities){
        randomizeOrder();
        evaluateFitness();
    }

    /**
    * Evaluate the fitness of the tour.
    */
    void evaluateFitness();

    Tour(const Tour &other);

    /**
     * Slightly change the order of the cities in tour.
     *
     * There is a 0.15^n chance the order will not change.
     */
    void mutate();

    /**
     * Add a City to the Tour.
     * @param c City& City to add
     */
    void addCity(City& c);

    /**
     * Get the fitness.
     * @return the fitness of the tour
     */
    double getFitness() const;

    /**
     * Get the total distance for the tour.
     * @return the total distance
     */
    double getDistance() const;

    /**
     * Get if a tour contains a City.
     *
     * @param city City& the City to search for
     * @return boolean
     */
    bool containsCity(const City& city);

    /**
     * Get the cities in the tour.
     * @return a vector of cities
     */
    const vector<City>& getCities() const { return cities; }

    Tour & operator=(Tour rhs);

    /**
     * Insert a tour into output stream
     * @param os the output stream
     * @param tour a tour
     * @return the output stream, after the fact
     */
    friend ostream &operator<<( ostream &os, const Tour &tour );

    /**
     * Assignment operator helper
     */
    friend void swapTour( Tour &lhs, Tour &rhs );
};



