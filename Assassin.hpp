#include "Player.hpp"
namespace coup {
    class Assassin:public Player{
    private:
        Player* couped_player;
    public:
        Assassin(Game& game, string name);
        void coup(Player& player);
        Player* getCoupedPlayer();
    };
}