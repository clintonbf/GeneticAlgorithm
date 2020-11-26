/**
*
* Author: C. Fernandes, Karel Chanivecky
* clintonf@gmail.com
* Copyright (c) 2020. All rights reserved.
**/

#pragma once

#include <algorithm>
#include <random>
#include "Tour.hpp"

Tour::Tour( const Tour &other ) {
    cities = other.cities;
    fitness = other.fitness;
}

void Tour::mutate() {
    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<> distribution{};
    double mutation_coeff = distribution(generator);
    for(int i=0; i < cities.size(); i++) {
        if (MUTATION_RATE <= mutation_coeff) {
            continue; // do not mutate
        }
        // mutate
        // first and last cities only have one adjacent city each
        if (i == 0) {
            swap(cities[0], cities[1]);
            continue;
        }
        if (i == cities.size() - 1) {
            swap(cities[cities.size() - 2], cities[i]);
            continue;
        }
        double adjacentCityChoice = distribution(generator);
        if (adjacentCityChoice < 0.5) {
            swap(cities[i - 1], cities[i]);
        } else {
            swap(cities[i + 1], cities[i]);
        }
    }
    evaluateFitness();
}

void Tour::randomizeOrder() {
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(cities.begin(), cities.end(), g);
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

double Tour::getDistance() const {
    double distance{0};
    for ( int i = 0; i < cities.size() - 1; ++i ) {
        distance += cities[i].getDistanceTo(cities[i + 1]);
    }
    distance += cities[0].getDistanceTo(cities[cities.size() - 1]);
    return distance;
}

void Tour::evaluateFitness() {
    fitness = 1 / getDistance();
}

void swapTour(Tour &lhs, Tour &rhs) {
    swap(lhs.cities, rhs.cities);
    swap(lhs.fitness, rhs.fitness);
}

Tour &Tour::operator=( Tour rhs ) {
    swapTour(*this, rhs);
    return *this;
}

ostream &operator<<( ostream &os, const Tour &tour ) {
    os << "fitness: " << tour.fitness << " cities: ";
    for (const City &c : tour.cities) {
        os << " " << c;
    }
    return os;
}

double Tour::getFitness() const {
    return fitness;
}

