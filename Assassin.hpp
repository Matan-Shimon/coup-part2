#include "Player.hpp"
namespace coup {
    class Assassin:public Player{
    public:
        Assassin(Game& game, string name);
        void coup(Player& player);
    };
}