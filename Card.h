#ifndef CARD_H_
#define CARD_H_
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 
#include <iostream>
#include <cstring>
#include <iomanip>

class Card
{
protected:
	int value;
	char symbol[3];
	char color[9];
	friend std::ostream& operator<<(std::ostream &os, const Card& card) {
		os << card.value << " " << card.symbol << " " << card.color << std::endl;
		return os;
	}

	friend std::istream& operator>>(std::istream &is,Card& card) {
		is >> card.value >> card.symbol >> card.color;
		return is;
	}
public:
	Card();
	Card(int value1, const char* symbol1, const char* color1);
	~Card();
	void display();
	void create(int value1, const char* symbol1, const char* color1);
	Card &operator=(const Card &rhs);
	/*Card& operator=(Card&& rhs) {
		value = rhs.value;
		strcpy(symbol, rhs.symbol);
		strcpy(color, rhs.color);
		return *this;
	}*/
	void set_value(int value1) { value = value1; }
	void set_symbol(const char* symbol1); 
	void set_color(const char* color1) ; 
	int get_value() { return value; }
	void remove();
	bool operator==(const Card& rhs) {
		if (this->value == rhs.value && !strcmp(this->color, rhs.color) && !strcmp(this->symbol, rhs.symbol)) {
			return 1;
		}

		return 0;
	}
	
	const char* get_symbol() { return symbol; }
	const char* get_color() { return color; }

	bool operator<(const Card& rhs) {
		return value < rhs.value;
	}
	
	bool operator>(const Card& rhs) {
		return value > rhs.value;
	}
	bool operator!=(const Card& rhs) {
		if (this->value == rhs.value && !strcmp(this->color, rhs.color) && !strcmp(this->symbol, rhs.symbol)) {
			return 0;
		}
		return 1;
	}
	
};

#endif CARD_H_