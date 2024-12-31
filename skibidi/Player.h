//
//  Player.h
//
//  Created by Max Chou on 12/17/24.
//

#ifndef Player_h
#define Player_h

#include <vector>
#include "Deck.h"

class Player
{
public:
    Player();
    void hit(Deck& deck);
    void displayHand();
    void displayFirstCard();
    int getTotal();
    int getBank();
    void removeFromBank(int betAmount);
    void addToBank(int betAmount);
    void resetHand();
    
private:
    int total;
    int bank;
    static const int STARTING_BANK = 500;
    std::vector<Card> playersHand;
};

#endif /* Player_h */
