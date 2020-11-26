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
    return tours[0];
}

vector<Tour> TourDNA::createParentPool() {
    constexpr int poolSize = 5;
    vector<Tour> pool;

    for (int i = 0; i < poolSize; i++) {
        //lowerBound = 1 to prevent including the elite in the pool
        int index = getRandomInteger( 1, ( (int) tours.size() - 1) );

        pool.emplace_back( tours[ index ] );
    }

    return pool;
}

Tour TourDNA::crossParents( const Tour &buck, const Tour &doe ) {
    int upperBound = ( int ) buck.getCities().size();

    int buckIndexToCopyTo = getRandomInteger( 0, (upperBound - 1) );
    Tour fawn;

    vector<City> buckCities = buck.getCities();
    vector<City> doeCities = doe.getCities();

    for ( int i = 0; i <= buckIndexToCopyTo; i++ ) { //Step 4.3 of the algorithm
        fawn.addCity( buckCities.at(i) );
    }

    int doeSize = doeCities.size();

    for ( int i = 0; i < doeSize; i++ ) { //Step 4.3 of the algorithm (cont.)
        if ( !fawn.containsCity( doeCities.at(i) ) ) {
            fawn.addCity( doeCities.at(i) );
        }
    }

    fawn.evaluateFitness();

   return fawn;
}

void TourDNA::crossover() {
    vector<Tour> fawns;
    fawns.emplace_back(tours[ 0 ] ); //This is the elite

    //4.3 Pick two sets of 5 random tours form the original population
    // Find the fittest two parents in each set
    while (fawns.size() < tours.size()) {
        vector<Tour> bucks = createParentPool();
        int eliteBuckIndex = findIndexOfEliteTour(bucks );

        vector<Tour> does = createParentPool();
        int eliteDoeIndex = findIndexOfEliteTour(does );

        Tour buck = bucks[ eliteBuckIndex ];
        Tour doe = does[ eliteDoeIndex ];

        //Cross the parents
        Tour fawn = crossParents(buck, doe);
        fawns.emplace_back( fawn );
    }

    //4.4 Replace all the Tours in our Population (except the Elite Tour) with the new crosses.
    tours = fawns;
}

void TourDNA::mutate() {
    //Start at 1: don't mutate elite
    for (int i = 1; i < tours.size(); i++) {
        tours.at(i).mutate();
    }
}

void TourDNA::improve() {
    promoteElite(); //Step 3
    crossover();    //Step 4
    mutate();       //Step 4 (cont)
}

ostream& operator<< (ostream& os, const TourDNA& t) {
    for (const Tour& tour: t.getTours()) {
        cout << tour << endl;
    }
}

int TourDNA::getRandomInteger( int lowerBound, int upperBound ) {
    if ( upperBound <= lowerBound ) {
        return lowerBound;
    }
    random_device rd;
    mt19937 generator( rd());
    uniform_int_distribution<> distribution( lowerBound, upperBound );

    return distribution( generator );
}
