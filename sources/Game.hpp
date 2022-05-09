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
        bool game_started = false;
        bool can_add = true;
        int game_id;
        int player_position;
        int max_players = 6;
        queue<Player*> game_players;
        vector<string> players_name;
    public:
        Game();
        ~Game();
        string turn();
        string winner();
        vector<string>players();
        int get_player_position() const;
        bool get_game_started() const;
        int get_num_of_players();
        void addPlayer(Player* player);
        void coupPlayer(Player* player);
        void set_can_add(bool can_add);
        void nextTurn();
        int getGameID() const;
        bool operator!= (Game const & game) const;
        bool operator== (Game const & game) const;
    };
}