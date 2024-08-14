#ifndef PACMAN_HPP
#define PACMAN_HPP

class pacman {
private:
	int lives = 3;
	int score = 0;
	int row = 0;
	int column = 0;
	int empowerment = 0;
	int dots_eaten = 0;
public:
	int get_lives() const;
	void death();

	int get_score() const;
	void increase_score(int amount);

	int get_row() const;
	int get_column() const;
	void set_row(int row);
	void set_column(int column);
	void move_up();
	void move_down();
	void move_right();
	void move_left();

	bool is_empowered() const;
	void empower();

	void tick();

	void eat_dot();
	void reset_dots_eaten();
	int get_dots_eaten() const;
};

#endif
