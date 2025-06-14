#ifndef DECK_HPP
# define DECK_HPP

#include <vector>
#include "card.hpp"
#include <string>

class Deck
{
    private:
        std::vector<Card> _cards;
    public:

        //constructors
        Deck();
        ~Deck();
        Deck(int type);

        //getters & setters

        bool isEmpty() const;                           //checks if there are no cards  
        void shuffle();                                 //shuffle the deck
        int size() const;                               //how many cards left

        Card dealCards();                               //
};






#endif