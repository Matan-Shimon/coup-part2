//
// Created by matan on 25/04/2022.
//
#include "Contessa.hpp"
#include "Assassin.hpp"
using namespace coup;

Contessa::Contessa(Game& game, string name) : Player(game, move(name), "Contessa"){

}
void Contessa::block(Player& player){
    if (!this->game->get_game_started()) {
        throw invalid_argument("The game must have at least 2 players");
    }
    if (player.getLastOperation() != "assassin_special_coup"){
        throw invalid_argument("Contessa can only assassin special coup action");
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
    Assassin* assassin = (Assassin*)&player;
    this->game->addPlayer(assassin->getCoupedPlayer());
}
