#include <iostream>
#include <string>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>
#include "gameai.h"

using namespace std;

int Gameai::countPair(int aicards[]){
  int noOfpair = 0;
  bool check[5];
  
  for (int i = 0; i < 3; i++) {
    check[i] = 0;
  }

  for (int i = 0; i < 5; i++) {
    if (check[i] == 1) {
      continue;
    }
    int count = 1;
    for (int j = i + 1; j < 3; j++) {
      if (aicards[i] == aicards[j]) {
        check[j] = 1;
        count++;
      }
    }
    if (count >= 2){
    noOfpair++;
    }
  }
  
  return noOfpair;

}

int Gameai::getNoPair(int aicards[]){
  int nums[3];
 
  for (int i = 0; i < 3; i++)
  {
    nums[i] = aicards[i] % 13;
  }
  int noOfpair = countPair(nums);
  return noOfpair;
} 

bool Gameai::halfIsOnePair(int aicards[]){
  int q = getNoPair(aicards);
  if (q == 1){
    return true;
  } else{
    return false;
  }
}// return if the hand is one pair

bool Gameai::halfIsTwoPair(int aicards[]){
  int p = getNoPair(aicards);
  if ( p==2){
    return true;
  } else{
    return false;
  }
}

bool Gameai::halfIsThreeOfAKind(int aicards[]){
  for (int i = 0; i <13; i++){
    int count = 0; // counting the number of case when the element in the array equals to specific number, renewed if not equals to 3. 
    for ( int j = 0; j < 5 ; j++){
      if (aicards[j]%13 == i){
        count +=1;
      }
    }
    if ( count == 3){
      return true;
    }
  }
  return false;
}

bool Gameai::halfIsFlush(int aicards[]){
  int countspade=0,countheart=0,countclub=0, countdiamond=0; // counting the number of suites, and any of them equals to 5 means Flush.
  for (int i = 0; i < 3; i ++){
    if (aicards[i] >= 0 && aicards[i]<=12){
      countspade+=1;
    } else if (aicards[i] >=13 && aicards[i] <= 25){
      countheart+=1;
    } else if (aicards[i] >=26 && aicards[i] <= 38){
      countclub+=1;
    } else if (aicards[i] >=39 && aicards[i] <= 51){
      countdiamond+=1;
    }
  }
  if (countspade ==3 ||countheart ==3||countclub ==3||countdiamond ==3){
    return true;
  } else{
    return false;
  }
}



double Gameai::check(int aicards[]){
  if (halfIsFlush(aicards)){
    return 0.8;
  }else if(halfIsOnePair(aicards)){
    return (0.6);
  }else if(halfIsTwoPair(aicards)){
    return (0.7);
  } else if(halfIsThreeOfAKind(aicards)){
    return (1);
  } else{
    return 0;
  }
}

string Gameai::decision(int aicards[]){
  double chance = check(aicards);
  srand(time(NULL));
	double prob = ((double)rand() / RAND_MAX);
  if (prob < chance){
    return "GO";
  } else{
    return "NO";
  }
}

void Gameai::aibet(int &aimoney,int aicards[]){
  string aistatus = decision(aicards);
  int betamount = check(aicards) * 100;
  if ( aistatus == "GO"){
    aimoney = aimoney - betamount;
  } 
}
