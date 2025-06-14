#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>


enum class Role
{
    Presidente,
    V_Presidente,
    V_Olho,
    Olho_do_Cu,
    Indefenido
};

class Player
{
    private:
        int _id;                            //player id
        std::string _name;                         //player name
        std::vector<Card> _Hand;            //players hand (cards that player have atm)
        Role _role;                         //after 1 game change if needed

    public:
        Player();
        ~Player();
        Player(int id, std::string name, Role role);

        //getters

        int getId()const;
        const std::string& getName()const;
        Role getRole()const;
        int getHandSize() const;
        std::vector<int>getCardNbr()const;
        std::vector<std::string> getCardDescription() const;

        //setters
        
        void setRole(Role role);
        void setName(std::string name);
        void setId(int id);
        void addCard(const Card& card);

        //others

        void removeCard(const Card& card);      //used to remove card from hand
        void annouce();

};

#endif