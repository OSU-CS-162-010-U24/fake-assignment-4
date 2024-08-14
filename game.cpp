#include <iostream>
#include <cctype>

#include "game.hpp"
#include "maze_util.hpp"
#include "print_util.hpp"
#include "fruit.hpp"

game::game() : inky("blue"), pinky("pink"), blinky("red"), clyde("orange") {
	this->reset();
}

void game::reset_pacman() {
	// Set Pac-Man's position to row index 23, column index 12
	this->p.set_row(23);
	this->p.set_column(12);
}

void game::reset_ghosts() {
	// For each ghost, reset ghost's position.
	this->blinky.set_row(13);
	this->blinky.set_column(12);

	this->inky.set_row(14);
	this->inky.set_column(11);

	this->pinky.set_row(14);
	this->pinky.set_column(12);

	this->clyde.set_row(14);
	this->clyde.set_column(13);
}

void game::reset() {
	char game_grid[31][25] {
	// Column 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24
		{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}, // row 0
		{'W', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'W', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'W'}, // row 1
		{'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W'}, // row 2
		{'W', 'P', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'P', 'W'}, // row 3
		{'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W'}, // row 4
		{'W', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'W'}, // row 5
		{'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W'}, // row 6
		{'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W'}, // row 7
		{'W', 'D', 'D', 'D', 'D', 'D', 'D', 'W', 'W', 'D', 'D', 'D', 'W', 'D', 'D', 'D', 'W', 'W', 'D', 'D', 'D', 'D', 'D', 'D', 'W'}, // row 8
		{'W', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', ' ', 'W', ' ', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'W'}, // row 9
		{' ', ' ', ' ', ' ', ' ', 'W', 'D', 'W', 'W', 'W', 'W', ' ', 'W', ' ', 'W', 'W', 'W', 'W', 'D', 'W', ' ', ' ', ' ', ' ', ' '}, // row 10
		{' ', ' ', ' ', ' ', ' ', 'W', 'D', 'W', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W', 'W', 'D', 'W', ' ', ' ', ' ', ' ', ' '}, // row 11
		{' ', ' ', ' ', ' ', ' ', 'W', 'D', 'W', 'W', ' ', 'W', 'W', ' ', 'W', 'W', ' ', 'W', 'W', 'D', 'W', ' ', ' ', ' ', ' ', ' '}, // row 12
		{'W', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'W', ' ', 'W', 'W', ' ', 'W', 'W', ' ', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'W'}, // row 13
		{' ', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', 'W', ' ', ' ', ' ', 'W', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', ' '}, // row 14
		{'W', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'W', ' ', 'W', 'W', 'W', 'W', 'W', ' ', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'W'}, // row 15
		{' ', ' ', ' ', ' ', ' ', 'W', 'D', 'W', 'W', ' ', 'W', 'W', 'W', 'W', 'W', ' ', 'W', 'W', 'D', 'W', ' ', ' ', ' ', ' ', ' '}, // row 16
		{' ', ' ', ' ', ' ', ' ', 'W', 'D', 'W', 'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W', 'W', 'D', 'W', ' ', ' ', ' ', ' ', ' '}, // row 17
		{' ', ' ', ' ', ' ', ' ', 'W', 'D', 'W', 'W', ' ', 'W', 'W', 'W', 'W', 'W', ' ', 'W', 'W', 'D', 'W', ' ', ' ', ' ', ' ', ' '}, // row 18
		{'W', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'W', ' ', 'W', 'W', 'W', 'W', 'W', ' ', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'W'}, // row 19
		{'W', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'W', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'W'}, // row 20
		{'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W'}, // row 21
		{'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'D', 'W'}, // row 22
		{'W', 'P', 'D', 'D', 'W', 'W', 'D', 'D', 'D', 'D', 'D', 'D', ' ', 'D', 'D', 'D', 'D', 'D', 'D', 'W', 'W', 'D', 'D', 'P', 'W'}, // row 23
		{'W', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'W'}, // row 24
		{'W', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'D', 'W', 'W', 'W'}, // row 25
		{'W', 'D', 'D', 'D', 'D', 'D', 'D', 'W', 'W', 'D', 'D', 'D', 'W', 'D', 'D', 'D', 'W', 'W', 'D', 'D', 'D', 'D', 'D', 'D', 'W'}, // row 26
		{'W', 'D', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'D', 'W'}, // row 27
		{'W', 'D', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'D', 'W', 'D', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'D', 'W'}, // row 28
		{'W', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'W'}, // row 29
		{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}  // row 30
	};

	// Create maze. Hint: Use a nested for loop and tile_from_char()
	// as provided by maze_util.hpp to convert the characters in the above
	// array to tiles to store in the 2D vector
	std::vector<std::vector<tile>> maze(31, std::vector<tile>(25));
	
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 25; j++) {
			maze.at(i).at(j) = tile_from_char(game_grid[i][j]);
		}
	}

	this->maze = maze;

	this->reset_pacman();
	this->reset_ghosts();
}

bool game::contains_ghost(int row, int column) const {
	if (this->inky.get_row() == row &&
			this->inky.get_column() == column) {
		return true;
	}

	if (this->blinky.get_row() == row &&
			this->blinky.get_column() == column) {
		return true;
	}
	
	if (this->pinky.get_row() == row &&
			this->pinky.get_column() == column) {
		return true;
	}

	if (this->clyde.get_row() == row &&
			this->clyde.get_column() == column) {
		return true;
	}

	return false;
}

void game::print_ghost(int row, int column) const {
	if (this->inky.get_row() == row &&
			this->inky.get_column() == column &&
			this->inky.get_alive()) {
		this->inky.print();
	} else if (this->blinky.get_row() == row &&
			this->blinky.get_column() == column &&
			this->blinky.get_alive()) {
		this->blinky.print();
	} else if (this->pinky.get_row() == row &&
			this->pinky.get_column() == column &&
			this->pinky.get_alive()) {
		this->pinky.print();
	} else if (this->clyde.get_row() == row &&
			this->clyde.get_column() == column &&
			this->clyde.get_alive()) {
		this->clyde.print();
	}
}
	
void game::print_maze() const {
	for (int i = 0; i < 31; i++) {
		// Print row
		for (int j = 0; j < 25; j++) {
			if (this->p.get_row() == i && this->p.get_column() == j) {
				// If Pac-Man at row i, column j, display
				// Pac-Man
				print_pacman();
			} else if (this->contains_ghost(i, j)) {
				// Else if ghost is at row i, column j, display
				// ghost
				this->print_ghost(i, j);
			} else if (!this->maze.at(i).at(j).is_passable()) {
				// Else if tile at row i, column j is not
				// passable, print wall character
				print_wall();
			} else if (this->maze.at(i).at(j).get_event() != nullptr) {
				// Else if the tile at row i, column j
				// contains an event, print character of event
				// in tile
				this->maze.at(i).at(j).get_event()->print();
			} else {
				std::cout << " ";
			}
		}

		// Print endline
		std::cout << std::endl;
	}
}

void game::print_top_hud() const {
	std::cout << "  Score: ";
	// Print player's score
	std::cout << this->p.get_score();
	std::cout << std::endl;
}

void game::print_bottom_hud() const {
	std::cout << "  ";
	for (int i = 0; i < this->p.get_lives() - 1; i++) {
		// For each remaining life player has, minus 1:
		// Print a Pac-Man icon
		print_pacman();
	}
	
	std::cout << std::endl;
}

bool game::game_over() const {
	// Return true if the game is over, false otherwise.
	return this->p.get_lives() == 0;
}

bool game::is_valid_direction(char direction) const {
	return direction == 'W' || direction == 'A' || direction == 'S' || direction == 'D';
}

bool game::tile_passable(int row, int column) const {
	// Return true if the tile at the given row and column is passable,
	// false otherwise.
	if (column < 0 || column > 24) {
		return true;
	}
	return this->maze.at(row).at(column).is_passable();
}

char game::prompt_player_direction() const {
	char direction;
	int player_row = this->p.get_row();
	int player_column = this->p.get_column();
	int new_row;
	int new_column;
	bool valid_move = false;

	do {
		std::cout << "What direction would you like to move in? " <<
			"(W|A|S|D): ";
		std::cin >> direction;
		direction = toupper(direction);

		if (!this->is_valid_direction(direction)) {
			std::cout << "Invalid option!" << std::endl <<
				std::endl;
		} else {
			new_row = player_row;
			new_column = player_column;
			if (direction == 'W') {
				new_row--;
			} else if (direction == 'A') {
				new_column--;
			} else if (direction == 'S') {
				new_row++;
			} else {
				new_column++;
			}

			if (!this->tile_passable(new_row, new_column)) {
				std::cout << "There's a wall in your way!" <<
					std::endl << std::endl;
			} else {
				valid_move = true;
			}
		}
	} while(!valid_move);

	return direction;
}

void game::move_pacman(char direction) {
	if (direction == 'W') {
		// Move Pac-Man up
		this->p.move_up();
	} else if (direction == 'A') {
		// Move Pac-Man left
		this->p.move_left();
		if (this->p.get_column() < 0) {
			this->p.set_column(24);
		}
	} else if (direction == 'S') {
		// Move Pac-Man down
		this->p.move_down();
	} else {
		// Move Pac-Man right
		this->p.move_right();
		if (this->p.get_column() > 24) {
			this->p.set_column(0);
		}
	}
}

void game::trigger_event_encounter() {
	if (this->maze.at(this->p.get_row()).at(this->p.get_column()).get_event() != nullptr) {
		// If Pac-Man is on tile with event, trigger the event's
		// encounter
		this->maze
			.at(this->p.get_row())
			.at(this->p.get_column())
			.get_event()
				->encounter(this->p);
		
		// Remove the event from the maze
		this->maze
			.at(this->p.get_row())
			.at(this->p.get_column())
			.clear_event();
	}
}

void game::trigger_ghost_encounter() {
	if (this->p.get_row() == this->inky.get_row() &&
			this->p.get_column() == this->inky.get_column() &&
			this->inky.get_alive()) {
		if (this->p.is_empowered()) {
			this->inky.death();
		} else {
			this->p.death();
			this->reset_pacman();
			this->reset_ghosts();
		}
	}

	if (this->p.get_row() == this->blinky.get_row() &&
			this->p.get_column() == this->blinky.get_column() &&
			this->blinky.get_alive()) {
		if (this->p.is_empowered()) {
			this->blinky.death();
		} else {
			this->p.death();
			this->reset_pacman();
			this->reset_ghosts();
		}
	}

	if (this->p.get_row() == this->pinky.get_row() &&
			this->p.get_column() == this->pinky.get_column() &&
			this->pinky.get_alive()) {
		if (this->p.is_empowered()) {
			this->pinky.death();
		} else {
			this->p.death();
			this->reset_pacman();
			this->reset_ghosts();
		}
	}

	if (this->p.get_row() == this->clyde.get_row() &&
			this->p.get_column() == this->clyde.get_column()) {
		if (this->p.is_empowered()) {
			this->clyde.death();
		} else {
			this->p.death();
			this->reset_pacman();
			this->reset_ghosts();
		}
	}
}

void game::player_action() {
	char direction = this->prompt_player_direction();
	this->move_pacman(direction);
	this->trigger_event_encounter();
	this->trigger_ghost_encounter();
}

int game::choose_random_direction(int row, int column) const {
	int direction; // 1 means up, 2 down, 3 left, 4 right
	bool invalid_direction;
	do {
		direction = rand() % 4 + 1;
		if (direction == 1) {
			if (this->maze.at(row - 1).at(column).is_passable()) {
				invalid_direction = false;
			} else {
				invalid_direction = true;
			}
		} else if (direction == 2) {
			if (this->maze.at(row + 1).at(column).is_passable()) {
				invalid_direction = false;
			} else {
				invalid_direction = true;
			}
		} else if (direction == 3) {
			if (this->maze.at(row).at(column - 1).is_passable()) {
				invalid_direction = false;
			} else {
				invalid_direction = true;
			}
		}  else if (direction == 4) {
			if (this->maze.at(row).at(column + 1).is_passable()) {
				invalid_direction = false;
			} else {
				invalid_direction = true;
			}
		}
	} while (invalid_direction);

	return direction;
}

void game::ghost_actions() {
	// For each ghost, choose a random empty adjacent space to move to
	// if one exists.
	int direction = this->choose_random_direction(
		this->inky.get_row(),
		this->inky.get_column()
	);
	if (direction == 1) {
		this->inky.move_up();
	} else if (direction == 2) {
		this->inky.move_down();
	} else if (direction == 3) {
		this->inky.move_left();
	} else {
		this->inky.move_right();
	}

	direction = this->choose_random_direction(
		this->blinky.get_row(),
		this->blinky.get_column()
	);
	if (direction == 1) {
		this->blinky.move_up();
	} else if (direction == 2) {
		this->blinky.move_down();
	} else if (direction == 3) {
		this->blinky.move_left();
	} else {
		this->blinky.move_right();
	}

	direction = this->choose_random_direction(
		this->pinky.get_row(),
		this->pinky.get_column()
	);
	if (direction == 1) {
		this->pinky.move_up();
	} else if (direction == 2) {
		this->pinky.move_down();
	} else if (direction == 3) {
		this->pinky.move_left();
	} else {
		this->pinky.move_right();
	}

	direction = this->choose_random_direction(
		this->clyde.get_row(),
		this->clyde.get_column()
	);
	if (direction == 1) {
		this->clyde.move_up();
	} else if (direction == 2) {
		this->clyde.move_down();
	} else if (direction == 3) {
		this->clyde.move_left();
	} else {
		this->clyde.move_right();
	}

	this->trigger_ghost_encounter();
	// Trigger ghost encounter if ghost is in same location as Pac-Man
}

void game::print_final_score() const {
	std::cout << "Your final score: ";
	// Print player's final score
	std::cout << this->p.get_score();
}

void game::play() {
	while (!this->game_over()) {
		// Print heads-up display (score, lives) and maze
		this->print_top_hud();
		this->print_maze();
		this->print_bottom_hud();

		// Allow player to perform action
		this->player_action();

		// Process ghosts' turns
		this->ghost_actions();

		this->p.tick();

		if (!this->p.is_empowered()) {
			if (!this->inky.get_alive()) {
				this->inky.respawn(14, 11);
			}
			if (!this->blinky.get_alive()) {
				this->blinky.respawn(13, 12);
			}
			if (!this->pinky.get_alive()) {
				this->pinky.respawn(14, 12);
			}
			if (!this->clyde.get_alive()) {
				this->clyde.respawn(14, 13);
			}
		}

		if (this->p.get_dots_eaten() == 30) {
			this->maze.at(17).at(12).set_event(new fruit);
		}

		if (this->p.get_dots_eaten() == 224) {
			this->reset();
		}
	}

	this->print_final_score();
}
