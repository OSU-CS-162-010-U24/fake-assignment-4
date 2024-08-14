#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "event.hpp"

// TODO Complete this class
class fruit : public event {
public:
	void encounter(pacman& p) override;
	void print() override;

	event* clone();
};

#endif
