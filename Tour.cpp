/**
*
* Author: C. Fernandes, Karel Chanivecky
* clintonf@gmail.com
* Copyright (c) 2020. All rights reserved.
**/

#pragma once

#include <random>
#include "Tour.hpp"

void Tour::mutate() {

}

void Tour::swapCities( const int a, const int b) {
    City &t = cities[a];
    cities[a] = cities[b];
    cities[b] = t;
}

void Tour::randomizeOrder() {
    random_device rd;
    mt19937 generator(rd());
    for ( int i = cities.size(); 0 < i ; --i ) {
        uniform_int_distribution<> distribution(0, i);
        int swapIndex = distribution( generator);
        swapCities( i, swapIndex );
    }
}

void Tour::addCity( City &c ) {
    cities.emplace_back(c);
}

bool Tour::containsCity( const City &city ) {
    for (const City &c : cities) {
        if (c == city) {
            return true;
        }
    }
    return false;
}

void Tour::evaluateFitness() {
    for ( int i = 0; i < cities.size() - 1; ++i ) {
        fitness += cities[i].getDistanceTo(cities[i + 1]);
    }
}

ostream &operator<<( ostream &os, const Tour &tour ) {
    os << "fitness: " << tour.fitness << "cities:";
    for (const City &c : tour.cities) {
        os << " " << c;
    }
    return os;
}
