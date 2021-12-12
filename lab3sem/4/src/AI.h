//
// Created by cronion on 11.11.2021.
//

#ifndef INC_4TH_AI_H
#define INC_4TH_AI_H
#include "Env_descriptor.h"
#include "Component.h"

namespace Mobile_robots {
    class AI {
        private:
            Env_descriptor* map;
        public:
            explicit AI(Env_descriptor* m) : map(m){};
            status_string* find_points(Env_descriptor* mp);
    };
}


#endif //INC_4TH_AI_H
