//
// Created by cronion on 05.11.2021.
//

#include "Module.h"

namespace Mobile_robots{
    int Module::set_cost(int val) {
        if(val > 0)
            cost = val;
        else
            return incorrect_value;
    }
}
