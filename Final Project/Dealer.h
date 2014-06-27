//
//  Dealer.h
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#ifndef __Final_Project__Dealer__
#define __Final_Project__Dealer__

#include <iostream>
#include "Player.h"
using namespace std;

class Dealer
{
private:
    string name;
public:
    vector<Card> dlrHand;
    bool bust;
    bool blackjack;
    Dealer();
    Dealer(string n);
    Card getUpCard();
    string getName();
    void DealTo(Shoe &s, Player& p);
    void DealSelf(Shoe &s);
    int getValue();
};


#endif /* defined(__Final_Project__Dealer__) */
