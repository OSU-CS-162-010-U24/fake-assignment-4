#ifndef GAME_HPP
#define GAME_HPP

#include "tile.hpp"

class game {
private:
	// Reset pacman's position
	void reset_pacman();

	// Reset ghosts' positions
	void reset_ghosts();

	// Reset entire maze
	void reset();
	
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

	void ghost_actions();

	void print_final_score() const;
public:
	game();
	void play();
};

#endif
