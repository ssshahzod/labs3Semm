#include "Command_center.h"

namespace Mobile_robots {
    Command_center::Command_center(int x, int y, int type, unsigned int cst, unsigned int mods,
                                                  unsigned int power) : Component(x, y, type, cst, mods, power) {
        speed = 0;

    }
}