#include <iostream>
#include <string>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include "check.h"
using namespace std;

int Check::countPair(int cards[]){
  int noOfpair = 0;
  bool check[5];
  
  for (int i = 0; i < 5; i++) {
    check[i] = 0;
  }

  for (int i = 0; i < 5; i++) {
    if (check[i] == 1) {
      continue;
    }
    int count = 1;
    for (int j = i + 1; j < 5; j++) {
      if (cards[i] == cards[j]) {
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

int Check::getNoPair(int cards[]){
  int nums[5];
 

  for (int i = 0; i < 5; i++)
  {
    nums[i] = cards[i] % 13;
  }
  int noOfpair = countPair(nums);
  return noOfpair;
} 


bool Check::IsOnePair(int cards[]){
  int q = getNoPair(cards);
  if (q == 1){
    return true;
  } else{
    return false;
  }
}// return if the hand is one pair

bool Check::IsTwoPair(int cards[]){
  int p = getNoPair(cards);
  if ( p==2){
    return true;
  } else{
    return false;
  }
}

bool Check::IsThreeOfAKind(int cards[]){
  for (int i = 0; i <13; i++){
    int count = 0; // counting the number of case when the element in the array equals to specific number, renewed if not equals to 3. 
    for ( int j = 0; j < 5 ; j++){
      if (cards[j]%13 == i){
        count +=1;
      }
    }
    if ( count == 3){
      return true;
    }
  }
  return false;
}

bool Check::IsFlush(int cards[]){
  int countspade=0,countheart=0,countclub=0, countdiamond=0; // counting the number of suites, and any of them equals to 5 means Flush.
  for (int i = 0; i < 5; i ++){
    if (cards[i] >= 0 && cards[i]<=12){
      countspade+=1;
    } else if (cards[i] >=13 && cards[i] <= 25){
      countheart+=1;
    } else if (cards[i] >=26 && cards[i] <= 38){
      countclub+=1;
    } else if (cards[i] >=39 && cards[i] <= 51){
      countdiamond+=1;
    }
  }
  if (countspade ==5 ||countheart ==5||countclub ==5||countdiamond ==5){
    return true;
  } else{
    return false;
  }
}

bool Check::IsFullHouse(int cards[]){
  int count = 0;
  int compare=0,nums_cards=0;
  for ( int i = 0; i < 5; i++ ){
    for ( int j = 0; j < i; j++){
      if (cards[i]%13 == cards[j]%13 && cards[i] != compare){ 
        nums_cards +=1;
        compare = cards[i];
      }
      if (cards[i]%13 == cards[j]%13){
        count +=1;
      }
    }
  }
  if (count == 4 && nums_cards ==2){
    return true;
  } else{
    return false;
  }
}

bool Check::IsFourOfAKind(int cards[]){
  for (int i = 0; i <13; i++){
    int count = 0;
    for ( int j = 0; j < 5 ; j++){
      if (cards[j]%13 == i){
        count +=1;
      }
    }
    if (count ==4){
      return true;
    }else{
      continue;
    }
  }
  return false;
}
