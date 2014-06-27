//
//  Card.h
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#ifndef __Final_Project__Card__
#define __Final_Project__Card__

#include <iostream>
using namespace std;

class Card {
private:
    int num;
	int suit;
	int value;
    
public:
	static const int SPADES = 1;
	static const int DIAMONDS = 2;
	static const int CLUBS = 3;
	static const int HEARTS = 4;
    
	Card(int s, int n);
    
	int getSuit();
	void setSuit(int s);
	int getNum();
	void setNum(int n);
    int getValue();
    void setValue(int n);
    
	friend ostream& operator<<(ostream& str, const Card& c);
	bool operator==(Card& c);
};

#endif /* defined(__Final_Project__Card__) */
