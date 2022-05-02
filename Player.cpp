//
// Created by matan on 25/04/2022.
//
#include "Player.hpp"
using namespace coup;

Player::Player() {
    this->money = 0;
    this->name = "";
    this->last_operation = "";
    this->player_role = "";
    this->game = nullptr;
    this->position = 0;
}
Player::Player(Game& game, string name){
    this->money = 0;
    this->name = move(name);
    this->last_operation = "";
    this->player_role = "";
    this->game = &game;
    this->game->addPlayer(this);
    this->position = this->game->get_player_position();
}
Player::Player(Game& game, string name, string player_role){
    this->money = 0;
    this->name = move(name);
    this->last_operation = "";
    this->player_role = move(player_role);
    this->game = &game;
    this->game->addPlayer(this);
    this->position = this->game->get_player_position();
}
Player::~Player(){}
void Player::income() {
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (this->game->turn() != this->name){
        throw invalid_argument("It's not "+this->name+" turn!");
    }
    if (this->coins() > '\n'){
        throw invalid_argument(this->getName()+" has "+ to_string(this->coins())+" so he must do coup!");
    }
    this->change_money_amount(1);
    this->last_operation = "income";
    this->game->nextTurn();
}
void Player::foreign_aid(){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (this->game->turn() != this->name){
        throw invalid_argument("It's not "+this->name+" turn!");
    }
    if (this->coins() > '\n'){
        throw invalid_argument(this->getName()+" has "+ to_string(this->coins())+" so he must do coup!");
    }
    this->change_money_amount(2);
    this->last_operation = "foreign_aid";
    this->game->nextTurn();
}
void Player::coup(Player& player){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (this->game->turn() != this->name){
        throw invalid_argument("It's not "+this->name+" turn!");
    }
    if (this->game != player.game){
        throw invalid_argument(player.getName()+" is not in "+this->getName()+" game");
    }
    if (this->coins() < 7){
        throw invalid_argument(this->getName()+" has less than 7 coins");
    }
    this->game->coupPlayer(&player);
    this->change_money_amount(coup_cost);
    this->last_operation = "coup";
    this->game->nextTurn();
}
string Player::role(){
    return player_role;
}
int Player::coins() const{
    return this->money;
}
string Player::getName() {
    return this->name;
}
string Player::getLastOperation(){
    return this->last_operation;
}
Game* Player::getGame(){
    return this->game;
}
void Player::setCoupCost(int cost){
    this->coup_cost = cost;
}
void Player::change_money_amount(int change){
    this->money += change;
}
bool Player::operator!=(const Player &player) {
    bool ans = false;
    if (this->name != player.name || this->last_operation != player.last_operation
    || this->money != player.money || this->player_role != player.player_role
    || this->game != player.game){
        ans = true;
    }
    return ans;
}
bool Player::operator==(const Player &player) {
    return !(*this != player);
}