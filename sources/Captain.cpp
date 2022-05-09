//
// Created by matan on 25/04/2022.
//
#include "Captain.hpp"
using namespace coup;

Captain::Captain(Game& game, string name) : Player(game, move(name), "Captain"){
    this->stolen_player = nullptr;
}
void Captain::steal(Player& player){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (this->game->turn() != this->name){
        throw invalid_argument("It's not "+this->name+" turn!");
    }
    if (this->coins() > '\n'){
        throw invalid_argument(this->getName()+" has "+ to_string(this->coins())+" so he must do coup!");
    }
    this->stolen_player = &player;
    if (player.coins() < 2){
        int stolen_coins = player.coins();
        player.change_money_amount(-1 * stolen_coins);
        this->change_money_amount(stolen_coins);
    }
    else{
        player.change_money_amount(-2);
        this->change_money_amount(2);
    }
    this->last_operation = "steal";
    this->game->set_can_add(false);
    this->game->nextTurn();
}
void Captain::block(Player& player){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (player.getLastOperation() != "steal"){
        throw invalid_argument("Captain can only block steal action");
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
    Captain* captain = dynamic_cast<Captain*>(&player);
    captain->change_money_amount(-2);
    captain->getStolenPlayer().change_money_amount(2);
}
Player& Captain::getStolenPlayer() {
    return *this->stolen_player;
}