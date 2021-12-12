//
//
//

#ifndef INC_4TH_OBSERVATION_H
#define INC_4TH_OBSERVATION_H

#include "Module.h"
#include "Component.h"
#include "Coord.h"

namespace Mobile_robots{

	class Observation_cnt : public Component{
		protected:
			Module* owner;
		public:
			Observation_cnt(int x = 0, int y = 0, int type = 3, unsigned int cst = 0, unsigned int mods = 0, unsigned int power = 0);
			comp_cords* get_info();
	};
}


#endif