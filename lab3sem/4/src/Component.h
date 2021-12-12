//
// Created by cronion on 05.11.2021.
//

#ifndef INC_4TH_COMPONENT_H
#define INC_4TH_COMPONENT_H

#include "Coord.h"
#include "Module.h"

namespace Mobile_robots{
    typedef struct status_string{
        int component_type;
        int coordX;
        int coordY;
    } status_string;

    class Module;
    class Component {
        protected:
            status_string status;
            unsigned int cost;
            unsigned int power_consumption;
            unsigned int modules_num;
            unsigned int modules_en;
            unsigned int modules_slots;
            Module* modules;

        public:
            Component(int x = 0, int y = 0, int type = component, unsigned int cst = 0, unsigned int slots = 0, unsigned int power = 0);
            unsigned int get_power_cons() const{return power_consumption;};
            int getType() const {return status.component_type;};
            unsigned int get_modules_num() const{return modules_num;};
            unsigned int get_modules_slots() const{return modules_slots;};
            unsigned int get_comp_cost() const{return cost;};
            void stat_set_cordX(int cord) {status.coordX = cord;};
            void stat_set_cordY(int cord) {status.coordY = cord;};
            status_string get_comp_string() const;
            int install_module(Module& mod);
            bool module_is_in(int module_type);
            int delete_module(int module_typeId);
            int energy_regulate();
            void print_status(std::ostream& ostrm) const;
        private:
            float speed;

    };
}



#endif //INC_4TH_COMPONENT_H
