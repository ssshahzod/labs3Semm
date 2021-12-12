//
//
//

#ifndef INC_4TH_COMMAND_CENT_H
#define INC_4TH_COMMAND_CENT_H
#include "Component.h"
#include "Robot_scout.h"
#include "Coord.h"

namespace Mobile_robots{

	class Command_center : public Component{ //хранить информацию
		public:
			Command_center(int x, int y, int type = command_center, unsigned int cst = 0, unsigned int mods = 0, unsigned int power = 0);
			//int move_robot(Robot_scout& rob, int x, int y){rob.set_position(x, y);};
			comp_cords* get_info();
	};
}

#endif