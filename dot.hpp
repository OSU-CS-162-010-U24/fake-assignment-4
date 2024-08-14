#ifndef DOT_HPP
#define DOT_HPP

#include "event.hpp"

// TODO Complete this class
class dot : public event {
public:
	void encounter(pacman& p) override;
	void print() override;

	event* clone();
};

#endif
