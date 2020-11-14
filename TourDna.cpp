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

#include <set>
#include <random>

#include "TourDna.hpp"

TourDNA::TourDNA(vector<Tour> &tours) : tours(tours) {
    int eliteIndex = findIndexOfEliteTour(tours);

    Tour& tempTour = tours[0];
    tours[0] = tours[eliteIndex];
    tours[eliteIndex] = tempTour;
}

int TourDNA::findIndexOfEliteTour(vector<Tour> &toursVector) {
    double minScore;
    int eliteIndex;
    Tour localElite;

    localElite = toursVector[0];
    minScore = localElite.getFitness();

    for (int i = 1; i < toursVector.size(); i++) {
        if (toursVector[i].getFitness() < minScore ) {
            localElite = toursVector[i];
            eliteIndex = i;
        }
    }

    return eliteIndex;
}

int TourDNA::getRandomInteger(int lowerBound, int upperBound) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(lowerBound, upperBound);

    return distribution(generator);
}

vector<Tour> TourDNA::createParentPool() {
    constexpr int poolSize = 5;
    vector<Tour> pool;
    vector<Tour> poolVector;

    while (pool.size() != poolSize) {
        int index = getRandomInteger(1, tours.size());

        pool.emplace_back(tours[index]);
    }

    return pool;
}

Tour TourDNA::crossParents(const Tour& buck, const Tour& doe) {
    int indexEnd = getRandomInteger(0, buck.getCities().size());
    Tour child;

    vector<City> buckCities = buck.getCities();
    vector<City> doeCities = doe.getCities();

    for (int i = 0; i <= indexEnd; i++) {
        child.addCity(buckCities[i]);
    }

    for (int i = (indexEnd + 1); i < doe.getCities().size(); i++) {
        if (! child.containsCity(doeCities[i])) {
            child.addCity(doeCities[i]);
        }
    }

    return child;
}

void TourDNA::crossover() {
    vector<Tour> merge;
    merge.emplace_back(tours[0]);

    while (merge.size() != tours.size()) {
        vector<Tour> bucks = createParentPool();
        int eliteBuck = findIndexOfEliteTour(bucks);

        vector<Tour> does = createParentPool();
        int eliteDoe = findIndexOfEliteTour(does);

        merge.emplace_back(crossParents(bucks[eliteBuck], does[eliteDoe]));
    }

    tours = merge;
}