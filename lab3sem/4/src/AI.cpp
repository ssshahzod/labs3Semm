//
// Created by cronion on 11.11.2021.
//

#include "AI.h"

namespace Mobile_robots{
/*    status_string *AI::find_points(Env_descriptor *mp) {
        int size = 0;
        status_string* ar;
        status_string* tmp;
        for(int i = 0; i < mp->get_map_height(); i++){
            for(int j = 0; j < mp->get_map_weight(); j++){
                if(mp->get_cell_info(j, i).component_type == point){
                    size++;
                    tmp = (status_string*) realloc(ar, size * sizeof(status_string));
                    tmp[size - 1].coordX = mp->get_cell_info(j, i).coordX;
                    tmp[size - 1].coordY = mp->get_cell_info(j, i).coordY;
                    tmp[size - 1].component_type = mp->get_cell_info(j, i).component_type;
                    if(tmp)
                        ar = tmp;
                    else
                        throw std::bad_alloc();
                }
            }
        }
    }*/
}