#include "power_pellet.hpp"

#include "print_util.hpp"

void power_pellet::encounter(pacman& p) {
	p.increase_score(50);
	p.empower();
}

void power_pellet::print() {
	print_power_pellet();
}

event* power_pellet::clone() {
	return new power_pellet;
}
