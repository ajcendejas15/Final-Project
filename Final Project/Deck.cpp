//
//  Deck.cpp
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#include "Deck.h"

Deck::Deck()
{
    vector<Card> tmp;
	bool found;
	while (tmp.size() < 52) {
		Card c(rand() % 4 + 1, rand() % 13 + 1);
		found = false;
		for (int i = 0; !found && i < tmp.size(); i++) {
			found = (tmp[i] == c);
		}
		if (!found)
			tmp.push_back(c);
	}
    
	for (int i = tmp.size() - 1; i >= 0; i--)
		cards.push_back(tmp[i]);
    
    size = cards.size();
}

void Deck::shuffle()
{
    srand (time(NULL));
    for (int i = cards.size()-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

int Deck::getSize()
{
    return size;
}

Card Deck::getTop()
{
    int i = cards.size();
    return cards[i];
}

void Deck::popOff()
{
    cards.pop_back();
}