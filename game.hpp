#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "tile.hpp"
#include "pacman.hpp"
#include "ghost.hpp"

class game {
private:
	pacman p;
	ghost inky; // Blue ghost
	ghost pinky; // Pink ghost
	ghost blinky; // Red ghost
	ghost clyde; // Orange ghost

	std::vector<std::vector<tile>> maze;

	// Reset pacman's position
	void reset_pacman();

	// Reset ghosts' positions
	void reset_ghosts();

	// Reset entire maze
	void reset();

	bool contains_ghost(int row, int column) const;
	void print_ghost(int row, int column) const;
	
	// Printing functions
	void print_top_hud() const;
	void print_maze() const;
	void print_bottom_hud() const;

	bool game_over() const;

	bool is_valid_direction(char direction) const;
	bool tile_passable(int row, int column) const;
	char prompt_player_direction() const;

	void move_pacman(char direction);
	void trigger_event_encounter();
	void trigger_ghost_encounter();
	void player_action();

	int choose_random_direction(int row, int column) const;

	void ghost_actions();

	void print_final_score() const;
public:
	game();
	void play();
};

#endif
