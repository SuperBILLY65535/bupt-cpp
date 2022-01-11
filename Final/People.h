//
// Created by 14799 on 2021/12/20.
//

#ifndef CPP_FINAL_PANDEMIC_PEOPLE_H
#define CPP_FINAL_PANDEMIC_PEOPLE_H

#include <deque>
#include <iostream>
#include <algorithm>


class People {
private:
    bool vaccinated, infected;
    People *neighbours[4];
    unsigned infectDay;
    static unsigned max_infect_day;
public:
    static unsigned infectCount;
    static std::deque<People*> infQue, tmpQue;

    People();
    People(bool inf, bool vac);

    static unsigned getInfected();
    bool checkVac() const;
    void vaccinate();
    bool checkHealthy() const;
    bool vulnerable() const;
    static unsigned get_max_infect_day();
    friend bool neighbourVulnerable(People *p);

    void neighbourInitialize(unsigned pos, People *p);
    static void interInit();

    void infectNeighbours();
    void infect(unsigned day);
};

#endif //CPP_FINAL_PANDEMIC_PEOPLE_H
