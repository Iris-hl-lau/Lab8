//
// Created by Iris L on 2018-11-16.
//

#include "travelLog.hpp"

/**
 * Prints everybody in the city.
 */
void travelLog::print() {
    string person;
    vector<string> location;
    for (auto &ppl_place : ppl_places) {
        person = ppl_place.first;
        location = ppl_place.second;
        cout << person << " ";
        for(const string &loc : location) {
            cout << loc << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * Prints those who visited Krusty-Burger and Tavern.
 */
void travelLog::visited_kBurgerAndTavern() {
    string person;
    vector<string> location;
    cout << "Visited both Krusty-Burger and Tavern" << endl;
    for (auto &ppl_place : ppl_places) {
        person = ppl_place.first;
        location = ppl_place.second;

        if(find(location.begin(), location.end(), "Krusty-Burger") != location.end()) {
            if(find(location.begin(), location.end(), "Tavern") != location.end()) {
                cout << person << endl;
            }
        }
    }
    cout << endl;
}

/**
 * Prints those who have not visited Krusty-Burger and Home.
 */
void travelLog::not_visited_kBurgerAndHome() {
    string person;
    vector<string> location;
    cout << "Did NOT visit Krusty-Burger and Home" << endl;
    for (auto &ppl_place : ppl_places) {
        person = ppl_place.first;
        location = ppl_place.second;

        if(find(location.begin(), location.end(), "Krusty-Burger") == location.end()) {
            if(find(location.begin(), location.end(), "Home") == location.end()) {
                cout << person << endl;
            }
        }
    }
    cout << endl;
}

/**
 * Prints those who have visited Krusty-Burger and School,
 * and have not visited Tavern and Home.
 */
void travelLog::visited_kBurgerAndSchool_not_tavernAndHome() {
    string person;
    vector<string> location;
    cout << "Visited Krusty-Burger and School but did NOT visit Tavern and Home \n";
    for (auto &ppl_place : ppl_places) {
        person = ppl_place.first;
        location = ppl_place.second;

        if(find(location.begin(), location.end(), "Krusty-Burger") != location.end()) {
            if (find(location.begin(), location.end(), "School") != location.end()) {
                if (find(location.begin(), location.end(), "Tavern") == location.end()) {
                    if (find(location.begin(), location.end(), "Home") == location.end()) {
                        cout << person << endl;
                    }
                }
            }
        }
    }
    cout << endl;
}

/**
 * Prints and remove those who have visited all places.
 */
void travelLog::remove_visited_allLocations() {
    string person;
    vector <string> location;
    cout << "Removing visited all locations" << endl;
    for (auto it = ppl_places.begin(); it != ppl_places.end();) {
        person = it->first;
        location = it->second;

        if (find(location.begin(), location.end(), "Krusty-Burger") != location.end()
            && find(location.begin(), location.end(), "School")!= location.end()
            && find(location.begin(), location.end(), "Tavern")!= location.end()
            && find(location.begin(), location.end(), "Home") != location.end()) {
            cout << person << endl;
            auto remove = it++;
            ppl_places.erase(remove);
        } else{
            it++;
        }
    }
    cout << endl;
}
