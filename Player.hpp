#pragma once
#include "string"
#include "Game.hpp"
#include "iostream"
using namespace std;
namespace coup{
    class Game;
    class Player{
    protected:
        Game* game;
        int money;
        string name;
        string player_role;
        string last_operation;
        Player* couped_player;
        int coup_cost = 7;
    public:
        int position;
        bool blocked = false;
        bool blocking = false;
        bool in_game = false;
        Player();
        Player(Game& game, string name);
        Player(Game& game, string name, string player_role);
        ~Player();
        void income();
        void foreign_aid();
        void coup(Player& player);
        virtual string role();
        int coins() const;
        string getName();
        string getLastOperation();
        Game* getGame();
        Player* getCoupedPlayer();
        void setCoupCost(int cost);
        void change_money_amount(int change);
        bool operator!= (Player const & player);
        bool operator== (Player const & player);
    };
}