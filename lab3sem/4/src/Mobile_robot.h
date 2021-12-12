//
// Created by cronion on 12.11.2021.
//

#ifndef INC_4TH_MOBILE_ROBOT_H
#define INC_4TH_MOBILE_ROBOT_H
#include "Coord.h"
#include "Component.h"

namespace Mobile_robots {
    class Mobile_robot : private Component{
        public:
            Mobile_robot(int x = 0, int y = 0, int type = 4, unsigned int cst = 0, unsigned int mods = 0, unsigned int power = 0);
            int move_robot(int direction);
    };
}

#endif //INC_4TH_MOBILE_ROBOT_H
