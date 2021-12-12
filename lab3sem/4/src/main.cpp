#include <iostream>
#include "Env_descriptor.h"

int main() {
    int h = 5, w = 5, res = 0;
    Mobile_robots::Env_descriptor tmp(h, w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            res += tmp.get_cell_info(i, j).component_type;
            std::cout << "Comp cord x: " << tmp.get_cell_info(i, j).coordX;
            std::cout << " Comp cord y: " << tmp.get_cell_info(i, j).coordY << "||";
            std::cout << " copm type: " << tmp.get_cell_info(i, j).component_type << std::endl;
        }
    }
    Mobile_robots::Component t(1, 1,Mobile_robots::observation_center);
    tmp.change_component(1, 1, t);

    return 0;
}
