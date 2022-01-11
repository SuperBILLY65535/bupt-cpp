#include <iostream>
#include <fstream>
#include <cstdio>
#include <random>
#include "People.h"
#include <limits>
#include <ctime>
#include <windows.h>

using std::endl;

int size, vacNum, originNum;

People people[1000][1000];

const int pos[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
//positions to the x+, y+, x-, y-


/*
 * tmpQue is for get_random_people() to get a random people each time.
 * as each person can only be infected or vaccinated once,
 * using this method (instead of pure random location) can greatly improve the speed of getting people.
 */

unsigned People::infectCount = 0;

inline bool within(int comp, int low, int high) {
    //check if low <= comp <= high
    return ((comp >= low) && (comp <= high));
}

void outerInit();
void randomVaccination();
void randomInfection();
void nextInfect();
void result();
void experiment();
People *boundCheck(int x, int y);
void chain_list_initialize();
People *get_random_people();
inline unsigned get_num_people();

int main() {
    std::cout << "Please input the size of People:" << endl;
    std::cin >> size;
    std::printf("There are %d people in the test.\nPlease input the number of vaccinated people:\n", get_num_people());
    std::cin >> vacNum;
    printf("Please input the number of source infected:\n");
    std::cin >> originNum;

    chain_list_initialize();
    experiment();//casts an experiment
    return 0;
}

void randomVaccination() {
    //vaccinates vacNum people
    unsigned count = 0;
    People* tmp;
    while (count < vacNum) {
        tmp = get_random_people();
        if(tmp->checkVac()){//vaccinated
            continue;
        }
        else {//not vaccinated
            tmp->vaccinate();
            count++;
        }
    }
}

void randomInfection() {
    //infects originNum people as the source of the pandemic
    People *tmp;
    unsigned count = 0;
    while (count < originNum) {
        tmp = get_random_people();
        if(tmp->vulnerable()) {//not vaccinated nor infected
            tmp->infect(0);
            count++;
        }
        else {//either vaccinated or infected
            continue;
        }
    }
}

void nextInfect() {
    //extracts a person from infQue and infects his or her neighbours
    //this is actually the BFS main function
    People *tmp;
    tmp = People::infQue.front();//gets a person from the top of the queue
    tmp->infectNeighbours();
    People::infQue.pop_front();//expose
}

void result() {
    std::fstream res;
    res.open("result.txt");
    res << "Number of people: " << get_num_people() << endl;
    res << "Vaccinated people: " << vacNum << endl;
    res << "Source of infection: " << originNum << endl;
    res << "Infected people: " << People::getInfected() << endl;
    res << "Max infect days: " << People::get_max_infect_day() << endl;
    res << "Vulnerable but healthy people: " << get_num_people() - vacNum - People::getInfected() << endl;
}

void experiment() {
    //casts an experiment
    People::interInit();
    outerInit();
    randomVaccination();
    randomInfection();
    do{
        nextInfect();
    }while(!(People::infQue.empty()));
    result();
}

People *boundCheck(int x, int y) {
    //if the direction is out of range, returns a nullptr,
    //which will be recognized as the boundary in neighbourVulnerable()
    //else returns the neighbour pointer
    if (within(x, 0, size - 1) && within(y, 0, size - 1)) {
        return &(people[x][y]);
    }
    else {
        return nullptr;
    }
}

void chain_list_initialize() {
    //chain list initialization
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++) {
            for (int k = 0; k < 4; ++k) {
                people[i][j].neighbourInitialize(k, boundCheck(i + pos[k][0], j + pos[k][1]));
            }
        }
    }
}

People *get_random_people() {
    //this function is only written for randomVaccination() and randomInfection()
    //gets a person of people[][] and erase() it from tmpQue
    gen.seed(clock());
    Sleep(1);
    /*
     * Originally, I did not let the system pause for a millisecond and got the next random seed from clock()
     * but it was proven that Sleep() is crucial if you're not to get a duplicated random number
     */
    std::deque<People*>::iterator position;
    //using an iterator is due to that std::deque::erase() requires an matching iterator as variable
    position = People::tmpQue.begin() + gen() % People::tmpQue.size();
    People *r = *position;
    People::tmpQue.erase(position);
    return r;
}

void outerInit() {
    //initializes tmpQue for randomVaccination() and randomInfection()
    People::infQue.clear();
    People::tmpQue.clear();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            People::tmpQue.push_back(&people[i][j]);
            //everyone taking part in the test will be pushed into tmpQue
        }
    }
}

unsigned get_num_people() {
    return size * size;
}
