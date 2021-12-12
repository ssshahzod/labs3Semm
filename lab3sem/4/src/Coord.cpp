//
// Created by cronion on 05.11.2021.
//

#include "Coord.h"

namespace Mobile_robots{

    const char *Comp_Types[] = {
            "Barrier",
            "Point",
            "Command center",
            "Observation center",
            "Mobile robot",
            "Robot scout",
            "Robot commander"
    };

    const char *ErrorTypes[] ={
            "The cell is empty!\n",
            "Wrong component!\n",
            "The robot isnt active!\n",
            "Wrong permission!\n",
            "Memory allocation error!\n",
            "Incorrect value entered!\n"
    };

    void er_message(int err_code, std::ostream strm, const char* msg){
        strm << msg << std::endl;
        strm << "Next error occured: ";
        strm << ErrorTypes[err_code - 900];
    }



}