#include "maze_util.hpp"

#include "dot.hpp"
#include "power_pellet.hpp"
#include "fruit.hpp"

tile tile_from_char(char c) {
	if (c == 'D') {
		return tile(new dot);
	} else if (c == 'P') {
		return tile(new power_pellet);
	} else if (c == 'W') {
		return tile(false);
	} else if (c == ' ') {
		return tile();
	} else {
		std::string message = "Invalid event character ";
		message += c;
		throw std::invalid_argument(message);
	}
}
