//
// Created by matan on 25/04/2022.
//
#include "Assassin.hpp"
using namespace coup;

Assassin::Assassin(Game& game, string name) : Player(game, move(name), "Assassin"){
    this->setCoupCost(3);
}