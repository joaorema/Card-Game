#include "card.hpp"


//Constructors


Card::Card()
{

}

Card::~Card()
{
    //std::cout << "Destroying card" << std::endl;
}

Card::Card(int number, Suit type) : _number(number), _type(type)
{
    //std::cout << "Created a card " << std::endl; 
}

Card::Card(const Card &other) : _number(other._number), _type(other._type)
{
    //std::cout << "Copying card" << std::endl;
}

Card::Card(Card&& other) noexcept : _number(other._number), _type(other._type)
{
    //std::cout << "Moving card" << std::endl;
}

//getters and setters


Suit Card::getType() const
{
    return _type;
}

void Card::setType(Suit type)
{
    this->_type = type;
}

int Card::getNumber() const
{
    return _number;
}

void Card::setNumber(int nbr)
{
    this->_number = nbr;
}

std::string suitToString(Suit suit) 
{
    switch (suit) 
    {
        case Suit::Hearts:   return "Hearts";
        case Suit::Diamonds: return "Diamonds";
        case Suit::Clubs:    return "Clubs";
        case Suit::Spades:   return "Spades";
        case Suit::Joker:    return "Joker";
        default:             return "Unknown";
    }
}