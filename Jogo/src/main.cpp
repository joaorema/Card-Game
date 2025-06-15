#include <SFML/Graphics.hpp>
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "menu.hpp"
#include "cardTexture.hpp"

std::string suitToString3(Suit suit) 
{
    switch (suit) 
    {
        case Suit::Heart:   return "heart";
        case Suit::Diamond: return "diamond";
        case Suit::Club:    return "club";
        case Suit::Spade:   return "spade";
        case Suit::Joker:    return "joker";
        default:             return "Unknown";
    }
}



int main()
{
    //loading cards images
    CardTexture cardtextures;
    if(!cardtextures.loadall())
    {
        std::cerr << "Failed to load images!" << std::endl;
        return -1;
    }

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
    sf::Sprite cardSprite;
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
            if(end.type == sf::Event::MouseButtonPressed)           //if we click on start game
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
                gameStarted = true;
            }
            const auto& hand = players[0].getHand(); 
            float startX = 100.0f;                                              // Starting x position
            float y = 400.0f;                                                   // y position for all cards

            for (size_t i = 0; i < hand.size(); ++i)
            {
                const Card& card = hand[i];
                std::string key = suitToString3(card.getType()) + "_" + std::to_string(card.getNumber());
                sf::Sprite cardSprite(cardtextures.getTexture(key));
                cardSprite.setPosition(startX + i * 50.0f, y); // 40 pixels apart
                window.draw(cardSprite);
            }

        }
        window.display();
        
    }

}


 