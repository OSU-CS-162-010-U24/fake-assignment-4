#include "dot.hpp"

#include "print_util.hpp"

void dot::encounter(pacman& p) {
	p.increase_score(10);
	p.eat_dot();
}

void dot::print() {
	print_dot();
}

event* dot::clone() {
	return new dot;
}
