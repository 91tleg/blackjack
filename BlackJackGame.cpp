//
//  BlackJackGame.cpp
//
//  Created by Max Chou on 12/31/24.
//

#include <iostream>
#include "BlackJackGame.h"

void BlackJackGame::play()
{
    while (true)
    {
        player.resetHand();
        house.resetHand();
        std::cout << "Your bank: $" << player.getBank() << std::endl;
        int inputBetAmount = getBetAmount();
        player.removeFromBank(inputBetAmount);

        // Initial hands
        player.hit(deck);
        house.hit(deck);
        player.hit(deck);
        house.hit(deck);
        std::cout << "\nDealer's hand: ";
        house.displayFirstCard();
        std::cout << ", [hidden card]";
        std::cout << "\nYour hand: ";
        player.displayHand();

        playerTurn();
        dealerTurn();
        determineResults(inputBetAmount);
        if (player.getBank() == 0)
        {
            break;
        }
    }
    std::cout << "Out of funds... Thanks for playing" << std::endl;
}
void BlackJackGame::playerTurn()
{
    while (true)
    {
        std::cout << "\nEnter 'hit' or 'stand': ";
        std::string choice;
        std::cin >> choice;

        if (choice == "hit")
        {
            player.hit(deck);
            std::cout << "Your hand: ";
            player.displayHand();
            if (player.getTotal() > MAX_TOTAL)
            {
                break;
            }
        }
        else if (choice == "stand")
        {
            break;
        }
        else
        {
            std::cout << "Invalid input... Please enter 'hit' or 'stand'." << std::endl;
        }
    }
}
void BlackJackGame::dealerTurn()
{
    if (player.getTotal() <= MAX_TOTAL)
    {
        while (house.getTotal() < 17) // Dealer stands on soft 17
        {
            house.hit(deck);
        }
    }
    std::cout << "\nDealer's hand: ";
    house.displayHand();
}
void BlackJackGame::determineResults(int inputBetAmount)
{
    int playerTotal = player.getTotal();
    int houseTotal = house.getTotal();

    if (playerTotal > MAX_TOTAL)
    {
        std::cout << "\nYou busted... Dealer wins!\n" << std::endl;
    }
    else if (houseTotal > MAX_TOTAL)
    {
        std::cout << "\nDealer busted... You win!\n" << std::endl;
        player.addToBank(inputBetAmount * 2);
    }
    else if (playerTotal > houseTotal)
    {
        std::cout << "\nCongratulations! You win!\n" << std::endl;
        player.addToBank(inputBetAmount * 2);
    }
    else if (playerTotal < houseTotal)
    {
        std::cout << "\nBetter luck next time... Dealer wins!\n" << std::endl;
    }
    else
    {
        std::cout << "\nClose one... It's a tie!\n" << std::endl;
        player.addToBank(inputBetAmount);
    }
}

int BlackJackGame::getBetAmount()
{
    int inputBetAmount;
    while (true)
    {
        std::cout << "Enter your bet in increments of 100: ";
        std::cin >> inputBetAmount;
        if (std::cin.fail() || inputBetAmount % 100 != 0)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cerr << "Invalid input. Please enter a valid number in increments of 100.\n";
            continue;
        }
        if (inputBetAmount > player.getBank())
        {
            std::cerr << "Not enough money in your bank. Try again.\n";
            continue;
        }
        break;
    }
    return inputBetAmount;
}
