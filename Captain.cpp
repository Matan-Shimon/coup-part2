//
// Created by matan on 25/04/2022.
//
#include "Captain.hpp"
using namespace coup;

Captain::Captain(Game& game, string name) : Player(game, move(name), "Captain"){
    this->stolen_player = nullptr;
}
void Captain::steal(Player& player){
    if (this->game->turn() != this->name){
        throw invalid_argument("It's not "+this->name+" turn!");
    }
    if (this->coins() > '\n'){
        throw invalid_argument(this->getName()+" has "+ to_string(this->coins())+" so he must do coup!");
    }
    this->stolen_player = &player;
    if (player.coins() < 2){
        player.change_money_amount(-1 * player.coins());
        this->change_money_amount(player.coins());
    }
    else{
        player.change_money_amount(-2);
        this->change_money_amount(2);
    }
    this->last_operation = "steal";
    this->game->nextTurn();
}
void Captain::block(Player& player){
    if (player.getLastOperation() != "steal"){
        throw invalid_argument("Captain can only block steal action");
    }
    if (player.blocked) {
        throw invalid_argument(player.getName()+" is already blocked!");
    }
    if (this->blocking) {
        throw invalid_argument(this->getName()+" is already blocking this round");
    }
    this->blocking = true;
    player.blocked = true;
    Captain* captain = (Captain*)&player;
    captain->change_money_amount(-2);
    captain->getStolenPlayer().change_money_amount(2);
}
Player Captain::getStolenPlayer() {
    return *(this->stolen_player);
}