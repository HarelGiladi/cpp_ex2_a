#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"


using namespace ariel;

TEST_CASE("starting games, and cheking first stats"){
    Player p1("h");
    Player p2("g");
    Game game1(p1,p2);

    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);

    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);




    Player p3("harel");
    Player p4("giladi");
    Game game2(p3,p4);

    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);
    
    CHECK(p3.cardesTaken()==0);
    CHECK(p4.cardesTaken()==0);
  
}

TEST_CASE("only one turn played in the game")
{
    Player player1("h");
    Player player2("g");
    Game game(player1,player2);
    
    game.playTurn();

    CHECK(player1.stacksize() == 25);
    CHECK(player2.stacksize() == 25);
    
}

TEST_CASE("non valid name")
{
    Player player1("h");
    Player player2("");

    CHECK_THROWS(Game(player1, player1));
    CHECK_THROWS(Game(player1, player2));


}
TEST_CASE("only one game for each player"){
    Player p1("h");
    Player p2("g");
    Player p3("hg");

    Game game1(p1, p2);
    Game game2(p2, p3);

    game2.playTurn();
    CHECK_THROWS(game1.playAll());
    CHECK_THROWS(game1.printLastTurn());
    CHECK_THROWS(game1.printWiner());
}

TEST_CASE("game moves"){
    Player p1("harel");
    Player p2("giladi");
    Game game1(p1,p2);
      
    CHECK_THROWS(game1.printLog());      
    CHECK_THROWS(game1.printLastTurn());
    CHECK_THROWS(game1.printWiner());
    CHECK_THROWS(game1.printLog());

    game1.playTurn();
    CHECK(p1.stacksize()!=p2.stacksize()); 
    CHECK_THROWS(game1.printWiner());

    game1.playAll();
    CHECK(p1.stacksize()!=p2.stacksize());

    CHECK_THROWS(game1.printWiner());
    CHECK_THROWS(game1.printLastTurn());
    CHECK_THROWS(game1.printLog());

}
  
TEST_CASE("plays to the end and byeond")
{
    Player player1("h");
    Player player2("g");

    Game game(player1,player2);
    
    game.playAll();

    CHECK_THROWS(game.playAll());
    CHECK_THROWS(game.playTurn());
}


TEST_CASE("odd likely to happen Situation"){
    Player p3("harel");
    Player p4("giladi");
    Player p5("eilon");
    Game game1(p3,p4);
    Game game2(p3, p5);
    CHECK(p3.stacksize()==26);
    game1.playTurn();
    CHECK(p3.stacksize()!=p4.stacksize());
    CHECK_THROWS(game2.playTurn());
    CHECK_THROWS(game2.playAll());
    
    
}
