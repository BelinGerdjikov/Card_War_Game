#ifndef GAME_H_
#define GAME_H_
#include "Player.h"
#include <dos.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <set> 

class Game
{
protected:
	Player bot;
	Player real;
	Cards deck;
public:
	Game(std::string filename);
	~Game();
	
	void play();
	void war(const Card real_c, const Card bot_c, int& h);
	void not_enough_cards();
	void three_card_to_choose_real();
	void three_card_to_choose_bot();
	void validation(int& choice, int vali);
	void three_card_to_choose_for_war_real(Card real_c, Card bot_c);
	void Display_for_there_cards_war(Card bot_c);
	void advice(int n, std::string text);
	void Space_for_Cards();
	void three_card_to_choose_for_war_bot(Card real_c, Card bot_c);
	void three_card_to_choose_for_war_bot_template(int& n, int without);
	void war_display(int real_card,int bot_card,Card real_c,Card bot_c);
	void real_to_pick(int& ans);
	void ofstream1(std::string file);
	void ifstream1(std::string file);
	bool want_to_continue();
	void Exit_menu(bool game_finish);

	
};
#endif GAME_H_