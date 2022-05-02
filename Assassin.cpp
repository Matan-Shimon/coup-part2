//
// Created by matan on 25/04/2022.
//
#include "Assassin.hpp"
using namespace coup;

Assassin::Assassin(Game& game, string name) : Player(game, move(name), "Assassin"){
    this->setCoupCost(3);
}
void Assassin::coup(Player& player){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (this->game->turn() != this->name){
        throw invalid_argument("It's not "+this->name+" turn!");
    }
    if (this->game != player.getGame()){
        throw invalid_argument(player.getName()+" is not in "+this->getName()+" game");
    }
    if (player.getName() == this->game->turn()) {
        throw invalid_argument("cannot block a player while it is his turn");
    }
    if (this->coins() < 3) {
        throw invalid_argument("Assassin cannot coup with less than 3 coins");
    }
    else {
        this->couped_player = &player;
        this->game->coupPlayer(&player);
        if (this->coins() > 6) {
            this->coup_cost = -7;
            this->change_money_amount(coup_cost);
            this->last_operation = "coup";
        }
        else {
            this->coup_cost = -3;
            this->change_money_amount(coup_cost);
            this->last_operation = "assassin_special_coup";
        }
        this->game->nextTurn();
    }
}
Player* Assassin::getCoupedPlayer(){
    return this->couped_player;
}