//
// Created by cronion on 12.11.2021.
//

#ifndef INC_4TH_ROBOT_COMMANDER_H
#define INC_4TH_ROBOT_COMMANDER_H
#include "Component.h"
#include "Robot_scout.h"
#include "Command_center.h"


namespace Mobile_robots {
    class Robot_commander : public Command_center {
        private:
            int speed;

        public:
            Robot_commander(int sp = 1.0);
            int move(int direction);
    };
}


#endif //INC_4TH_ROBOT_COMMANDER_H
