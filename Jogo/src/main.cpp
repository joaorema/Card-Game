#include <SFML/Graphics.hpp>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "menu.hpp"

int main()
{
    //setting the window
    sf::RenderWindow window;
    window.create(sf::VideoMode(1000,550),"Test");                   //Creates Window for game
    sf::Font font;                                                  //constructor for font
    if(!font.loadFromFile("DejaVuSans-Bold.ttf"))                       //load font
        return -1;
    
    //creating background
    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("images/Background_resized.jpg"))
        return -1;

    sf::Sprite backgroundsprite(backgroundTexture);
    backgroundsprite.setPosition(0, 0);

    //Create menu
    bool inMenu = true;
    bool gameStarted = false;
    auto [tittle, start, options, htp, howToPlay] = start_menu(font);
   
    //starting deck
    Deck deck(1);

    std::vector<Player> players = 
    {
        Player(1, "Joao", Role::Indefenido),
        Player(2, "Bot Joana", Role::Indefenido),
        Player(3, "Bot Vasco", Role::Indefenido),
        Player(4, "Bot Miguel", Role::Indefenido)
    };
    
    
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
                sf::Vector2i mousePos;
                mousePos = sf::Mouse::getPosition(window);
                if(start.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                {
                    inMenu = false;
                }
            }
        }
        
        window.clear(sf::Color::Black);
        if(inMenu)
        {
            window.draw(howToPlay);
            window.draw(backgroundsprite);
            window.draw(tittle);
            window.draw(start);
            window.draw(options);
            window.draw(htp);
        }
        else
        {
            window.draw(backgroundsprite);
            if(!gameStarted)
            {
                deck.shuffle();
                deck.dealCards(players);
                auto cardDescriptions = players[0].getCardDescription();
                for(const auto& desc : cardDescriptions)
                    std::cout << desc << std::endl;
                gameStarted = true;
            }
        }
        window.display();
        
    }

}


 