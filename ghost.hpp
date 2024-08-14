#ifndef GHOST_HPP
#define GHOST_HPP

#include <string>

class ghost {
private:
	int row = 0;
	int column = 0;
	bool alive = true;
	std::string color;
public:
	ghost(const std::string& color);

	int get_row() const;
	int get_column() const;
	void set_row(int row);
	void set_column(int column);
	void move_up();
	void move_down();
	void move_right();
	void move_left();

	bool get_alive() const;
	void death();
	void respawn(int row, int column);

	void print() const;
};

#endif
