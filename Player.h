#ifndef Player_H_
#define Player_H_
#include "Cards.h"
#include <string>
class Player
{
private:
	Cards p_cards;
	std::string name;
	int wins;
	int games;
	double w_s;
	friend std::ostream& operator<<(std::ostream&os ,const Player player) {
		os << player.name << std::endl;
		os << player.games << " " << player.wins << std::endl;
		return os;
	}

	friend std::istream& operator>>(std::istream& is,Player player) {
		getline(is,player.name);
		is >> player.games >> player.wins;
		return is;
	}
public:
	Player(std::string name1="BOT",int games1=0,int wins1=0);
	void win_lose() { w_s = (wins / games); }
	void inc_win() { wins++; }
	void inc_games() { games++; }
	void add_cards(const Card& obj);
	int get_i() { return p_cards.get_i(); };
	void display() {
		p_cards.display();
	}
	bool is_lower(const Player &rhs) {
		return this->p_cards < rhs.p_cards;
	}
	bool is_equal(const Player &rhs) {
		return this->p_cards == rhs.p_cards;
	}
	void remove(int t=0) {
		p_cards.remove(t);
	}

	Card move_card(int t=0) {
		return p_cards.move_card(t);
	}

	void send_back() {
		p_cards.send_back();
	}

	void display_in_game(int n = 0) {
		p_cards.display_in_game(n);
	}

	void check_for_copies() {
		if (p_cards.check_for_copies()) {
			std::cout << "Error";
		}
	}

	void rotate(int t) {
		p_cards.rotate(t);
	}

	int the_lowest() {
		return p_cards.the_lowest();
	}
	int the_highest() {
		return p_cards.the_highest();
	}

	std::string get_name() {
		return name;
	}

	void set_name(std::string name) { this->name = name; }
	void set_games(int games) { this->games = games; }
	void set_wins(int wins) { this->wins = wins; }

	int get_games() { return games; }
	int get_wins() { return wins; }
	double get_w_s(){ return w_s; }

	void display1() {
		std::cout << std::setw(70) << name << "      " << std::endl;
		std::cout << std::setw(70) << "Games: " << games << " Wins: " << wins << " Win rate%: " << w_s * 100 << std::endl;
	}
};

#endif Player_H_
