//
//  Card.h
//
//  Created by Max Chou on 12/17/24.
//

#ifndef Card_h
#define Card_h

#include <string>

enum Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
};
enum Rank
{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};
struct Card
{
    Suit suit;
    Rank rank;
    int value;
    std::string suitToString(Suit suit) const
    {
        switch (suit)
        {
        case Hearts:
            return "Hearts";
        case Diamonds:
            return "Diamonds";
        case Clubs:
            return "Clubs";
        case Spades:
            return "Spades";
        }
    }
    std::string rankToString(Rank rank) const
    {
        switch (rank)
        {
        case Ace:
            return "Ace";
        case Two:
            return "Two";
        case Three:
            return "Three";
        case Four:
            return "Four";
        case Five:
            return "Five";
        case Six:
            return "Six";
        case Seven:
            return "Seven";
        case Eight:
            return "Eight";
        case Nine:
            return "Nine";
        case Ten:
            return "Ten";
        case Jack:
            return "Jack";
        case Queen:
            return "Queen";
        case King:
            return "King";
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const Card& card)
    {
        return os << card.rankToString(card.rank) << " of " << card.suitToString(card.suit);
    }
};

#endif /* Card_h */
