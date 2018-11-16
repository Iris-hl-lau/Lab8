//
// Created by Iris L on 2018-11-16.
//

#ifndef LAB8_TRAVELLOG_HPP
#define LAB8_TRAVELLOG_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/**
 * Identifies a list of people who have been or haven't been to places.
 */
class travelLog {
private:
    map<string, vector<string>> ppl_places;
public:
    explicit travelLog(map<string, vector<string>> ppl_places) : ppl_places(ppl_places) {} //Constructor
    void print(); //Prints everybody in the city
    void visited_kBurgerAndTavern(); //Prints those who visited Krusty-Burger and Tavern
    void not_visited_kBurgerAndHome(); //Prints those who have not visited Krusty-Burger and Home
    void visited_kBurgerAndSchool_not_tavernAndHome(); //Prints those who have visited Krusty-Burger and School, but have not visited Tavern and Home
    void remove_visited_allLocations(); //Prints and remove those who have visited all places
};


#endif //LAB8_TRAVELLOG_HPP
