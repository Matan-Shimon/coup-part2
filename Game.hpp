#pragma once
#include "string"
#include "queue"
#include "vector"
#include "Player.hpp"
#include "iostream"
using namespace std;
namespace coup {
    class Player;
    class Game{
    private:
        inline static int id = 0;
        int game_id;
        inline static int player_position = 0;
        queue<Player*> game_players;
        vector<string> players_name;
    public:
        Game();
        ~Game();
        string turn();
        vector<string>players();
        void addPlayer(Player* player);
        void coupPlayer(Player* player);
        void nextTurn();
        int getGameID() const;
        bool operator!= (Game const & game) const;
        bool operator== (Game const & game) const;
    };
}