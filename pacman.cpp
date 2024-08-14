#include "pacman.hpp"

int pacman::get_lives() const {
	return this->lives;
}

void pacman::death() {
	this->lives--;
}

int pacman::get_score() const {
	return this->score;
}

void pacman::increase_score(int amount) {
	this->score += amount;
}

int pacman::get_row() const {
	return this->row;
}

int pacman::get_column() const {
	return this->column;
}

void pacman::set_row(int row) {
	this->row = row;
}

void pacman::set_column(int column) {
	this->column = column;
}

void pacman::move_up() {
	this->row--;
}

void pacman::move_down() {
	this->row++;
}

void pacman::move_right() {
	this->column++;
}

void pacman::move_left() {
	this->column--;
}

bool pacman::is_empowered() const {
	return this->empowerment > 0;
}

void pacman::empower() {
	this->empowerment = 30;
}

void pacman::tick() {
	if (this->empowerment > 0) {
		this->empowerment--;
	}
}

void pacman::eat_dot() {
	this->dots_eaten++;
}

void pacman::reset_dots_eaten() {
	this->dots_eaten = 0;
}

int pacman::get_dots_eaten() const {
	return this->dots_eaten;
}
