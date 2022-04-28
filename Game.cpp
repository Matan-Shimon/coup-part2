//
// Created by matan on 25/04/2022.
//
#include "Game.hpp"
using namespace coup;

Game::Game(){
    this->player_position = 0;
    this->game_id = id;
    id++;
}
Game::~Game() {}
string Game::turn(){
    return this->game_players.front()->getName();
}
vector<string>Game::players(){
    return this->players_name;
}
int Game::get_player_position() const{
    return this->player_position;
}
void Game::addPlayer(Player* player){
    if (!player->in_game){
        this->player_position++;
        player->in_game = true;
        this->game_players.push(player);
        this->players_name.push_back(player->getName());
    }
    else{
        Player* front = this->game_players.front();
        while (this->game_players.front()->position != player->position+1){
            Player* p = this->game_players.front();
            this->game_players.pop();
            this->game_players.push(p);
        }
        this->game_players.push(player);
        while (this->game_players.front() != front){
            Player* p = this->game_players.front();
            this->game_players.pop();
            this->game_players.push(p);
        }
        this->players_name.insert(this->players_name.begin() + player->position, player->getName());
    }

}
void Game::coupPlayer(Player* player) {
    // Helper queue to store the elements
    // temporarily.
    queue<Player*> ref;
    int s = this->game_players.size();
    int cnt = 0;

    // Finding the value to be removed
    while (this->game_players.front() != player and !this->game_players.empty()) {
        ref.push(this->game_players.front());
        this->game_players.pop();
        cnt++;
    }
    // If element is not found
    if (this->game_players.empty()) {
        while (!ref.empty()) {

            // Pushing all the elements back into q
            this->game_players.push(ref.front());
            ref.pop();
        }
        throw invalid_argument("There's no player named "+player->getName());
    }

        // If element is found

    for (unsigned int i = 0; i < this->players_name.size(); ++i) {
        if (this->players_name.at(i) == player->getName()){
            this->players_name.erase(this->players_name.begin()+i);
        }
    }
    this->game_players.pop();
    while (!ref.empty()) {
        // Pushing all the elements back into q
        this->game_players.push(ref.front());
        ref.pop();
    }
    int k = s - cnt - 1;
    while ((k--)!=0) {
        // Pushing elements from front of q to its back
        Player* p = this->game_players.front();
        this->game_players.pop();
        this->game_players.push(p);
    }
}
void Game::nextTurn(){
    Player* player = this->game_players.front();
    this->game_players.pop();
    this->game_players.push(player);
    this->game_players.front()->blocked = false;
    this->game_players.front()->blocking = false;
}
int Game::getGameID() const{
    return this->game_id;
}
bool Game::operator!= (Game const & game) const{
    bool ans = false;
    if (this->game_id != game.game_id) {
        ans = true;
    }
    return ans;
}
bool Game::operator== (Game const & game) const{
    return !(*this != game);
}