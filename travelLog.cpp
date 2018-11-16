//
// Created by Iris L on 2018-11-16.
//

#include "travelLog.hpp"

void travelLog::print() {
    string person;
    vector<string> location;
    for (auto it = ppl_places.begin(); it != ppl_places.end(); it++) {
        person = it->first;
        location = it->second;
        cout << person << " ";
        for(const string &loc : location) {
            cout << loc << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void travelLog::visited_kBurgerAndTavern() {
    string person;
    vector<string> location;
    cout << "Visited both Krusty-Burger and Tavern" << endl;
    for (auto it = ppl_places.begin(); it != ppl_places.end(); it++) {
        person = it->first;
        location = it->second;

        if(find(location.begin(), location.end(), "Krusty-Burger") != location.end()) {
            if(find(location.begin(), location.end(), "Tavern") != location.end()) {
            cout << person << endl;
            }
        }
    }
    cout << endl;
}

void travelLog::not_visited_kBurgerAndHome() {
    string person;
    vector<string> location;
    cout << "Did NOT visit Krusty-Burger and Home" << endl;
    for (auto it = ppl_places.begin(); it != ppl_places.end(); it++) {
        person = it->first;
        location = it->second;

        if(find(location.begin(), location.end(), "Krusty-Burger") == location.end()) {
            if(find(location.begin(), location.end(), "Home") == location.end()) {
                cout << person << endl;
            }
        }
    }
    cout << endl;
}

void travelLog::visited_kBurgerAndSchool_not_tavernAndHome() {
    string person;
    vector<string> location;
    cout << "Visited Krusty-Burger and School but did NOT visit Tavern and Home \n";
    for (auto it = ppl_places.begin(); it != ppl_places.end(); it++) {
        person = it->first;
        location = it->second;

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
