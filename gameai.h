//check.h

#ifndef GAMEAI
#define GAMEAI

using namespace std;

class Gameai{
public:
  string decision( int aicards[]);

  double check(int aicards[]);

  bool halfIsFlush(int aicards[]);

  bool halfIsThreeOfAKind(int aicards[]);

  int countPair(int aicards[]);

  int getNoPair(int aicards[]);

  bool halfIsTwoPair(int aicards[]);

  bool halfIsOnePair(int aicrds[]);

  void aibet(int &aimoney, int aicards[]);
};

#endif
