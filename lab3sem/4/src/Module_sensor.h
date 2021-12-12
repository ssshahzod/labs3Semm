//
// Created by cronion on 05.11.2021.
//

#ifndef INC_4TH_MODULE_SENSOR_H
#define INC_4TH_MODULE_SENSOR_H
#include "Module.h"
#include "Coord.h"

namespace Mobile_robots{
    class Module_sensor : Module{
        private:
            double radius;
            double field_of_view; //45, 90, 30, 180
            int direction;
        public:
            explicit Module_sensor(double rad = 0, double view = 0, int dir = 0) : radius(rad), field_of_view(view), direction(dir){}
            status_string* get_env_info();
    };
}

#endif //INC_4TH_MODULE_SENSOR_H
