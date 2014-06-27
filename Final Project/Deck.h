//
//  Deck.h
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#ifndef __Final_Project__Deck__
#define __Final_Project__Deck__

#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

class Deck
{
private:
    vector<Card> cards;
    int size;
public:
    Deck();
    void shuffle();
    int getSize();
    Card getTop();
    void popOff();
};

#endif /* defined(__Final_Project__Deck__) */
