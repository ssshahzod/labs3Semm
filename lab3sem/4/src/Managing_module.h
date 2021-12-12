//
// Created by cronion on 12.11.2021.
//

#ifndef INC_4TH_MANAGING_MODULE_H
#define INC_4TH_MANAGING_MODULE_H
#include "Module.h"
#include "Env_descriptor.h"
#include <iostream>

namespace Mobile_robots {
    class Managing_module : public Module{
        private:
            float radius;
            int num_of_robots;
            Component** robots;
        public:
            explicit Managing_module(float rad);
            int add_robot(int x, int y, Env_descriptor desc);
            int remove_robot(int x, int y);
            void get_robots_info(std::ostream& ostrm);
            int move_robot(int num, int direction);
            //

    };
}

#endif //INC_4TH_MANAGING_MODULE_H
