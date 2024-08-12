#include "tile.hpp"

tile::tile(bool passable) : passable(passable) {}

tile::tile(event* e) : e(e) {}

void tile::clear_event() {
	if (this->e != nullptr) {
		delete this->e;
		this->e = nullptr;
	}
}

bool tile::is_passable() const {
	return this->passable;
}
