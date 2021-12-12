//
// Created by cronion on 11.11.2021.
//

#include "Power_generator.h"

namespace Mobile_robots{
    Power_generator::Power_generator(int supply) {
        if(supply < 0)
            throw std::logic_error("Wrong power value!\n");
        power_supply = supply;
    }
}