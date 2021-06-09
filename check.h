//check.h

#ifndef CHECK
#define CHECK

using namespace std;

class Check{
public:
  bool IsFourOfAKind(int cards[]);

  bool IsFullHouse(int cards[]);

  bool IsFlush(int cards[]);

  bool IsThreeOfAKind(int cards[]);

  int countPair(int cards[]);

  int getNoPair(int cards[]);

  bool IsTwoPair(int cards[]);

  bool IsOnePair(int cards[]);

  void winner(int aicards[],int cards[], int &money, int &aimoney, int &bet);
};


#endif
