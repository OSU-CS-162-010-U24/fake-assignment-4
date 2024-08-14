#ifndef EVENT_HPP
#define EVENT_HPP

#include "pacman.hpp"

class event {
public:
	virtual void encounter(pacman& p) = 0;
	virtual void print() = 0;

	virtual ~event() = default;

	virtual event* clone() = 0;
};

#endif
