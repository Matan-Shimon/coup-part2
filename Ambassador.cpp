//
// Created by matan on 25/04/2022.
//
#include "Ambassador.hpp"
using namespace coup;

Ambassador::Ambassador(Game& game, string name) : Player(game, move(name), "Ambassador") {
}
void Ambassador::transfer(Player& took, Player& give) {
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (this->game->turn() != this->name){
        throw invalid_argument("It's not "+this->name+" turn!");
    }
    if (this->coins() > '\n'){
        throw invalid_argument(this->getName()+" has "+ to_string(this->coins())+" so he must do coup!");
    }
    if (took.coins() < 1) {
        throw invalid_argument(took.getName()+" has "+ to_string(took.coins())+" coins");
    }
    took.change_money_amount(-1);
    give.change_money_amount(1);
    this->last_operation = "transfer";
    this->game->nextTurn();
}
void Ambassador::block(Player& player){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (player.getLastOperation() != "steal"){
        throw invalid_argument("Ambassador can only block steal action");
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
    Captain* captain = (Captain*)&player;
    captain->change_money_amount(-2);
    captain->getStolenPlayer().change_money_amount(2);
}