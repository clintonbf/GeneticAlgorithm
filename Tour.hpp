/**
*
* Author: C. Fernandes
* clintonf@gmail.com
* Copyright (c) 2020. All rights reserved.
**/

#include "City.hpp"

#include <vector>
#pragma once

class Tour {
private:
    vector<City> cities;
    double fitness = 0;

public:
    Tour(vector<City> newCities): cities(newCities){}

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
    bool containsCity(City& city); //Todo: implementation

    const vector<City>& getCities() const { return cities; }

};



