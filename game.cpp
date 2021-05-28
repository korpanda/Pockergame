#include <iostream>
#include <string>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()
#include "game.h"

using namespace std;

Game::Game(){
  #define SPADE   "\xE2\x99\xA0"
  #define CLUB    "\xE2\x99\xA3"
  #define HEART   "\xE2\x99\xA5"
  #define DIAMOND "\xE2\x99\xA6"  
}

void Game::halfDealHand(int cards[]){
  srand(time(NULL));
  for (int i =0; i < 3; i++){
    cards[i]= rand()%52;
  }
}

void Game::secondhalfDealHand(int cards[]){
  srand(time(NULL));
  for (int i =3; i < 5; i++){
    cards[i]= rand()%52;
  }
}

void Game::halfPrintHand(int cards[]){
  string front[13] = {"A","2","3","4","5","6", "7", "8", "9", "10","J","Q","K"}; //making an array of the front part of the cards, so can be called simply.
  string outcome[5]; // array of a numbers to suites and cards.
  for ( int i = 0; i<3; i++){ 
    if (cards[i] >= 0 && cards[i] <=12){
      outcome[i] = front[cards[i]%13] + SPADE;
    } else if( cards[i] >=13 && cards[i] <= 25){
      outcome[i] = front[cards[i]%13] + HEART;
    } else if (cards[i] >=26 && cards[i] <= 38){
      outcome[i] = front[cards[i]%13] + CLUB;
    } else if( cards[i] >=39 && cards[i] <= 51){
      outcome[i] = front[cards[i]%13] + DIAMOND; 
    }
  }
  for ( int j = 0; j < 3; j++){
    cout << outcome[j] << " ";
  }
  cout << endl;
}

void Game::secondhalfPrinthand(int cards[]){
  string front[13] = {"A","2","3","4","5","6", "7", "8", "9", "10","J","Q","K"}; //making an array of the front part of the cards, so can be called simply.
  string outcome[5]; // array of a numbers to suites and cards.
  for ( int i = 0; i<5; i++){ 
    if (cards[i] >= 0 && cards[i] <=12){
      outcome[i] = front[cards[i]%13] + SPADE;
    } else if( cards[i] >=13 && cards[i] <= 25){
      outcome[i] = front[cards[i]%13] + HEART;
    } else if (cards[i] >=26 && cards[i] <= 38){
      outcome[i] = front[cards[i]%13] + CLUB;
    } else if( cards[i] >=39 && cards[i] <= 51){
      outcome[i] = front[cards[i]%13] + DIAMOND; 
    }
  }
  for ( int j = 0; j < 5; j++){
    cout << outcome[j] << " ";
  }
  cout << endl;
}

