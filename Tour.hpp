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
    void evaluateFitness();
    void swapCities( unsigned long a, unsigned long b);
public:
    explicit Tour(vector<City> &newCities): cities(newCities){
        randomizeOrder();
        evaluateFitness();
    }

    void mutate(); //Todo: implementation

    void randomizeOrder(); //Todo: implementation

    /**
     * Add a City to the Tour.
     * @param c City& City to add
     */
    void addCity(City& c); //Todo: implementation

    /**
     * Get if a tour contains a City.
     *
     * @param city City& the City to search for
     * @return boolean
     */
    bool containsCity(const City& city); //Todo: implementation

    const vector<City>& getCities() const { return cities; }

    friend ostream &operator<<( ostream &os, const Tour &tour );
};



