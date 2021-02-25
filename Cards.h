#ifndef CARDS_H_
#define CARDS_H_
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 
#include "Card.h"
#include <time.h> 
#include <stdlib.h>
class Cards
{
protected:
	Card p[52];
	int i;
public:
	Cards();
	~Cards();
	void display();
	void create();
	void shuffle();
	int get_i() { return i; };
	Card get_card(int i1) { return p[i1]; }
	void add_card(const Card& obj) {
		p[i] = obj;
		i++;
	}

	bool check_for_copies() {
		for (int y = 0; y < i-1; y++) {
			for (int z = 0; z < i-1; z++) {
				if (z != y) {
					if (p[y]==p[z]) {
						return true;
					}
				}
			}
		}

		return 0;
	}
	
	bool operator<(Cards rhs) {
		if (this->p[0].get_value() < rhs.p[0].get_value()) {
			return true;
		}
		
		return false;
	}
	bool operator==(Cards rhs) {
		return this->p[0].get_value() == rhs.p[0].get_value();
	}

	void remove(int t=0);
	Card move_card(int t=0) {
		return p[t];
	}

	void send_back() {
		
			Card temp = p[0];
			for (int y = 0; y < i - 1; y++) {
				p[y] = p[y + 1];
			}
			p[i - 1] = temp;
		
	}

	void display_in_game(int n=0) {
		p[n].display();
	}
	
	void rotate(int t);
	int the_lowest();
	int the_highest();
};

#endif CARD_H_

