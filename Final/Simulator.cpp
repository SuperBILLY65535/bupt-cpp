//
// Created by 14799 on 2021/12/22.
//

#include "Simulator.h"

People *Simulator::get_people(size_t index) {
    return &people[index % people.size()];
}
