//
//  Player.cpp
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#include "Player.h"

Player::Player()
{
    name = "AJ";
    chips = 100000;
    playing = true;
    bet = 0;
    bust = blackjack = false;
}

Player::Player(string n, int c)
{
    name = n;
    chips = c;
    playing = true;
    bet = 0;
    bust = blackjack = false;
}

void Player::showHand()
{
    for (int i = 0; i < plyrHnd.size(); i++)
    {
        cout << plyrHnd[i] << endl;
    }
}

string Player::getName()
{
    return name;
}

int Player::getValue()
{
    int value = 0;
    for (int i = 0; i < plyrHnd.size(); i++)
    {
        value += plyrHnd[i].getValue();
    }
    return value;
}

int Player::getChips()
{
    return chips;
}

int Player::getBet()
{
    return bet;
}

void Player::setBet(int b)
{
    bet = b;
}

void Player::CashOut()
{
    cout << "Have a nice day " << name << ", thanks for playing!";
    playing = false;
}

bool Player::isPlaying()
{
    return playing;
}

void Player::isntPlaying()
{
    playing = false;
}

void Player::pay(int p)
{
    chips += p;
}

void Player::dealTo(Card c)
{
    plyrHnd.push_back(c);
}