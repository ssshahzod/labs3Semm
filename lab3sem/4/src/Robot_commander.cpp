//
// Created by cronion on 12.11.2021.
//

#include "Robot_commander.h"
namespace Mobile_robots {

    int Mobile_robots::Robot_commander::move(int direction) {
        if(direction == up)
            status.coordY -= speed;
        else if(direction == down)
            status.coordY += speed;
        else if(direction == left)
            status.coordX -= speed;
        else if(direction == right)
            status.coordX += speed;

    }
}
