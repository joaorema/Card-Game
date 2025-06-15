#include "cardTexture.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

bool CardTexture::loadall() {
    std::vector<std::string> suits = {"club", "diamond", "heart", "spade"};
    for (const auto& suit : suits) {
        for (int value = 1; value <= 13; ++value) {
            std::ostringstream oss;
            oss << "Cards/" << suit << "_" << std::setw(4) << std::setfill('0') << value << ".png";
            std::string filename = oss.str();
            std::cout << "Trying to load: " << filename << std::endl;
            sf::Texture tex;
            if (!tex.loadFromFile(filename)) {
                std::cerr << "Failed to load " << filename << std::endl;
                return false;
            }
            std::string key = suit + "_" + std::to_string(value);
            textures[key] = std::move(tex);
        }
    }
    return true;
}

const sf::Texture& CardTexture::getTexture(const std::string& cardKey)const
{
    return textures.at(cardKey);
}