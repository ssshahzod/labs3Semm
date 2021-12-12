//
// Created by cronion on 12.11.2021.
//

#include "Managing_module.h"
#include "Coord.h"
#include "Env_descriptor.h"

namespace Mobile_robots{
    Managing_module::Managing_module(float rad) {
        radius = rad;
        num_of_robots = 0;
        robots = nullptr;
    }

    int Managing_module::add_robot(int x, int y, Env_descriptor desc) {
        Component** tmp = (Component**) realloc(robots, (num_of_robots + 1) * sizeof(Component**));
        if(tmp != nullptr){
            robots = tmp;
            robots[num_of_robots] = desc.get_cell_link(x, y);
            num_of_robots++;
            return no_err;
        }
        else
            return mem_all;

    }

    int Managing_module::remove_robot(int x, int y){
        for(int i = 0; i < num_of_robots; i++){
            if(robots[i]->get_comp_string().coordX == x && robots[i]->get_comp_string().coordY == y){
                robots[i] = robots[num_of_robots];
                robots[num_of_robots] = nullptr;
                num_of_robots--;
                Component** tmp = (Component**) realloc(robots, (num_of_robots) * sizeof(Component**));
                if(tmp != nullptr) {
                    robots = tmp;
                    return no_err;
                }
                else
                    return mem_all;
            }
        }
    }

    void Managing_module::get_robots_info(std::ostream& ostrm) {
        for(int i = 0; i < num_of_robots; i++){
            ostrm << "Robot Num:" << i << " :" << std::endl;
            robots[i]->print_status(ostrm);
        }
    }

    int Managing_module::move_robot(int num, int direction) {
/*        if(direction == up)
            robots[num]->stat_set_cordY(robots[num]->get_comp_string().coordY - 1);
        else if(direction == down)
            robots[num]->stat_set_cordY(robots[num]->get_comp_string().coordY + 1);
        else if(direction == left)
            robots[num]->stat_set_cordX(robots[num]->get_comp_string().coordX - 1);
        else if(direction == right)
            robots[num]->stat_set_cordX(robots[num]->get_comp_string().coordX + 1);*/

    }
}