#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include <iostream>
#include <string>


//constructors


Deck::Deck()                                                    //creates a deck with 52 cards
{
    for(int naipe = 0; naipe < 4; ++naipe)
    {
        for(int nbr = 1; nbr <= 13; ++nbr)
        {
            _cards.emplace_back(nbr, static_cast<Suit>(naipe));
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
