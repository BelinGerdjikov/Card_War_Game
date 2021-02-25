#include "Game.h"

Game::Game(std::string filename){
	std::ifstream in((filename+".txt"));
	std::string line;
	getline(in,line);
	if (line == "") {
		line = filename;
		in.close();
		std::ofstream out((filename + ".txt"), std::ios::app);
		out << filename << std::endl << 0 << " " << 0 << std::endl << "BOT" << std::endl << 0 << " "<<0 << std::endl;
		out.close();
	}
	real.set_name(line);
	int games(0), wins(0);
	in >> games >> wins;
	real.set_games(games); real.set_wins(wins);
		getline(in, line);
		getline(in, line);
		bot.set_name("BOT");
		in >> games >> wins;
		bot.set_games(games); bot.set_wins(wins);
	bool gamesaved = 0;
	in >> gamesaved;
	in.close();
	if (gamesaved&& want_to_continue()) {
		
			ifstream1(filename + ".txt");
	}
	else {
		real.inc_games();
		bot.inc_games();
		deck.create();
		deck.shuffle();
		deck.shuffle();
		deck.shuffle();
		int i = 0;
		do {
			real.add_cards(deck.get_card(i));
			i++;
			bot.add_cards(deck.get_card(i));
			i++;
		} while (i < 52);
	}
}
Game::~Game() {

}

bool Game::want_to_continue() {
	int ans;
	std::cout << std::setw(70)<<  "You have a saved game  " << std::endl;
	std::cout << std::setw(70) << "Do you want to continue" << std::endl;
	std::cout << std::setw(70) << "If you dicide not to   " << std::endl;
	std::cout << std::setw(70) << "you will lose your save" << std::endl;
	std::cout << std::setw(50) << "1.Yes" << std::endl;
	std::cout << std::setw(50) << "2.No " << std::endl;

	validation(ans,2);
	if (ans == 1) {
		return 1;
	}
	else {
		bot.inc_win();
		return 0;
	}
}

void Game::play() {
	
	int rounds = 0;
	bool game_finish = 0;
	char p='y';
	while (real.get_i() > 0 && bot.get_i() > 0 &&real.get_i()<52&& bot.get_i() < 52&&(p!='q'&&p!='Q')) {

		bot.display_in_game();
		Sleep(1000);
		std::cout << std::setw(70) << std::right << bot.get_name()<<" have " << bot.get_i()<<" cards" << std::endl;
		std::cout << std::setw(93) << std::right <<"----------VS----------" << std::endl;
		std::cout << std::setw(70) << std::right << real.get_name()<<" have "<< real.get_i()<<" cards" << std::endl;
		Sleep(1000);
		if(real.get_i()>=4)
		real.display_in_game();

		if (real.get_i() == 0)
			real.display_in_game();
		Sleep(1000);
		
		if (real.get_i() < 4 && real.get_i() > 1) {
			three_card_to_choose_real();
		}

		if (bot.get_i() < 4 && bot.get_i() > 1) {
			three_card_to_choose_bot();
		}

		if (real.is_equal(bot)) {
			
			int h=0;
			Card temp[2];
			temp[0] = real.move_card();
			real.remove();
			temp[1] = bot.move_card();
			bot.remove();
			war(temp[0],temp[1],h);
			if (h == -1) {
				bot.add_cards(temp[0]);
				bot.add_cards(temp[1]);
			}
			else if (h == 1) {
				real.add_cards(temp[0]);
				real.add_cards(temp[1]);
			}
				
		}
		else {
			
			if (real.is_lower(bot)) {
				bot.add_cards(real.move_card());
				bot.send_back();
				real.remove();
				std::cout << std::endl << std::endl;
				std::cout<<std::setw(80) << std::right << "!!! "<<bot.get_name()<<" WINS!!!" << std::endl;
			}
			else {
				real.add_cards(bot.move_card());
				real.send_back();
				bot.remove();
				std::cout << std::endl << std::endl;
				std::cout << std::setw(80) << std::right << "!!! " << real.get_name() << " WINS!!!" << std::endl;
			}
			
			std::cout << "If you want to quite press Q" << std::endl;
			Sleep(900);
			p = _getch();
		}
			rounds++;
			system("cls");
	}

	if (real.get_i()==52) {
		std::cout << std::setw(80) << std::right << "!!! " << real.get_name() << " WINS THE GAME!!!" << std::endl;
		real.inc_win();
		game_finish = 1;
	}
	else if(bot.get_i()==52) {
		std::cout << std::setw(80) << std::right << "!!! " << bot.get_name() << " WINS THE GAME!!!" << std::endl;
		bot.inc_win();
		game_finish = 1;
	}

	
		
			std::ofstream out(real.get_name() + ".txt");
			out << real << bot;

		if (game_finish) {
			out << 0 << std::endl;
			out.close();
		}
		else {
			Exit_menu(game_finish);
		}
		
	

}
void Game::war(Card real_c,Card bot_c,int& h) {
	Sleep(2500);
	std::cout << std::endl << std::setw(85) << std::right << bot.get_name() << " IT IS A WAR" << std::endl;
	Card temp[6];
	
	if (real.get_i() < 6 && real.get_i() > 2) {
		three_card_to_choose_for_war_real(real_c, bot_c);
	}

	if (bot.get_i() < 6 && bot.get_i() > 2) {
		three_card_to_choose_for_war_bot(real_c, bot_c);
	}

	if (real.get_i()<3) {
		not_enough_cards();
	}

	if (bot.get_i() < 3) {
		not_enough_cards();
	}
	int num = 0;
	    Sleep(2500);
		war_display(3, 3, real_c, bot_c);
		
	
	for (int y = 0; y < 3; y++) {
		temp[y] = real.move_card();
		real.remove();
	}

	for (int y = 3; y < 6; y++) {
		temp[y] = bot.move_card();
		bot.remove();
	}

	if (temp[2].get_value()==temp[5].get_value()) {
		
		war(temp[2],temp[5],h);
		
	}

	if (h == 0) {
		if (temp[2]<temp[5]) {
			h = -1;
			
		}
		else {
			h = 1;
			
		}
	}
 
		if (h == -1) {
			for (int p = 0; p < 6; p++) {
				bot.add_cards(temp[p]);
			}
		}
		else if (h == 1) {
			for (int p = 0; p < 6; p++) {
				real.add_cards(temp[p]);
			}
		}
	
		system("Pause");
	
}
void Game::real_to_pick(int& ans) {
	std::cout << std::setw(90) << std::right << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << std::setw(90) << std::right << "You don't have enough card/s to finish the War" << std::endl;
	std::cout << std::setw(90) << std::right << "You have to pick " << 3-real.get_i() << " card/s from your opponent" << std::endl;
	std::cout << std::setw(90) << std::right << "Your opponent have " << bot.get_i() << "Good luck mate " << std::endl;
	validation(ans, bot.get_i());
	ans--;
	system("cls");
	
	real.add_cards(bot.move_card(ans));
	bot.remove(ans);
	std::cout << "You pick this card to be in " << real.get_i() << " position" << std::endl;
	real.display_in_game(real.get_i()-1);
}

void Game::not_enough_cards() {


	int n = 0;
	int ans;
	int random;
	srand(time(0));
	if (real.get_i() < 3) {
		
		real_to_pick(ans);
		Sleep(800);
	
		if (real.get_i() == 1) {
			
			real_to_pick(ans);
			Sleep(800);
			
			real_to_pick(ans);
			Sleep(800);
		}
		else if (real.get_i() == 2) {
			
			real_to_pick(ans);
			Sleep(800);
		}
		

	}
	else if (bot.get_i()<3) {
		std::cout << std::setw(90) << std::right << bot.get_name() << "need to pick"<<3-bot.get_i()<<"from you" << std::endl;
		system("pause");
		
		random = rand() % real.get_i();
		bot.add_cards(real.move_card(random));
		real.remove(random);
		if (bot.get_i() == 1) {
			random = rand() % real.get_i();
			bot.add_cards(real.move_card(random));
			real.remove(random);

			random = rand() % real.get_i();
			bot.add_cards(real.move_card(random));
			real.remove(random);
		}
		else if (bot.get_i() == 2) {
			random = rand() % real.get_i();
			bot.add_cards(real.move_card(random));
			real.remove(random);
		}
	}
}

void Game::three_card_to_choose_real() {
	int ans;
	std::cout << "You have "<<real.get_i()<<" card/s left" << std::endl;
	std::cout << "Choose what card you want to use" << std::endl;
	real.display();
	validation(ans, real.get_i());
	ans--;
	if (ans == 0) {

		
	}
	else {
		real.rotate(ans);
	}
	bot.display_in_game();
	std::cout << std::setw(70) << "----------VS----------" << std::endl;
	real.display_in_game();
	Sleep(500);


}
void Game::three_card_to_choose_bot() {
	if (bot.move_card() < real.move_card()||bot.move_card()==real.move_card()){
		Card temp[4];
		int n = bot.the_highest();
		bool done = 0;
		if (bot.move_card(n) > real.move_card()) {
			done = 1;
		}

		if (done == 0&& bot.move_card(n) == real.move_card()) {
			done = 1;
		}

		if (done == 0) {
			n = bot.the_lowest();
			done = 1;
		}

		if (n!=0) {
			int i_temp = bot.get_i();
			for (int y = 0; y < i_temp; y++) {
				temp[y] = bot.move_card();
				bot.remove();
			}

			temp[3] = temp[n];
			temp[n] = temp[0];
			temp[0] = temp[3];

			for (int y = 0; y < i_temp; y++) {
				bot.add_cards(temp[y]);
			}
		}
	}
}
void Game::validation(int& choice, int vali) {
	std::cin >> choice;
	while (std::cin.good() == false) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout<<std::setw(70) << "You have entered a letter" << std::endl;
		validation(choice, vali);
	}
	while (choice < 1 || choice>vali) {
		std::cout << std::setw(70) << "You have entered an incorrect number" << std::endl;
		std::cout << std::setw(70) << "Enter a number from 1 to " << vali << std::endl;;
		validation(choice, vali);
	}
	
}

void Game::three_card_to_choose_for_war_real(Card real_c, Card bot_c) {
	Card temp[5];
		
	int ans;
	if (real.get_i() == 3) {
		Display_for_there_cards_war(bot_c);
		Space_for_Cards(); Space_for_Cards(); Space_for_Cards();
		real_c.display();

		advice(3,"You should save your higher card for last");

		validation(ans, 3);
		ans--;
		temp[0] = real.move_card(ans);
		real.remove(ans);
		system("cls");
		
		Display_for_there_cards_war(bot_c);
		Space_for_Cards(); Space_for_Cards();
		temp[0].display();
		real_c.display();

		advice(2, "You should save your higher card for last");

		validation(ans, 2);
		ans--;
		temp[1] = real.move_card(ans);
		real.remove(ans);
		system("cls");
		
		
		temp[2] = real.move_card();
		real.remove();
		
		for (int y = 0; y < 3; y++) {
			real.add_cards(temp[y]);
		}

		
	}
	else if (real.get_i() == 4) {

		Display_for_there_cards_war(bot_c);
		temp[0] = real.move_card();
		real.remove();
		Space_for_Cards(); Space_for_Cards();
		temp[0].display();
		real_c.display();
		
		advice(3, "You should save your higher card for last");

		validation(ans, 3);
		ans--;
		temp[1] = real.move_card(ans);
		real.remove(ans);
		system("cls");

		Display_for_there_cards_war(bot_c);
		Space_for_Cards();
		temp[1].display();
		temp[0].display();
		real_c.display();
		

		advice(2, "You should pick the higher one if you thik you can win the WAR");
		validation(ans, 2);
		ans--;
		temp[2] = real.move_card(ans);
		real.remove(ans);
		temp[3] = real.move_card();
		real.remove();

		for (int y = 0; y < 4; y++) {
			real.add_cards(temp[y]);
		}
		system("cls");
	}
	else if (real.get_i() == 5) {
		real.display_in_game();
		temp[0] = real.move_card();
		real.remove();
		real.display_in_game();
		temp[1] = real.move_card();
		real.remove();

		Display_for_there_cards_war(bot_c);
		Space_for_Cards();
		temp[1].display();
		temp[0].display();
		real_c.display();

		advice(3, "You should pick the higher one if you thik you can win the WAR");
		validation(ans, 3);
		ans--;
		temp[2] = real.move_card(ans);
		real.remove(ans);
		
		temp[3] = real.move_card();
		real.remove();
		
		temp[4] = real.move_card();
		real.remove();
		for (int y = 0; y < 5; y++) {
			real.add_cards(temp[y]);
		}
		system("cls");
	}
	Sleep(1200);
}

void Game::three_card_to_choose_for_war_bot(Card real_c, Card bot_c) {
	
	int n=0;
	if (real.move_card(2) < bot.move_card(2)&& real.move_card(2) != bot.move_card(2)) {

	}else{
		
		Card temp[5];
		if (bot.get_i() == 3) {
			n = 2;
			for (int y = 0; y < 3;y++) {
				three_card_to_choose_for_war_bot_template(n, 3);
				temp[y] = bot.move_card();
				bot.remove();
			}
			n = 3;
		}
		else if (bot.get_i() == 4) {
			temp[0] = bot.move_card();
			bot.remove();
			n = 1;
			for (int y = 1; y < 4; y++) {
				three_card_to_choose_for_war_bot_template(n, 3);
				temp[y] = bot.move_card();
				bot.remove();
			}
			n = 4;
		}
		else if (bot.get_i() == 5) {
			n = 0;
			for (int y = 0; y < 2; y++) {
				temp[y] = bot.move_card();
				bot.remove();
			}

			three_card_to_choose_for_war_bot_template(n,3);
			
			for (int y = 2; y < 5; y++) {
				temp[y] = bot.move_card();
				bot.remove();
			}
			n = 5;
		}

		for (int y = 0; y < n; y++) {
			bot.add_cards(temp[y]);
		}

	}
}

void Game::three_card_to_choose_for_war_bot_template(int &n,int without) {
	int t;
	if (n == 0) {
		t = bot.the_highest();
		if (bot.move_card(t) > real.move_card(2)) {
			if (t != 0) {
				bot.rotate(t);
			}
		}
		else if (bot.move_card(t) == real.move_card(2)) {
			if (t != 0) {
				bot.rotate(t);
			}
		}
		else {
			t = bot.the_lowest();
			if (t != 0) {
				bot.rotate(t);
			}
		}
			
	}
	else if(n>0){
		t=bot.the_lowest();
		if (t != 0) {
			bot.rotate(t);
			n--;
		}
	}
}

void Game::Display_for_there_cards_war(Card bot_c) {
	std::cout << "----------WAR----------" << std::endl;
	int num = 0;
	bot_c.display();
	bot.display_in_game(num);
	num++;
	bot.display_in_game(num);
	num++;
	bot.display_in_game(num);

	std::cout << "----------VS----------" << std::endl;
}

void Game::advice(int n,std::string text) {
	std::cout << "Now is your choice" << std::endl;
	real.display();
	std::cout << "You have "<<n<<" cards left" << std::endl;
	std::cout << "Be carefull which one you pick" << std::endl;
	std::cout << text << std::endl;
}

void Game::Space_for_Cards() {
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
}




void Game::war_display(int real_card, int bot_card, Card real_c, Card bot_c) {

	std::cout << std::setw(93) << std::right << "----------WAR----------" << std::endl;
	bot_c.display();

	for (int y = 0; y < bot_card; y++) {
		bot.display_in_game(y);
		
	}

	for (int y = 0; y < 3 - bot_card; y++) {
		Space_for_Cards();
	}

	if (bot.move_card() == real.move_card()) {
		std::cout << std::setw(80) << std::right <<"!!!It is a DRAW" << std::endl;
	}
	else if (bot.move_card() > real.move_card()) {
		std::cout << std::setw(80) << std::right << "!!!" <<bot.get_name() <<" WINS THE WAR" << std::endl;
	}
	std::cout << std::setw(93) << std::right << "----------VS----------" << std::endl;
	if (bot.move_card() == real.move_card()) {
		std::cout << std::setw(80) << std::right << "!!!It is a DRAW" << std::endl;
	}
	else if (real.move_card() > bot.move_card()) {
		std::cout << std::setw(80) << std::right <<"!!!"<< real.get_name() << " WINS THE WAR!!!" << std::endl;
	}

	for (int y = 0; y < 3 - real_card; y++) {
		Space_for_Cards();
	}

	for (int y = (-1+real_card); y >-1 ; y--) {
		real.display_in_game(y);
		
	}

	real_c.display();
}

void Game::ofstream1(std::string file) {
	std::ofstream of_stream{file,std::ios::app};
	if (!of_stream) {
		std::cout << "Error" << std::endl;
	}
	else {
		Card temp;
		while (real.get_i() > 0) {
			temp = real.move_card();
			real.remove();
			of_stream << 1 << " " << temp;
		}

		while (bot.get_i() > 0) {
			temp = bot.move_card();
			bot.remove();
			of_stream << 2 << " " << temp;
		}
	}
	of_stream.close();
}
void Game::ifstream1(std::string file) {
	std::ifstream if_stream{ file };
	std::string line;
	if (!if_stream) {
		std::cout << "Error" << std::endl;
	}
	else {
		for (int i = 0; i < 5; i++) {
			getline(if_stream, line);
		}
		Card temp;
		int num;
		if_stream >> num;
		while (num == 1) {
			if_stream >> temp >> num;
			real.add_cards(temp);
		}

		while (if_stream) {
			if_stream >> temp >> num;
			bot.add_cards(temp);
		}

	}
	if_stream.close();

}

void Game::Exit_menu(bool game_finish) {

	
	int ans = want_to_continue();


	if (ans == 1) {
		std::ofstream out(real.get_name() + ".txt",std::ios::app);
		out << 1 << std::endl;
		out.close();
		ofstream1(real.get_name() + ".txt");
	}
	else {
		std::ofstream out(real.get_name() + ".txt", std::ios::app);
		out << 0 << std::endl;
		out.close();
	}

}