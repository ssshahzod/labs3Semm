//
// Created by cronion on 05.11.2021.
//

#include "Component.h"
#include "Module.h"
#include "Coord.h"

namespace Mobile_robots {
    Component::Component(int x, int y, int type, unsigned int cst, unsigned int slots,
                                        unsigned int power) {
        cost = cst;
        modules_slots = slots;
        power_consumption = power;
        status.coordX = x;
        status.coordY = y;
        status.component_type = type;
        modules_num = 0;
        modules = new Module[slots];
    }

    int Component::install_module(Module& mod) {
        if(modules_num < modules_slots){
            modules[modules_num] = mod;
            modules_num++;
            if(mod.getId() == high)
                 power_consumption = mod.get_power_cons();
            else
                modules_en += mod.get_power_cons();
        }
        else
            return no_free_space;
        return 0;
    }

    int Component::delete_module(int module_typeId) {
        for(int i = 0; i < modules_num; i++) {
            if (modules[i].getId() == module_typeId) {
                modules_en -= modules[i].get_power_cons();
                modules[i] = NULL;
                modules_num--;
                return no_err;
            }
        }
        return incorrect_value;

    }

    bool Component::module_is_in(int module_typeId){
        for(int i = 0; i < modules_num; i++){
            if(modules[i].getId() == module_typeId)
                return true;
        }
        return false;
    }

    status_string Component::get_comp_string() const{
        return status;
    }

    int Component::energy_regulate(){
        int res = no_err;
        int prior = low;
        while(modules_en > power_consumption && res == no_err){
            res = delete_module(prior);
            if(res == incorrect_value && modules_en > power_consumption)
                prior = middle;
        }
        return no_err;
    }

    void Component::print_status(std::ostream& ostrm) const{
        ostrm << "Component type is: " << Comp_Types[status.component_type]
                    << "X cord is: " << status.coordX << "Y cord is: " << status.coordY << std::endl;
    }


}

