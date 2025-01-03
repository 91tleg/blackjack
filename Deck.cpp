//
//  Deck.cpp
//
//  Created by Max Chou on 12/17/24.
//

#include "Deck.h"

Deck::Deck()
{
    initDeck();
    shuffleDeck();
}
void Deck::initDeck()
{
    for (int col = (int)Suit::Hearts; col <= (int)Suit::Spades; col++)
    {
        for (int row = (int)Rank::Ace; row <= (int)Rank::King; row++)
        {
            Card newCard;
            newCard.suit = (Suit)col;
            newCard.rank = (Rank)row;
            if (newCard.rank == Jack || newCard.rank == Queen || newCard.rank == King)
            {
                newCard.value = 10;
            }
            else
            {
                newCard.value = (int)newCard.rank;
            }
            cardDeck.push_back(newCard);
        }
    }
}
void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(cardDeck), std::end(cardDeck), g);
}
Card Deck::drawCard()
{
    if (isEmpty())
    {
        std::cout << "out of cards, new deck drawn" << std::endl;
        initDeck();
        shuffleDeck();
    }
    Card card = cardDeck[cardDeck.size() - 1];
    cardDeck.pop_back();
    return card;
}
void Deck::displayDeck()
{
    for (int i = 0; i < cardDeck.size(); i++)
    {
        std::cout << cardDeck[i] << std::endl;
    }
}
bool Deck::isEmpty()
{
    return cardDeck.empty();
}
