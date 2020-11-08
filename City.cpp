/**
*
* Author: C. Fernandes
* clintonf@gmail.com
* Copyright (c) 2020. All rights reserved.
**/

#pragma once

#include <random>
#include "City.hpp"

int City::cityCount = 1;

City::City() {
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<> distribution(MIN_COORDINATE, MAX_COORDINATE);

  xPosition = distribution(generator);
  yPosition = distribution(generator);

  name = "City_" + std::to_string(cityCount);
  cityCount++;
}

double City::getDistanceTo(City &otherCity) {
    int a = abs(xPosition - otherCity.getXPosition());
    int b = abs(yPosition - otherCity.getYPosition());

    double distanceSquared = pow(a, 2) + pow(b, 2);

    return pow(distanceSquared, 0.5);
}
