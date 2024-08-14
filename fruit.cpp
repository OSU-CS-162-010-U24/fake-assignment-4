#include <cstdlib>

#include "fruit.hpp"

#include "print_util.hpp"

void fruit::encounter(pacman& p) {
	p.increase_score((rand() % 4801) + 200);
}

void fruit::print() {
	print_fruit();
}

event* fruit::clone() {
	return new fruit;
}
