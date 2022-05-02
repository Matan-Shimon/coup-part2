//
// Created by matan on 25/04/2022.
//
#include "Duke.hpp"
using namespace coup;

Duke::Duke(Game& game, string name): Player(game, move(name), "Duke") {
}
void Duke::tax(){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (this->game->turn() != this->name){
        throw invalid_argument("It's not "+this->name+" turn!");
    }
    if (this->coins() > '\n'){
        throw invalid_argument(this->getName()+" has "+ to_string(this->coins())+" so he must do coup!");
    }
    this->change_money_amount(3);
    this->last_operation = "tax";
    this->game->nextTurn();
}
void Duke::block(Player& player){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (player.getLastOperation() != "foreign_aid"){
        throw invalid_argument("Duke can only block foreign aid action");
    }
    if (player.blocked) {
        throw invalid_argument(player.getName()+" is already blocked!");
    }
    if (this->blocking) {
        throw invalid_argument(this->getName()+" is already blocking this round");
    }
    if (player.getName() == this->game->turn()) {
        throw invalid_argument("cannot block a player while it is his turn");
    }
    this->blocking = true;
    player.blocked = true;
    player.change_money_amount(-2);
}