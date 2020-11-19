/**
*
* Author: C. Fernandes, Karel Chanivecky
* clintonf@gmail.com
* Copyright (c) 2020. All rights reserved.
**/

#pragma once

#include <random>
#include "City.hpp"

int City::cityCount = 1;

City::City( const City &other ) {
    name = other.name;
    xPosition = other.xPosition;
    yPosition = other.yPosition;
}

City::City() {
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<> distribution(MIN_COORDINATE, MAX_COORDINATE);

  xPosition = distribution(generator);
  yPosition = distribution(generator);

  name = "city_" + std::to_string(cityCount++);
  cityCount++;
}

double City::getDistanceTo(const City &otherCity) const {
    int a = abs(xPosition - otherCity.getXPosition());
    int b = abs(yPosition - otherCity.getYPosition());

    double distanceSquared = pow(a, 2) + pow(b, 2);

    return pow(distanceSquared, 0.5);
}

ostream &operator<<( ostream &os, const City &city ) {
    os << city.name;
    return os;
}

bool City::operator==( const City &rhs ) const {
    return name == rhs.name &&
           xPosition == rhs.xPosition &&
           yPosition == rhs.yPosition;
}

bool City::operator!=( const City &rhs ) const {
    return !( rhs == *this );
}

City &City::operator=( City rhs ) {
    swapCity(*this, rhs);
    return *this;
}

void swapCity( City &lhs, City &rhs ) {
    swap(lhs.name, rhs.name);
    swap(lhs.xPosition, rhs.xPosition);
    swap(lhs.yPosition, rhs.yPosition);
}

