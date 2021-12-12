//
// Created by cronion on 05.11.2021.
//

#ifndef INC_4TH_COORD_H
#define INC_4TH_COORD_H
#include <iostream>

namespace Mobile_robots{

    enum comp_type{
        nothing = 0,
        barrier,
        point,
        component,
        command_center,
        observation_center,
        mobile_robot,
        robot_scout,
        robor_commander //has speed
    };

    extern const char *Comp_Types[];
    extern const char *ErrorTypes[];

    enum module_priority{
        low = 100, //sensor
        middle, //managing module
        high //generator
    };

    enum direction{
        up = 10,
        down,
        left,
        right
    };

    enum errors{
        no_err = 899,
        empty_cell,
        wrong_comp,
        not_active_rob,
        permission_er, //error occurs if we are trying to remove point from map
        mem_all,
        incorrect_value,
        no_free_space,

    };


    typedef struct comp_cords{
        int xcord;
        int ycord;
        int type;
    } comp_cords;
}


#endif //INC_4TH_COORD_H
