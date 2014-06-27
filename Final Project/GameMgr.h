//
//  GameMgr.h
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#ifndef __Final_Project__GameMgr__
#define __Final_Project__GameMgr__

#include <iostream>
#include "Dealer.h"
using namespace std;

int Welcome();
void startGame();
void PlayHand();
void turn(Player& p);
void payout();
void results();
void hit(Player& p);
void stay(Player& p);

#endif /* defined(__Final_Project__GameMgr__) */
