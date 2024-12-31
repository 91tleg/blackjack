//
//  BlackJackGame.h
//
//  Created by Max Chou on 12/31/24.
//

#ifndef BlackJackGame_h
#define BlackJackGame_h

#include <iostream>
#include <string>
#include "Deck.h"
#include "Player.h"

class BlackJackGame
{
public:
    void play();
    
private:
    static const int MAX_TOTAL = 21;
    Player player;
    Player house;
    Deck deck;
    void playerTurn();
    void dealerTurn();
    void determineResults(int inputBetAmount);
    int getBetAmount();
};

#endif /* BlackJackGame_h */
