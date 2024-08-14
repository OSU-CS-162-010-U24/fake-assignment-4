#include <cstdlib>
#include <ctime>

#include "game.hpp"

int main() {
	srand(time(nullptr));

	game g;
	g.play();
}
