//
// Created by matan on 25/04/2022.
//
#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
using namespace std;
using namespace coup;

TEST_CASE("Players") {
    Game game_1{};

    SUBCASE("Duke") {
        Duke duke{game_1, "Moshe"};
        CHECK(duke.role() == "Duke");
        int money = duke.coins();
        CHECK(money == 0);
        duke.income();
        bool check = duke.coins() == money+1;
        CHECK(check == true);
        money = duke.coins();
        duke.tax();
        check = duke.coins() == money+3;
        CHECK(check == true);
    }

    SUBCASE("Assassin") {
        Assassin assassin{game_1, "Moshe"};
        CHECK(assassin.role() == "Duke");
        int money = assassin.coins();
        CHECK(money == 0);
        assassin.income();
        bool check = assassin.coins() == money+1;
        CHECK(check == true);
    }

    SUBCASE("Ambassador") {
        Ambassador ambassador{game_1, "Moshe"};
        CHECK(ambassador.role() == "Duke");
        int money = ambassador.coins();
        CHECK(money == 0);
        ambassador.income();
        bool check = ambassador.coins() == money+1;
        CHECK(check == true);
        Game game_2{};
        Assassin assassin1{game_1, "Asi"};
        Ambassador ambassador1{game_1, "Amb"};
        Ambassador ambassador2{game_1, "Avi"};
        int ambassador2_money = ambassador2.coins();
        assassin1.income();
        ambassador1.transfer(assassin1, ambassador2);
        check = ambassador2_money+1 == ambassador2.coins();
        CHECK(check == true);
    }

    SUBCASE("Captain") {
        Captain captain{game_1, "Moshe"};
        CHECK(captain.role() == "Duke");
        int money = captain.coins();
        CHECK(money == 0);
        captain.income();
        bool check = captain.coins() == money+1;
        CHECK(check == true);
        Game game_2{};
        Assassin assassin{game_1, "Asi1"};
        Captain captain1{game_1, "Cap1"};
        Captain captain2{game_1, "Cap2"};
        assassin.income();
        captain1.income();
        captain2.income();
        assassin.income();
        captain1.steal(assassin);
        captain2.block(captain1);
        check = captain1.coins() == 1;
        CHECK(check == true);
    }

    SUBCASE("Contessa") {
        Contessa contessa{game_1, "Moshe"};
        CHECK(contessa.role() == "Duke");
        int money = contessa.coins();
        CHECK(money == 0);
        contessa.income();
        bool check = contessa.coins() == money+1;
        CHECK(check == true);
        Game game_2{};
        Assassin assassin{game_1, "Asi1"};
        Captain captain1{game_1, "Cap1"};
        Contessa contessa1{game_1, "Cap2"};
        assassin.income();
        captain1.income();
        contessa1.income();
        assassin.income();
        captain1.steal(assassin);
        contessa1.block(captain1);
        check = captain1.coins() == 1;
        CHECK(check == true);
        CHECK_THROWS(captain1.income());
    }
}
