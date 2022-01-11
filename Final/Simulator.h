//
// Created by 14799 on 2021/12/22.
//

#ifndef CPP_FINAL_PANDEMIC_SIMULATOR_H
#define CPP_FINAL_PANDEMIC_SIMULATOR_H

#include "People.h"
#include <iostream>
#include <limits>
#include <deque>
#include <random>
#include <vector>

std::deque<People*> People::infQue;
//best-first search queue to store states

std::deque<People*> People::tmpQue;

struct result_type{
    size_t numPeople, numVaccinated, numInfected, numVulnerable, maxDay, numSource;
};

class Simulator {
private:
    static std::linear_congruential_engine<size_t, 1, 0, std::numeric_limits<size_t>::max()> gen;//random generator
    std::vector<People> people;

    inline People *get_people(size_t index);
    People *get_random_people();
    void randomVaccination(size_t vacNum);
    void randomInfection(size_t originNum);
    void nextInfect();//best-first search main function

public:
    void outerInit();
    result_type experiment(size_t size, size_t vacNum, size_t originNum);

};


#endif //CPP_FINAL_PANDEMIC_SIMULATOR_H
