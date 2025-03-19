//
//  Player.cpp
//
//  Created by Max Chou on 12/17/24.
//

#include "Player.h"

Player::Player()
{
    total = 0;
    bank = STARTING_BANK;
}
void Player::hit(Deck& deck)
{
    Card c = deck.drawCard();
    if (c.rank == Ace && total <= 10)  // An ace is worth 1 or 11
    {
        total += 11;
    }
    else
    {
        total += c.value;
    }
    playersHand.push_back(c);
}
void Player::displayHand()
{
    if (playersHand.size() == 0)
    {
        std::cerr << "no cards" << std::endl;
    }
    for (int i = 0; i < playersHand.size(); i++)
    {
        std::cout << playersHand[i];
        if (i < playersHand.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}
void Player::displayFirstCard()
{
    if (playersHand.size() == 0)
    {
        std::cerr << "no cards" << std::endl;
    }
    std::cout << playersHand[0];
}
int Player::getTotal()
{
    return total;
}
int Player::getBank()
{
    return bank;
}
void Player::removeFromBank(int betAmount)
{
        bank -= betAmount;
}
void Player::addToBank(int betAmount)
{
        bank += betAmount;
}
void Player::resetHand()
{
    total = 0;
    while (!playersHand.empty())
    {
        playersHand.pop_back();
    }
}
