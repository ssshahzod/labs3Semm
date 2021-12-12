//
//
//

#ifndef INC_4TH_ROBOT_SCOUT_H
#define INC_4TH_ROBOT_SCOUT_H
#include "Observation_center.h"
#include "Coord.h"

namespace Mobile_robots{
	class Robot_scout : public Observation_cnt{
		public:
			Robot_scout(int x = 0, int y = 0, int type = robot_scout, unsigned int cst = 0, unsigned int mods = 0, unsigned int power = 0);
			//int set_position(int x, int y){status_string.coordX = x; status_string.coordY = y};
	};
}

#endif