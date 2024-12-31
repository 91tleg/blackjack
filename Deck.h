////
//  Deck.h
//
//  Created by Max Chou on 12/17/24.
//

#ifndef Deck_h
#define Deck_h

#include <cstdlib>
#include "Card.h"

class Deck
{
public:
    Deck();
    void initDeck();
    void shuffleDeck();
    Card drawCard();
    void displayDeck();
    bool isEmpty();
    
private:
    std::vector<Card> cardDeck;
};

#endif /* Deck_h */
