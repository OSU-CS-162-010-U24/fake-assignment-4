#ifndef TILE_HPP
#define TILE_HPP

#include "event.hpp"

class tile {
private:
	event* e = nullptr;
	bool passable = true;
public:
	tile() = default;
	tile(bool passable);
	tile(event* e);

	~tile();
	tile(const tile& other);
	tile& operator=(const tile& other);

	event* get_event() const;
	void set_event(event* e);

	void clear_event();

	// Getter for passable
	bool is_passable() const;
};

#endif
