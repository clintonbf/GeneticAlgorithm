#include <iostream>
#include "TourDriver.hpp"

constexpr int NUMBER_OF_CITIES = 32;
constexpr int NUMBER_OF_TOURS = 32;
constexpr int FITNESS_THRESHOLD = 100;

using namespace std;
void testTourDNA() {
    //Build a tour
    TourDriver td{5, 5, FITNESS_THRESHOLD};

    vector<Tour> tours = td.getTours();
    TourDNA tdna = TourDNA(tours);

    Tour elite = tdna.getElite();
    const vector<City>& cities = elite.getCities();
    for (const City& c: cities) {
        cout << c << " | " <<  c.getXPosition() << " | " << c.getYPosition() << endl;
    }

    cout << "The elite tour is:" << endl;
    cout << elite;

    cout << "Total distance of tour: " << elite.getDistance();

    tdna.improve();
    cout << "New elite tour is: " << endl;
    cout << tdna.getElite() << endl;

}

int main() {
    TourDriver td{NUMBER_OF_CITIES, NUMBER_OF_TOURS, FITNESS_THRESHOLD};
    td.get_best_tour();

//    testTourDNA();
    return 0;
}

