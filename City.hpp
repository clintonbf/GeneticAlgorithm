/**
*
* Author: C. Fernandes
* clintonf@gmail.com
* Copyright (c) 2020. All rights reserved.
**/

#include <string>
#include <utility>
#include <ostream>

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
    City(const City &other);
    /**
     * Get the position of the city in the X axis.
     * @return the position of the city in the X axis.
     */
    int getXPosition() const { return xPosition; }

    int getYPosition() const { return yPosition; }

    const string& getName() const { return name; }

    /**
     * Calculates the shortest distance between this city and another.
     *
     * @param otherCity City& the other city
     * @return double
     */
    double getDistanceTo(const City &otherCity) const;

    /**
    * Insert a city into output stream
    * @param os the output stream
    * @param city a City
    * @return the output stream, after the fact
    */
    friend ostream &operator<<( ostream &os, const City &city );

    bool operator==( const City &rhs ) const;

    bool operator!=( const City &rhs ) const;

    City & operator=(City rhs);

    friend void swapCity(City &lhs, City &rhs);
};



