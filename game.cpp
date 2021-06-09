#include <iostream>
#include <string>
#include <cstdlib>      // for calling srand(), rand
#include <ctime>
#include<cstring>   
#include <fstream>   
#include <stdio.h>
#include <cstdio>
#include "game.h"
#include "gameai.h"
#include "check.h"

using namespace std;

void Game::delprevious(string &pname)
{
  char filename[pname.size()];
  string strfilename = pname +".txt"; 
  strcpy(filename, strfilename.c_str());
  int status = remove(filename);
}


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
void Game::playermoney(int &money, int &bet){
  int playerbet;
  cout <<  "Key in the ammount of the money you want to bet!" << endl;
  cin >> playerbet;
  bet += playerbet;
  money = money - playerbet;
  cout << "Player have bet: " << bet << endl;
}



void Game::gameloop(int aicards[], int cards[], int &money, int &aimoney, int &bet, string &pname){
  Gameai ai;
  halfDealHand(cards);
  ai.halfDealHand(aicards);
  halfPrintHand(cards);
  Check check;
  string ais = ai.decision(aicards);
  string playerdecision = playerbet(money, bet);
  if ( ais == "GO" || playerdecision == "GO"){
    int betamount = ai.checkai(aicards) * 100;
    aimoney = aimoney - betamount;
    bet += betamount;
    secondhalfDealHand(cards);
    ai.secondhalfDealHand(aicards);
    cout << "Player Deck" << endl;
    secondhalfPrinthand(cards);
    cout << "AI Deck" << endl;
    secondhalfPrinthand(aicards);
    cout << "AI money left: " << aimoney <<endl;
    cout << "PLayer money left: " << money <<endl;
  
    check.winner(aicards, cards, money, aimoney, bet);

    cout << "AI money left: " << aimoney <<endl;
    cout << "PLayer money left: " << money <<endl;

    
  } else if( ais == "GO" || playerdecision == "NO"){
    cout << "The computer WON !" << endl;
    aimoney += bet;
    bet =0;
  } else if (ais == "NO" || playerdecision == "GO"){
    cout << "YOU WON !" << endl;
    money += bet;
    bet =0;
  }
}

void Game::startgame(int aicards[], int cards[], int &money, int &aimoney, int &bet) {
	string status;
	cout << "### Enter \"y\" to start or \"n\" to exit ###" << endl;
	cin >> status;
  string pname;
  
	if (status == "y") {
    string status1;
    cout << endl;
    cout << "Do you want to start from saved point (y/n)? "; // to ask whether to continue the game as saved before. 
    cin >> status1;
    cout << endl;
    if (status1 == "y"){ // loadgame, when there is no file as such name, create new game. 
      bool check = loadgame(aicards, cards, money, aimoney, bet, pname);
      if(check == true){ // if there is a file name as input, continue loading and start game. 
        string status2;
        while (true){
          if (aimoney == 0 && money >0){
            cout << "AI lost all the money!" << endl;
            cout << " YOU WON" << endl;
            delprevious(pname);
          } else if (aimoney >0 && money == 0){
            cout << "You lost all your money!" << endl;
            cout << "AI WON" << endl;
            delprevious(pname);
          }else {
            gameloop(aicards, cards, money, aimoney, bet,pname);
            cout << "Do you want to play again? (y/n)" << endl;
            cin >> status2;
            if( status2 == "n"){
              delprevious(pname);
              savegame(aicards, cards, money, aimoney, bet, pname);
              cout << "Game saved" <<endl;
              break;
            }
          }
        }
      } else{ // if there is no file in name as input, start new game. 
        cout << "Therefore, creating new game" << endl;
        cout << "Key in your one word name!" << endl;
        cin >> pname; 
        string status2;
        while (true){
          if (aimoney == 0 && money >0){
            cout << "AI lost all the money!" << endl;
            cout << " YOU WON" << endl;
            delprevious(pname);
          } else if (aimoney >0 && money == 0){
            cout << "You lost all your money!" << endl;
            cout << "AI WON" << endl;
            delprevious(pname);
          }else {
            gameloop(aicards, cards, money, aimoney, bet,pname);
            cout << "Do you want to play again? (y/n)" << endl;
            cin >> status2;
            if( status2 == "n"){
              delprevious(pname);
              savegame(aicards, cards, money, aimoney, bet, pname);
              cout << "Game saved" <<endl;
              break;
            }
          }
        }
      }
    } else if(status1 =="n"){ //if player want to play new game
      cout << "Key in your one word name" << endl;
      cin >> pname; 
      string status2;
        while (true){
          if (aimoney == 0 && money >0){
            cout << "AI lost all the money!" << endl;
            cout << " YOU WON" << endl;
            delprevious(pname);
          } else if (aimoney >0 && money == 0){
            cout << "You lost all your money!" << endl;
            cout << "AI WON" << endl;
            delprevious(pname);
          }else {
            gameloop(aicards, cards, money, aimoney, bet,pname);
            cout << "Do you want to play again? (y/n)" << endl;
            cin >> status2;
            if( status2 == "n"){
              delprevious(pname);
              savegame(aicards, cards, money, aimoney, bet, pname);
              cout << "Game saved" <<endl;
              break;
            }
          }
        }
    }
	} else if (status == "n") { //exit game.
		cout << "Game ended" << endl;
	}
}

string Game::playerbet(int &money, int &bet){
  string answer; 
  cout << "Would you like to \'GO\'? (y/n)" << endl;
  cin >> answer;
  if (answer == "Y" || answer == "y"){
    playermoney(money, bet);
    return "GO";
  } else if ( answer == "N" || answer=="n") {
    return "NO";
  }
  return "NO";
}

void Game::savegame(int aicards[], int cards[], int &money, int &aimoney, int &bet, string &pname){
  ofstream fout;
  string txtname = pname + ".txt"; // make into a [filename].txt 
  fout.open(txtname);
  string lines;

  int playerarrSize = sizeof(*cards)/sizeof(cards[0]);
  fout << "PLAYER HANDS" << endl;
  for ( int i= 0; i < playerarrSize; i++){
    fout<< cards[i] << endl;
  }
  int aiarrsize = sizeof(*aicards)/sizeof(aicards[0]);
  fout << "AI HANDS" << endl; //indication for next item.
  for ( int j =0 ; j < aiarrsize;j++){
    fout << aicards[j] << endl;
  }
  fout << "AIMONEY" << endl; // indication for next item
  fout << aimoney <<endl;
  fout << "PLAYERMONEY" << endl; // indication for next item
  fout << money << endl;
  fout << "BET" << endl;
  fout << bet << endl;
  fout.close();
  
}


bool Game::loadgame(int aicards[], int cards[], int &money, int &aimoney, int &bet, string &pname){
  ifstream fin;
  string lines;
  string previousfilename;
  previousfilename = pname + ".txt";
  fin.open(previousfilename);
  if(fin.fail()){
    cout<<"There is no file saved in that name" <<endl;
    cout <<endl;
    return false;
  }else {
    while (getline(fin, lines)){
      int i = 0;
      if (lines == "PLAYERHANDS"){
        while (getline(fin, lines)){
          if ( lines == "AIHANDS"){
            break;
          } else {
            cards[i] = stoi(lines);
            i++;
          }
        }        
      } 
      if (lines == "AIHANDS"){
        int j =0;
        while (getline(fin, lines)){
          if ( lines ==  "AIMONEY"){
            break;
          } else {
            aicards[j] = stoi(lines);
            j++;
          }
        }
      } 
      if (lines == "AIMONEY"){
        while (getline(fin,lines)){
          if ( lines == "PLAYERMONEY"){
            break;
          } else {
            aimoney = stoi(lines);
          }
        }
      } 
      if(lines == "PLAYERMONEY"){
        while (getline(fin,lines)){
          if ( lines == "BET"){
            break;
          } else {
            money = stoi(lines);
          }
        }

      }
      if(lines == "PLAYERMONEY"){
        getline(fin,lines);
        bet = stoi(lines);
      }
    }
  }
  fin.close();
  return true;
}

