//
// Created by cronion on 11.11.2021.
//

#ifndef INC_4TH_POWER_GENERATOR_H
#define INC_4TH_POWER_GENERATOR_H
#include "Module.h"

namespace Mobile_robots{
    class Power_generator : public Module{
        private:
            int power_supply;
            int id = 100;
        public:
            explicit Power_generator(int supply); //определять ли отдельный конструктор или использовать от родителя и сеттеры
            [[nodiscard]] int getId() const override{return id;};
            [[nodiscard]] int get_power_cons() const override{return power_supply;};
    };
}

#endif //INC_4TH_POWER_GENERATOR_H
