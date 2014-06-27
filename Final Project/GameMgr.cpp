//
//  GameMgr.cpp
//  Final Project
//
//  Created by AJ Cendejas on 6/24/14.
//  Copyright (c) 2014 AJ Cendejas. All rights reserved.
//

#include "GameMgr.h"

Shoe shoe;
Dealer dealer;
vector<Player> PlayerList;

int Welcome()
{
    int players;
    cout << "Welcome to BlackJack! How many players today(1-6)? ";
    cin >> players;
    return players;
}

void startGame()
{
    int p = Welcome();
    shoe.generateShoe();
    string n;
    int c;
    for (int i = 0; i < p; i++)
    {
        cout << "\nEnter name for Player " << i+1 << ": ";
        cin >> n;
        cout << "\nEnter chips for Player " << i+1 << " in dollars: ";
        cin >> c;
        PlayerList.push_back(Player(n, c));
    }
    for (int i = 0; i < PlayerList.size(); i++)
    {
        int tmp;
        if (PlayerList[i].isPlaying() == true)
        {
            do
            {
                cout << "\nPlayer " << i+1 << " enter your bet for the hand: ";
                cin >> tmp;
                if (tmp == 0)
                    PlayerList[i].isntPlaying();
            }while(tmp >= PlayerList[i].getChips());
            PlayerList[i].setBet(tmp);
        }
    }
}

void PlayHand()
{
    cout << "\nDealer: ";
    dealer.DealSelf(shoe);
    cout << dealer.getUpCard();
    for (int i = 0; i < PlayerList.size(); i++)
    {
        if(PlayerList[i].isPlaying())
        {
            cout << "\nPlayer " << i+1 << ": ";
            dealer.DealTo(shoe, PlayerList[i]);
            PlayerList[i].showHand();
        }
    }
    for (int i = 0; i < PlayerList.size(); i++)
    {
        if(PlayerList[i].isPlaying())
        {
            cout << "\nPlayer " << i+1 << ": \n";
            turn(PlayerList[i]);
        }
    }
    while(dealer.getValue() < 17)
    {
        dealer.dlrHand.push_back(shoe.getTop());
        shoe.popOff();
    }
    if(dealer.getValue() > 21)
        dealer.bust = true;
    else if(dealer.getValue() == 21)
        dealer.blackjack = true;
    payout();
    results();
}

void turn(Player &p)
{
    int choice;
    do
    {
        do
        {
            cout << "What would you like to do: " << endl;
            cout << "1) Hit" << endl;
            cout << "2) Stay" << endl;
            cin >> choice;
        }while(choice != 1 && choice != 2);
        switch (choice) {
            case 1:
            {
                hit(p);
            }
                break;
            case 2:
            {
                stay(p);
            }
            default:
                break;
        }
    }while (p.isPlaying());
}

void hit(Player& p)
{
    p.plyrHnd.push_back(shoe.getTop());
    
    shoe.popOff();
    int total = 0;
    for(int j = 0; j < p.plyrHnd.size(); j++)
    {
        total += p.plyrHnd[j].getValue();
    }
    if (total > 21)
    {
        cout << "\nBust\n";
        p.bust = true;
        p.isntPlaying();
    }
    else if(total == 21)
    {
        cout << "\nBlackjack\n";
        p.blackjack = true;
        p.isntPlaying();
    }
    p.showHand();
}

void stay(Player& p)
{
    p.isntPlaying();
}

void payout()
{
    int d = dealer.getValue();
    for (int i = 0; i < PlayerList.size(); i++)
    {
        int p = PlayerList[i].getValue();
        if (dealer.bust && p < 21)
        {
            PlayerList[i].pay(2*PlayerList[i].getBet());
        }
        else if (!dealer.blackjack && PlayerList[i].blackjack)
        {
            PlayerList[i].pay(1.5*PlayerList[i].getBet()+PlayerList[i].getBet());
        }
        else if (!dealer.bust && !PlayerList[i].bust)
        {
            if(p > d)
                PlayerList[i].pay(2*PlayerList[i].getBet());
            else
                PlayerList[i].pay(-PlayerList[i].getBet());
        }
        else if (PlayerList[i].bust)
            PlayerList[i].pay(-PlayerList[i].getBet());
    }
}

void results()
{
    cout << "Dealer: " << dealer.getValue();
    for (int i  = 0; i < PlayerList.size(); i++)
    {
        cout << "\nPlayer " << i+1 << ": " << PlayerList[i].getName() << " ";
        cout << PlayerList[i].getValue() << endl;
        cout << "Chips: " << PlayerList[i].getChips() << endl;
    }
}