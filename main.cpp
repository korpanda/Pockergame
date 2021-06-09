#include <iostream>
#include "gameai.h"
#include "check.h"
#include "game.h"

using namespace std;

int main(){
  Check check;
  Game game;
  Gameai gameai;
  int aicards[5] = {};
  int cards[5] = {};
  int money = 100;
  int aimoney = 100;
  int bet = 0;

  game.startgame(aicards, cards, money, aimoney, bet);
  
}

