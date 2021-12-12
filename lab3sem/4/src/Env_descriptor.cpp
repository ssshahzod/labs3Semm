//
// Created by cronion on 05.11.2021.
//

#include "Env_descriptor.h"

namespace Mobile_robots{
    Env_descriptor::Env_descriptor(unsigned int heig, unsigned int weig){
        unsigned int size = heig * weig;
        unsigned int num_of_points, added_points = 0;
        if(size < 9)
            num_of_points = size / 4;
        else
            num_of_points = size / 9;

        if(heig > 0 && weig > 0) {
            height = heig;
            width = weig;
        }
        else
            throw std::logic_error("Wrong map size!\n");

        map = array<Component>(size) ;
        int num;
        Component* tmp;
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                num = rand() % 10;

                if(num % 4 == 0 && added_points < num_of_points /*&& (check_cells_around(j, i, height, width, point) < 2)*/){
                    tmp = new Component(j, i, point);
                    added_points++;

                }
                else if(num % 3 == 0){
                    tmp = new Component(j, i, barrier);
                    /*if(check_cells_around(j, i, height, width, barrier) < 2){
                        map[width * i + j] = new Component(j, i, barrier);
                    }*/
                }
                else{
                    tmp = new Component(j, i, nothing);
                }

                map.inputObj(width * i + j, tmp);

            }
        }

    }

/*    int Env_descriptor::check_cells_around(int x, int y, unsigned int h, unsigned int w, int obj){
        int res = 0;
        int cord = y * (int)width + x;
        int pos = 1;
        if(map){
            while(cord - pos >= 0 && pos < 4){
                //res += (obj == get_cell_info(map[cord - pos]->get_comp_string().coordX, map[cord - pos]->get_comp_string().coordY).component_type);
                pos++;
            }
            return res;
        }
    }*/

    Component* Env_descriptor::get_cell_link(int x, int y) {
        int cord = (y) * (int)width + x;
        if(cord < height * width){
            Component* tmp = map[cord];
            return tmp;
        }
        else
            return nullptr;
    }

    void Env_descriptor::setHeight(unsigned int hgt){
        int err;
        int oldHeight = height;
        if(hgt > 0)
            height = hgt;
        else
            return;
        err = resize(oldHeight, width);
        if(err)
            throw std::bad_alloc();
    }

    void Env_descriptor::setWeight(unsigned int wgt){
        int err;
        unsigned int oldWidth = width;
        if(wgt > 0)
            width = wgt;
        else
            return;
        err = resize(height, oldWidth);
        if(err)
            throw std::bad_alloc();
    }

    int Env_descriptor::resize(unsigned int heig, unsigned int widt){
        array<Component> tmp(height * width);
        for(int i = 0; i < heig * widt; i++){
            tmp.inputObj(i, map[i]);
        }

    }


    status_string Env_descriptor::get_cell_info(int x, int y) {
        status_string nul;
        nul.component_type = 0;
        nul.coordX = -1;
        nul.coordY = -1;
        int cord = (y) * (int)width + x;
        if(map[cord])
            return map[cord]->get_comp_string();
        return nul;
    }


    int Env_descriptor::change_component(int x, int y, Component& cmp) { //const
        int cord = (y) * (int)width + x;

        if(map[cord]->getType() == point)
            return permission_er;
        delete map[cord];
        map.inputObj(cord, &cmp);
    }

}

