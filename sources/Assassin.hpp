#include "Player.hpp"
namespace coup {
    class Assassin:public Player{
    private:
        Player* couped_player;
        int high_cost = 7;
        int low_cost = 3;
    public:
        Assassin(Game& game, string name);
        void coup(Player& player);
        Player* getCoupedPlayer();
    };
}