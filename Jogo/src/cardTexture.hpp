#ifndef CARD_TEXTURE_HPP
# define CARD_TEXTURE_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class CardTexture
{
    private:
        std::unordered_map<std::string, sf::Texture> textures;

    public:
        bool loadall();
        const sf::Texture& getTexture(const std::string& cardKey) const;



};


#endif