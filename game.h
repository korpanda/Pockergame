//Game.h


#ifndef GAME
#define GAME

using namespace std;

class Game{
public:
  Game();
  
  void halfDealHand(int cards[]);

  void secondhalfDealHand( int cards[]);

  void halfPrintHand(int cards[]);

  void secondhalfPrinthand( int cards[]);

  void playerbet(int &money);

  void playermoney(int &moeny);

};

#endif
