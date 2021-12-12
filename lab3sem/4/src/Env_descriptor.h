//
// Created by cronion on 05.11.2021.
//

#ifndef INC_4TH_ENV_DESCRIPTOR_H
#define INC_4TH_ENV_DESCRIPTOR_H

#include "Coord.h"
#include "Component.h"
#include "Util.h"

namespace Mobile_robots {


    class Env_descriptor {
    private:
        unsigned int height;
        unsigned int width;
        array<Component> map;

    public:
        Env_descriptor(unsigned int heig, unsigned int weig);
        void setHeight(unsigned int hgt);
        void setWeight(unsigned int wgt);
        int resize(unsigned int heig, unsigned int widt);
        Component* get_cell_link(int x, int y);
        unsigned int get_map_height(){return height;};
        unsigned int get_map_weight(){return width;};
        status_string get_cell_info(int x, int y);
        int check_cells_around(int x, int y, unsigned int h, unsigned int w, int obj);
        int change_component(int x, int y, Component& cmp);

    };
}


#endif //INC_4TH_ENV_DESCRIPTOR_H
