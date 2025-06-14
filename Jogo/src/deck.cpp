#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

//constructors


Deck::Deck()                                                    //creates a deck with 52 cards
{
    for(int naipe = 0; naipe < 4; ++naipe)
    {
        for(int nbr = 1; nbr <= 13; ++nbr)
        {
            _cards.emplace_back(nbr, static_cast<Suit>(naipe));     //emplace_back puts on the last spot of the vector a card
        }
    }
}

Deck::~Deck() {}

Deck::Deck(int type)                                            //create deck with jokers 54 cards  
{
    for(int naipe = 0; naipe < 4; ++naipe)
    {
        for(int nbr = 1; nbr <= 13; ++nbr)
        {
            _cards.emplace_back(nbr, static_cast<Suit>(naipe));
        }
    }
    if (type == 1)
    {
        _cards.emplace_back(0, Suit::Joker);
        _cards.emplace_back(0, Suit::Joker);
    }
}

int Deck::size()const
{
    return _cards.size();
}

void Deck::dealCards(std::vector<Player>& players)
{
    size_t nbrPlayers;
    size_t currentPlayer;

    nbrPlayers = players.size();
    currentPlayer = 0;

    while(!_cards.empty())
    {
        Card card = _cards.back();
        _cards.pop_back();
        players[currentPlayer].addCard(card);
        currentPlayer = (currentPlayer + 1) % nbrPlayers;
    }
}

void Deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(_cards.begin(), _cards.end(), std::default_random_engine(seed));
}