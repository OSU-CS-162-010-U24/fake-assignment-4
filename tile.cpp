#include "tile.hpp"

tile::tile(bool passable) : passable(passable) {}

tile::tile(event* e) : e(e) {}

tile::~tile() {
	if (this->e != nullptr) {
		delete this->e;
	}
}

tile::tile(const tile& other) : passable(other.passable) {
	if (other.e != nullptr) {
		this->e = other.e->clone();
	} else {
		this->e = nullptr;
	}
}

tile& tile::operator=(const tile& other) {
	if (this == &other) {
		return *this;
	}

	if (this->e != nullptr) {
		delete this->e;
	}

	this->passable = other.passable;
	if (other.e != nullptr) {
		this->e = other.e->clone();
	} else {
		this->e = nullptr;
	}

	return *this;
}

event* tile::get_event() const {
	return this->e;
}

void tile::set_event(event* e) {
	if (this->e != nullptr) {
		delete this->e;
	}
	this->e = e;
}

void tile::clear_event() {
	if (this->e != nullptr) {
		delete this->e;
		this->e = nullptr;
	}
}

bool tile::is_passable() const {
	return this->passable;
}
