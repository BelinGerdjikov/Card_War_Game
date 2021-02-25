#include "Card.h"


Card::Card() :value{ 0 }, color{ "" }, symbol{""} {

}


Card::~Card() {
}

void Card::set_symbol(const char* symbol1) { strcpy(symbol, symbol1); }
void Card::set_color(const char* color1) { strcpy(color, color1); }

void Card::display() {
	std::cout << std::setw(90) << std::right << " _______________" << std::endl;
	std::cout << std::setw(80) << std::right << "|     "<<std::setw(10)<<std::right<<symbol<<"|    "<<value << std::endl;
	std::cout << std::setw(80) << std::right << "|     "<<std::setw(10)<<std::right << color<<"|" << std::endl;
	std::cout << std::setw(91) << std::right << "|               |" << std::endl;
	std::cout << std::setw(91) << std::right << "|               |" << std::endl;
	std::cout << std::setw(91) << std::right << "|               |" << std::endl;
	std::cout << std::setw(91) << std::right << "|               |" << std::endl;
	std::cout << std::setw(91) << std::right << "|               |" << std::endl;
	std::cout << std::setw(75) << std::right << "|"<<std::setw(10)<<std::left <<color<<"     |" << std::endl;
	std::cout << std::setw(75) << std::right << "|"<<std::setw(10)<<std::left<<symbol<<"     |" << std::endl;
	std::cout << std::setw(91) << std::right << "|_______________|" << std::endl;
	std::cout << std::endl;
}
void Card::create(int value1,const char*symbol1,const char*color1) {
	value = value1;
	strcpy(symbol, symbol1);
	strcpy(color, color1);
}
Card& Card::operator=(const Card& rhs) {
	if (this == &rhs) {
		return *this;
	}
	this->value=rhs.value;
	strcpy(this->symbol,rhs.symbol);
	strcpy(this->color,rhs.color);
	return *this;
}

void Card::remove()
{
	value= 0;
	strcpy(color, "");
	strcpy(symbol,"");
	
}