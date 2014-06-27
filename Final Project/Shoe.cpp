//
//  Shoe.cpp
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#include "Shoe.h"

Shoe::Shoe() {}

void Shoe::generateShoe()
{
    cout << "\nHow many decks would you like to use? ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        decks.push_back(Deck());
    }
    for (int i = 0; i < num; i++)
    {
        decks[i].shuffle();
        for (int j = 0; j < decks[i].getSize(); j++)
        {
            shoe.push_back(decks[i].getTop());
            decks[i].popOff();
        }
    }
}

void Shoe::shuffle()
{
    for (int i = 0; i < num; i++)
    {
        decks[i].shuffle();
    }
}

Card Shoe::getTop()
{
    return shoe[shoe.size()-1];
}

void Shoe::popOff()
{
    shoe.pop_back();
}