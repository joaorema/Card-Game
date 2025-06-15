#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>

std::string roleToString(Role role) 
{
    switch (role) 
    {
        case Role::Presidente:     return "Presidente";
        case Role::V_Presidente:   return "Vice Presidente";
        case Role::V_Olho:         return "Vice Olho do Cu";
        case Role::Olho_do_Cu:     return "Olho do CU";
        default:                   return "Indefenido";
    }
}

std::string suitToString1(Suit suit) 
{
    switch (suit) 
    {
        case Suit::Heart:   return "Heart";
        case Suit::Diamond: return "Diamond";
        case Suit::Club:    return "Club";
        case Suit::Spade:   return "Spade";
        case Suit::Joker:    return "Joker";
        default:             return "Unknown";
    }
}


Player::Player() {}


Player::Player(int id, const std::string name, Role role) : _id(id), _name(name), _role(role)
{
}


Player::~Player() {}


//getters

int Player::getId()const
{
    return _id;
}

const std::string& Player::getName()const
{
    return _name;
}

Role Player::getRole()const
{
    return _role;
}

int Player::getHandSize()const
{
    return _Hand.size();
}

std::vector<int> Player::getCardNbr()const
{
    std::vector<int>nbr;
    for(const auto& card : _Hand)
        nbr.push_back(card.getNumber());
    return nbr;
}

std::vector<std::string> Player::getCardDescription()const
{
    std::vector<std::string> descriptions;
    for (const auto& card : _Hand)
    {
        descriptions.push_back(std::to_string(card.getNumber()) + " " + suitToString1(card.getType()));
    }
    return descriptions; 
}

const std::vector<Card>& Player::getHand()const
{
    return _Hand;
}

//setters

void Player::setRole(Role role)
{
    this->_role = role;
}

void Player::setName(std::string name)
{
    this->_name = name;
}

void Player::setId(int id)
{
    this->_id = id;
}

void Player::addCard(const Card& card)
{
    _Hand.push_back(card);
}

void Player::annouce()
{
    std::cout << "Player name is : " << this->_name << std::endl;
    std::cout << "Player id is : " << this->_id << std::endl;
    std::cout << "Player role is : " << roleToString(this->_role) << std::endl;

}
/*
void Player::removeCard(const Card& card)
{

}
*/



