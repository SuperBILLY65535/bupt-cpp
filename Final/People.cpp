//
// Created by 14799 on 2021/12/20.
//

#include "People.h"

People::People() {
    for (auto &neighbour : neighbours) {
        neighbour = nullptr;
    }
    vaccinated = infected = false;
    infectDay = 0;
}

void People::infectNeighbours() {
    //adds all neighbours to infQue
    infectCount++;
    for (People *neighbour : neighbours){
        if(neighbourVulnerable(neighbour)) {
            neighbour->infect(this->infectDay + 1);
        }
    }
}

People::People(bool inf, bool vac) {
    infected = inf;
    vaccinated = vac;
    infectDay = 0;
    for (auto &neighbour : neighbours) {
        neighbour = nullptr;
    }
}

void People::interInit() {
    infectCount = 0;
}

bool People::checkVac() const {
    return vaccinated;
}

void People::vaccinate() {
    vaccinated = true;
}

bool People::checkHealthy() const {
    return !infected;
}

void People::infect(unsigned int day) {
    //set infected to true, and adds this to infQue
    infected = true;
    infectDay = day;
    max_infect_day = std::max<unsigned>(day, max_infect_day);
    infQue.push_back(this);
}

unsigned People::getInfected() {
    //get the number of infected
    return infectCount;
}

void People::neighbourInitialize(unsigned int pos, People *p) {
    //initializes neighbours[]
    this->neighbours[pos] = p;
}

bool People::vulnerable() const {
    //check if this is vulnerable
    return ((!this->checkVac()) && (this->checkHealthy()));
}

bool neighbourVulnerable(People *p) {
    //check if any neighbour is a nullptr
    //if not, returns the actual vulnerable() state
    if (p == nullptr) {
        return false;
    }
    else return p->vulnerable();
}

unsigned People::get_max_infect_day() {
    return max_infect_day;
}

