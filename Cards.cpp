#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 

#include "Cards.h"

   
Cards::Cards() :i{0} {

}
Cards::~Cards() {

}

void Cards::create() {
	char A[13][2] = { {'2'},{'3'},{'4'},{'5'},{'6'},{'7'},{'8'},{'9'},{'1','0'},{'J'},{'Q'},{'K'},{'A'} };

	char temp_color[4][9]{ {'S','p','a','d','e','s'},{'H','e','a','r','t','s'},{'D','i','a','m','o','n','d','s'},{'C','l','u','b','s'} };
	int value = 2;
	int index = 0;

	for (int i = 0; i < 13; i++) {
		for (int y = 0; y < 4; y++) {
			if (i == 8) {
				p[index].create(value, "10",temp_color[y]);
				index++;
			}
			else {
				p[index].create(value, A[i], temp_color[y]);
				index++;
			}
		}
		value++;
	}
}

void Cards::display() {
	for (int y = 0; y < i; y++) {
		p[y].display();
	}
}

void Cards::shuffle() {
	int random;
	Card temp;
	srand(time(0));
	for (int i = 0; i < 52; i++) {
		random = rand() % 52;
		if (random != i) {
			temp = p[i];
			p[i] = p[random];
			p[random] = temp;
		}


	}


}

void Cards::remove(int t) {
	
		p[t].remove();
		for (int y = t; y < i - 1; y++) {
			p[y] = p[y + 1];
		}
		i--;
		Card clear;
		p[i] = clear;
		
}

void Cards::rotate(int t) {
	Card temp;
	
	if (i < 7&&t>0) {
		temp=p[t];
		p[t] = p[0];
		p[0] = temp;
	}
	
}


int Cards::the_lowest() {
	int n = 0;
	Card temp = p[0];
	if (i > 1) {
		for (int y = 1; y < i; y++) {
			if (temp>p[y]) {
				temp = p[y];
				n = y;
			}
		}
	}
	return n;
}
int Cards::the_highest() {
	int n = 0;
	Card temp = p[0];
	if (i > 1) {
		for (int y = 1; y < i; y++) {
			if (temp < p[y]) {
				temp = p[y];
				n = y;
			}
		}
	}
	return n;
}


Card::Card(int value1, const char* symbol1, const char* color1) :value{value1} {
strcpy(symbol, symbol1);
strcpy(color, color1);
}