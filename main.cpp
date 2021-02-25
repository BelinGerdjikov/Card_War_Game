#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 

#include "Game.h"
#include <stdlib.h>


std::string if_continue() {
	std::string name;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout <<std::setw(70) << "Welcome to the game" << std::endl;
	std::cout <<std::setw(70) << "WAR WIH CARDS   " << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << std::setw(70)<<"Type your name  "<< std::endl;
	std::cout << std::setw(50)<<" "; getline(std::cin, name);

	std::ifstream in(name+".txt");
	std::string line;
	getline(in, line);
	if (line == "") {
		std::cout << "You are a new player" << std::endl;
		std::cout << "You have 0 games and 0 wins" << std::endl;
	}
	else {
		int games = 0; int wins = 0;
		in >> games >> wins;
		std::cout << "You have " << games << " games and " << wins << " wins" << std::endl;
	}
	

	return name;
}



bool Start_Menu() {

	int ans;
	do {
		std::cout << std::setw(70) << "---------MENU--------- " << std::endl;
		std::cout << std::setw(70) << "1.Start Game" << std::endl;
		std::cout << std::setw(70) << "2.Exit" << std::endl;
		std::cin >> ans;

		switch (ans) {
		case 1:return 1;
			break;
		case 2:return 0;
			break;
		}

	} while (true);

}

void main() {
	


	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	std::string name= if_continue();
	
	if (Start_Menu()) {
		Game p{ name };
		p.play();
	}
	
	
	
	
}