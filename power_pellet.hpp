#ifndef POWER_PELLET_HPP
#define POWER_PELLET_HPP

#include "event.hpp"

class power_pellet : public event {
public:
	void encounter(pacman& p) override;
	void print() override;

	event* clone();
};

#endif
