//
// Created by cronion on 05.11.2021.
//

#ifndef INC_4TH_MODULE_H
#define INC_4TH_MODULE_H
#include "Coord.h"
#include "Component.h"

namespace Mobile_robots{

    class Module{

    protected:
        int priority;
        bool is_active;
        unsigned int cost;
        unsigned int power_consumption;

    public:
        Module(int pr = 0, unsigned int cst = 0, unsigned int power = 0) : priority(pr), cost(cst), power_consumption(power){is_active = 0;};
        bool module_stat(){return is_active;};
        void module_switch_on()
            {is_active = true;}
        void module_switch_off()
            {is_active = false;}
        int set_cost(int val);
        int get_priority() const
            {return priority;};
        int get_cost() const
            {return cost;}
        virtual int get_power_cons() const
            {return power_consumption;}
        virtual int getId() const {return 0;};
    };
}



#endif //INC_4TH_MODULE_H
