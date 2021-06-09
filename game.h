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

  string playerbet(int &money, int &bet);

  void playermoney(int &moeny, int &bet);

  void savegame(int aicards[], int cards[], int &moneny, int &aimoney, int &bet, string &pname);

  void delprevious(string &pname);

  bool loadgame( int aicards[], int cards[], int &money, int &aimoney, int &bet, string &pname);

  void startgame(int aicards[], int cards[], int &money, int &aimoney, int &bet);

  void gameloop(int aicards[], int cards[], int &money, int &aimoney, int &bet, string &panme);

};

#endif
