#ifndef CARD_HPP
# define CARD_HPP

#include <iostream>
#include <string>

enum class Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades,
    Joker
};


class Card
{
    private:
        int _number;
        Suit _type;

    public:
        //constructors
        Card();
        Card(int number, Suit type);                                 
        ~Card();
        Card(const Card &other);                //copy contructor for card
        Card(Card&& other) noexcept;            //move contructor for card

        //Getters and setters
        Suit getType() const;
        void setType(Suit type);

        void setNumber(int nbr);
        int  getNumber(void) const;

};





#endif