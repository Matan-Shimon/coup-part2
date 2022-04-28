//
// Created by matan on 25/04/2022.
//
#include "Contessa.hpp"
using namespace coup;

Contessa::Contessa(Game& game, string name) : Player(game, move(name), "Contessa"){

}
void Contessa::block(Player& player){
    if (player.getLastOperation() != "coup"){
        throw invalid_argument("Contessa can only block coup action");
    }
    if (player.blocked) {
        throw invalid_argument(player.getName()+" is already blocked!");
    }
    if (this->blocking) {
        throw invalid_argument(this->getName()+" is already blocking this round");
    }
    this->blocking = true;
    player.blocked = true;
    this->game->addPlayer(player.getCoupedPlayer());
}
