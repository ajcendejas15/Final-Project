//
//  Player.h
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#ifndef __Final_Project__Player__
#define __Final_Project__Player__

#include <iostream>
#include <vector>
#include "Shoe.h"
using namespace std;

class Player
{
private:
    int chips, bet;
    string name;
    bool playing;
 public:
    bool bust;
    bool blackjack;
    vector<Card> plyrHnd;
    int getValue();
    Player();
    Player(string n, int c);
    void showHand();
    string getName();
    int getChips();
    int getBet();
    void setBet(int b);
    void CashOut();
    bool isPlaying();
    void isntPlaying();
    void pay(int p);
    void dealTo(Card c);
};


#endif /* defined(__Final_Project__Player__) */
