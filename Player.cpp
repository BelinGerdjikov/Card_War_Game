#include "Player.h"
Player::Player(std::string name1, int games1, int wins1) 
	:name{ name1 }, games{ games1 }, wins{ wins1 }, w_s{ 0 } {

}
void Player::add_cards(const Card& obj) {
	p_cards.add_card(obj);
}