#pragma once
#include "Player.hpp"
namespace coup {
    class Captain:public Player{
    private:
        Player* stolen_player;
    public:
        Captain(Game& game, string name);
        void steal(Player& player);
        void block(Player& player);
        Player& getStolenPlayer();
    };
}