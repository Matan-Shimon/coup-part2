#include "Player.hpp"
#include "Captain.hpp"
namespace coup {
    class Ambassador:public Player{
    public:
        Ambassador(Game& game, string name);
        void transfer(Player& took, Player& give);
        void block(Player& player);
    };
}