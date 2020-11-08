/**
*
* Author: C. Fernandes
* clintonf@gmail.com
* Copyright (c) 2020. All rights reserved.
**/

#include <string>
#include <utility>

using namespace::std;

static constexpr int MIN_COORDINATE = 0;
static constexpr int MAX_COORDINATE = 1000;

#pragma once

class City {
private:
    string name;
    int xPosition = 0;
    int yPosition = 0;

public:
    static int cityCount;

    City();
    City(string newName, int newX, int newY): name(std::move(newName)), xPosition(newX), yPosition(newY){}

    int getXPosition() const { return xPosition; }

    int getYPosition() const { return yPosition; }

    const string& getName() const { return name; }

    /**
     * Calculates the shortest distance between this city and another.
     *
     * @param otherCity City& the other city
     * @return double
     */
    double getDistanceTo(City &otherCity);
};



