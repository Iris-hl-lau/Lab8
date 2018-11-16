#include <iostream>
#include "travelLog.hpp"

/**
 * Drives the program.
 * @return int
 */
int main() {
    //Open file
    ifstream read_file;
    read_file.open("../peoplePlaces.txt");
    string read_person, person, loc;
    map<string, vector<string>> ppl_places;
    vector<string> places;

    //Read file into STL map
    while(getline(read_file, read_person)) {
        istringstream person_loc(read_person);
         person_loc >> person;
        while(person_loc >> loc) {
            places.push_back(loc);
        }
        ppl_places.insert(make_pair(person, places));
        places.clear();
    }

    //Create travelLog object and test functions
    travelLog tl(ppl_places);

    cout << "Everybody in the city" << endl;
    tl.print();
    tl.visited_kBurgerAndTavern();
    tl.not_visited_kBurgerAndHome();
    tl.visited_kBurgerAndSchool_not_tavernAndHome();
    tl.remove_visited_allLocations();
    cout << "Everybody in the city after removing people who visited all locations" << endl;
    tl.print();

    return 0;
}