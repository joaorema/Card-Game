#include <SFML/Graphics.hpp>
#include "card.hpp"
#include "deck.hpp"

int main()
{
    //setting the window
    sf::RenderWindow window;
    window.create(sf::VideoMode(1000,750),"Test");                   //Creates Window for game
    sf::Font font;                                                  //constructor for font
    if(!font.loadFromFile("DejaVuSans-Bold.ttf"))                       //load font
        return -1;
    
    //Create menu
    sf::Text tittle("President", font, 48);                         //creates text box
    tittle.setPosition(350, 100);                                   //set position on screen

    sf::Text start("1. Start Game", font, 32);
    start.setPosition(350, 350);

    sf::Text options("2. Options", font, 32);
    options.setPosition(350, 450);

    sf::Text htp("3. How to play", font , 32);
    htp.setPosition(350, 550);

    sf::Text howToPlay(
        "How to play:", font, 28);
    howToPlay.setPosition(100, 200);
    howToPlay.setFillColor(sf::Color::Yellow);
    bool showHowToPlay  = false;


    //starting deck
    Deck deck(1);
    std::cout << "The deck has : " << deck.size() << std::endl;
    

    //game loop
    while(window.isOpen())                                          //game loop
    {
        sf::Event end;
        while(window.pollEvent(end))                                //checks for keypresses 
        {
            if(end.type == sf::Event::Closed)                       //if we click on x on top
                window.close();
            if(end.type == sf::Event::MouseButtonPressed)
            {
                //get mouse positon
                sf::Vector2i mousePos;
                mousePos = sf::Mouse::getPosition(window);
                if(htp.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                {
                    showHowToPlay = !showHowToPlay;
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(tittle);
        window.draw(start);
        window.draw(options);
        window.draw(htp);

        if(showHowToPlay)
            window.draw(howToPlay);
        
        window.display();
        
    }

}


 