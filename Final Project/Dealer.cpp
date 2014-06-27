//
//  Dealer.cpp
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#include "Dealer.h"

Dealer::Dealer()
{
    name = "Pete";
}

Dealer::Dealer(string n)
{
    name = n;
}

Card Dealer::getUpCard()
{
    return dlrHand[0];
}

string Dealer::getName()
{
    return name;
}

void Dealer::DealTo(Shoe &s, Player& p)
{
    for(int i = 0; i < 2; i++)
    {
        p.dealTo(s.getTop());
        if (s.getTop().getNum() == 1)
        {
            int value;
            cout << "1 or 11: ";
            cin >> value;
            p.plyrHnd[i].setValue(value);
        }
        s.popOff();
    }
}

void Dealer::DealSelf(Shoe &s)
{
    for(int i = 0; i < 2; i++)
    {
        dlrHand.push_back(s.getTop());
        if (s.getTop().getNum() == 1)
        {
            int value;
            cout << "1 or 11: ";
            cin >> value;
            dlrHand[i].setValue(value);
        }
        s.popOff();
    }
}

int Dealer::getValue()
{
    int value = 0;
    for (int i = 0; i < dlrHand.size(); i++)
    {
        value += dlrHand[i].getValue();
    }
    return value;
}