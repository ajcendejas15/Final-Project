//
//  Card.cpp
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#include "Card.h"

Card::Card(int s, int n)
{
	setSuit(s);
	setNum(n);
    setValue(n);
}

int Card::getNum() { return num;}

void Card::setNum(int n)
{
    num = n;
}

int Card::getSuit() {return suit;}

void Card::setSuit(int s)
{
	suit = (s >= SPADES && s <= HEARTS) ? s : SPADES;
}

int Card::getValue() {return value;}

void Card::setValue(int n)
{
	if (n >= 1 && n <= 10)
        value = n;
    else if(n > 10 && n < 14)
        value = 10;
}

bool Card::operator==(Card& c)
{
	return (getSuit() == c.getSuit() && getNum() == c.getNum());
}

ostream& operator<<(ostream& str, const Card& c)
{
	if (c.num == 13) str << "King";
	else if (c.num == 12) str << "Queen";
	else if (c.num == 11) str << "Jack";
	else if (c.num == 1) str << "Ace";
	else str << c.num;
    
	str << " of ";
    
	switch (c.suit) {
        case Card::SPADES:
            str << "Spades";
            break;
        case Card::DIAMONDS:
            str << "Diamonds";
            break;
        case Card::CLUBS:
            str << "Clubs";
            break;
        case Card::HEARTS:
            str << "Hearts";
            break;
	}
	return str;
}