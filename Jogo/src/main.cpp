#include <SFML/Graphics.hpp>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

int main()
{
    //setting the window
    sf::RenderWindow window;
    window.create(sf::VideoMode(1000,550),"Test");                   //Creates Window for game
    sf::Font font;                                                  //constructor for font
    if(!font.loadFromFile("DejaVuSans-Bold.ttf"))                       //load font
        return -1;
    
    //creating background menu

    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("images/Background_resized.jpg"))
        return -1;

    sf::Sprite backgroundsprite(backgroundTexture);
    backgroundsprite.setPosition(0, 0);

    //Create menu
    bool inMenu = true;
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

    sf::Text howToPlay(
        "How to play:", font, 28);
    howToPlay.setPosition(100, 200);
    howToPlay.setFillColor(sf::Color::Yellow);
    // bool showHowToPlay  = false;


    //starting deck
    Deck deck(1);
    std::cout << "The deck has : " << deck.size() << std::endl;
    Player player1(1, "Joao", Role::Indefenido);
    Player player2(2, "Bot Joana", Role::Indefenido);
    Player player3(3, "Bot Vasco", Role::Indefenido);
    Player player4(4, "Bot Miguel", Role::Indefenido);

    player1.annouce();
    player2.annouce();
    player3.annouce();
    player4.annouce();
    

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
        if(!inMenu)
            window.draw(backgroundsprite);
        window.display();
        
    }

}


 