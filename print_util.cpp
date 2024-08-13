#include <sstream>
#include <iostream>

#include "print_util.hpp"

void print_color(std::string text, int r, int g, int b) {
	std::stringstream ansi;
	ansi << "\033[38;2;" << r << ";" << g << ";" << b << "m";

	std::cout << ansi.str() << std::flush;
	std::cout << text;
	std::cout << "\033[0m" << std::flush;
}

void print_ghost(std::string color) {
	if (color == "red") {
		print_color("\u25BC", 255, 0, 0);
	} else if (color == "orange") {
		print_color("\u25BC", 255, 184, 71);
	} else if (color == "pink") {
		print_color("\u25BC", 255, 184, 222);
	} else if (color == "blue") {
		print_color("\u25BC", 0, 255, 222);
	} else {
		std::stringstream message;
		message << "Invalid ghost color '" << color << "'.";
		throw std::invalid_argument(message.str());
	}
}

void print_wall() {
	std::cout << "\033[48;2;33;33;222m" << std::flush;
	std::cout << " ";
	std::cout << "\033[0m" << std::flush;
}

void print_pacman() {
	print_color("\u25D5", 255, 255, 0);
}

void print_fruit() {
	print_color("F", 255, 0, 0); // F stands for fruit :)
}

void print_dot() {
	print_color("\u2022", 255, 184, 151);
}

void print_power_pellet() {
	print_color("\u25CF", 255, 184, 151);
}
