//
//  Shoe.h
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#ifndef __Final_Project__Shoe__
#define __Final_Project__Shoe__

#include <iostream>
#include <vector>
#include "Deck.h"
using namespace std;

class Shoe
{
private:
    vector<Card> shoe;
    vector<Deck> decks;
    int num;
public:
    Shoe();
    void generateShoe();
    void shuffle();
    Card getTop();
    void popOff();
};

#endif /* defined(__Final_Project__Shoe__) */
