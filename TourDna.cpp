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

#include <iostream>
#include <set>
#include <random>

#include "TourDna.hpp"

TourDNA::TourDNA( vector<Tour> &tours ) : tours( tours ) {
    promoteElite();
    thereIsAReasonToBelieveThereIsANewElite = false;
}

int TourDNA::findIndexOfEliteTour( vector<Tour> &toursVector ) {
    double minScore;
    int eliteIndex{0};
    Tour localElite;
    localElite = toursVector[ 0 ];
    minScore = localElite.getFitness();

    for ( int i = 0; i < toursVector.size(); i++ ) {
        double candidateScore = toursVector[ i ].getFitness();
        if (  candidateScore < minScore ) {
            localElite = toursVector[ i ];
            minScore = candidateScore;
            eliteIndex = i;
        }
    }

    return eliteIndex;
}

void TourDNA::promoteElite() {
    int eliteIndex = findIndexOfEliteTour( tours );

    using std::swap;
    swap(tours[0], tours[eliteIndex]);
}

Tour TourDNA::getElite() {
    if (thereIsAReasonToBelieveThereIsANewElite) {
        promoteElite();
    }

    return tours[0];
}

vector<Tour> TourDNA::createParentPool() {
    constexpr int poolSize = 5;
    vector<Tour> pool;
    vector<Tour> poolVector;

    while ( pool.size() != poolSize ) {
        int index = getRandomInteger( 1, ( int ) tours.size());

        pool.emplace_back( tours[ index ] );
    }

    return pool;
}

Tour TourDNA::crossParents( const Tour &buck, const Tour &doe ) {
    int upperBound = ( int ) buck.getCities().size();

    int buckIndexToCopyTo = getRandomInteger( 0, upperBound );
    Tour fawn;

    vector<City> buckCities = buck.getCities();
    vector<City> doeCities = doe.getCities(); // This line will empty the vector above.

    for ( int i = 0; i <= buckIndexToCopyTo; i++ ) { //Step 4.3 of the algorithm
        fawn.addCity( buckCities[ i ] );
    }

    for ( int i = ( buckIndexToCopyTo + 1 ); i < doe.getCities().size(); i++ ) { //Step 4.3 of the algorithm (cont.)
        if ( !fawn.containsCity( doeCities[ i ] )) {
            fawn.addCity( doeCities[ i ] );
        }
    }

    fawn.evaluateFitness();
    return fawn;
}

void TourDNA::crossover() {
    vector<Tour> crossedTours;
    crossedTours.emplace_back( tours[ 0 ] );
    int numberOfCitiesOfWeirdSize = 0;

    // TODO remove when done debugging
    for ( int i = 0; i < tours.size(); i++) {
        vector<City> cities = tours[i].getCities();
        if (cities.size() != 32) {
            int foo(0); // TODO breakpoint here
            numberOfCitiesOfWeirdSize++;
        }
        for (const City &c : cities) {
            if (c.getName().empty()) {
                int fooo(0);// TODO breakpoint here
            }
        }
    }

    //4.3 Pick two sets of 5 random tours form the original population
    // Find the fittest two parents in each set
    while ( crossedTours.size() != tours.size()) {
        vector<Tour> bucks = createParentPool();
        int eliteBuck = findIndexOfEliteTour( bucks );

        vector<Tour> does = createParentPool();
        int eliteDoe = findIndexOfEliteTour( does );

        Tour buck = bucks[ eliteBuck ];
        Tour doe = does[ eliteDoe ];

        //Cross the parents
        crossedTours.emplace_back( crossParents( buck, doe ));
    }

    //4.4 Replace all the Tours in our Population (except the Elite Tour) with the new crosses.
    tours = crossedTours;
}

void TourDNA::mutate() {
    for (int i = 1; i < tours.size(); i++) {
        tours.at(i).mutate();
    }
}

void TourDNA::improve() {
    crossover();
    mutate();
    thereIsAReasonToBelieveThereIsANewElite = true;
}

ostream& operator<< (ostream& os, const TourDNA& t) {
    for (Tour tour: t.getTours()) {
        cout << tour << endl;
    }
}

int TourDNA::getRandomInteger( int lowerBound, int upperBound ) {
    if ( upperBound <= lowerBound ) {
        return lowerBound;
    }
    random_device rd;
    mt19937 generator( rd());
    uniform_int_distribution<> distribution( lowerBound, upperBound - 1 );


    return distribution( generator );
}
