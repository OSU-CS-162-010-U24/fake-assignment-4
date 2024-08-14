#include "ghost.hpp"

#include "print_util.hpp"

ghost::ghost(const std::string& color) : color(color) {}

int ghost::get_row() const {
	return this->row;
}

int ghost::get_column() const {
	return this->column;
}

void ghost::set_row(int row) {
	this->row = row;
}

void ghost::set_column(int column) {
	this->column = column;
}

void ghost::move_up() {
	this->row--;
}

void ghost::move_down() {
	this->row++;
}

void ghost::move_right() {
	this->column++;
}

void ghost::move_left() {
	this->column--;
}

bool ghost::get_alive() const {
	return this->alive;
}

void ghost::death() {
	this->alive = false;
}

void ghost::respawn(int row, int column) {
	this->alive = true;
	this->row = row;
	this->column = column;
}

void ghost::print() const {
	print_ghost(this->color);
}
