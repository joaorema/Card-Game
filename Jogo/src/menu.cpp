#include "menu.hpp"

std::tuple<sf::Text, sf::Text, sf::Text, sf::Text, sf::Text>
start_menu(sf::Font& font)
{
    sf::Text tittle("Presidente", font, 48);                         //creates text box
    tittle.setPosition(350, 135);                                   //set position on screen
    tittle.setFillColor(sf::Color::Red);

    sf::Text start("1. Start Game", font, 32);
    start.setPosition(350, 230);
    start.setFillColor(sf::Color::Black);

    sf::Text options("2. Options", font, 32);
    options.setPosition(350, 290);
    options.setFillColor(sf::Color::Black);

    sf::Text htp("3. How to play", font , 32);
    htp.setPosition(350, 350);
    htp.setFillColor(sf::Color::Black);

    sf::Text howToPlay("How to play:", font, 28);
    howToPlay.setPosition(100, 200);
    howToPlay.setFillColor(sf::Color::Yellow);

    return {tittle, start, options, htp, howToPlay};
}

