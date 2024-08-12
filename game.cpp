#include <iostream>
#include <cctype>

#include "game.hpp"
#include "maze_util.hpp"

game::game() {
	this->reset();
}

void game::reset_pacman() {
	// TODO Set Pac-Man's position to row index 23, column index 12
}

void game::reset_ghosts() {
	// TODO For each ghost, reset ghost's position
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

	// TODO Create maze. Hint: Use a nested for loop and tile_from_char()
	// as provided by maze_util.hpp to convert the characters in the above
	// array to tiles to store in the 2D vector

	this->reset_pacman();
	this->reset_ghosts();
}
	
void game::print_maze() const {
	for (int i = 0; i < 31; i++) {
		// Print row
		for (int j = 0; j < 25; j++) {
				// TODO If Pac-Man at row i, column j, display
				// Pac-Man

				// TODO Else if ghost is at row i, column j, display
				// ghost

				// TODO Else if tile at row i, column j is not
				// passable, print wall character

				// TODO Else, print character of event in tile at
				// row i, column j
		}

		// Print endline
		std::cout << std::endl;
	}
}

void game::print_top_hud() const {
	std::cout << "  Score: ";
	// TODO Print player's score
	std::cout << std::endl;
}

void game::print_bottom_hud() const {
	std::cout << "  ";
		// TODO For each remaining life player has, minus 1:
			// TODO Print a Pac-Man icon
	std::cout << std::endl;
}

bool game::game_over() const {
	// TODO Return true if the game is over, false otherwise.
	
	// TODO Remove this line of code
	return false;
}

bool game::is_valid_direction(char direction) const {
	return direction == 'W' || direction == 'A' || direction == 'S' || direction == 'D';
}

bool game::tile_passable(int row, int column) const {
	// TODO Return true if the tile at the given row and column is passable,
	// false otherwise.
	
	// TODO Remove this line of code
	return true;
}

char game::prompt_player_direction() const {
	char direction;
	int player_row = 0; // TODO Change this to PacMan's current row idx
	int player_column = 0; // TODO Change this to PacMan's current col idx
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
		// TODO Move Pac-Man up
	} else if (direction == 'A') {
		// TODO Move Pac-Man left
	} else if (direction == 'S') {
		// TODO Move Pac-Man down
	} else {
		// TODO Move Pac-Man right
	}
}

void game::trigger_event_encounter() {
		// TODO If Pac-Man is on tile with event, trigger the event's
		// encounter
}

void game::trigger_ghost_encounter() {
		// TODO If Pac-Man is on tile with ghost, trigger ghost encounter
}

void game::player_action() {
	char direction = this->prompt_player_direction();
	this->move_pacman(direction);
	this->trigger_event_encounter();
	this->trigger_ghost_encounter();
}

void game::ghost_actions() {
	// TODO For each ghost, choose a random empty adjacent space to move to
	// if one exists.

	this->trigger_ghost_encounter();
	// Trigger ghost encounter if ghost is in same location as Pac-Man
}

void game::print_final_score() const {
	std::cout << "Your final score: ";
	// TODO Print player's final score
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
	}

	this->print_final_score();
}
