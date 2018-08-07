#include "Field.h"

sf::Texture Field::hideTexture;
sf::Texture Field::mineTexture;
sf::Texture Field::number1Texture;
sf::Texture Field::number2Texture;
sf::Texture Field::number3Texture;
sf::Texture Field::number4Texture;
sf::Texture Field::number5Texture;
sf::Texture Field::number6Texture;
sf::Texture Field::number7Texture;
sf::Texture Field::number8Texture;
sf::Texture Field::emptyTexture;


void Field::loadTextures() {
    hideTexture.loadFromFile("textures/hideTexture.png");
    mineTexture.loadFromFile("textures/mineTexture.png");
    number1Texture.loadFromFile("textures/1Texture.png");
    number2Texture.loadFromFile("textures/2Texture.png");
    number3Texture.loadFromFile("textures/3Texture.png");
    number4Texture.loadFromFile("textures/4Texture.png");
    number5Texture.loadFromFile("textures/5Texture.png");
    number6Texture.loadFromFile("textures/6Texture.png");
    number7Texture.loadFromFile("textures/7Texture.png");
    number8Texture.loadFromFile("textures/8Texture.png");
    emptyTexture.loadFromFile("textures/emptyTexture.png");
}

Field::Field(void)
{
    
}


Field::~Field(void)
{

}

sf::Texture* Field::getTexture(){

    switch (this->type)
    {
        case FieldType::hide:
            return &Field::hideTexture;
        case FieldType::mine:
            return &Field::mineTexture;
        case FieldType ::number1:
            return &Field::number1Texture;
        case FieldType ::number2:
            return &Field::number2Texture;
        case FieldType ::number3:
            return &Field::number3Texture;
        case FieldType ::number4:
            return &Field::number4Texture;
        case FieldType ::number5:
            return &Field::number5Texture;
        case FieldType ::number6:
            return &Field::number6Texture;
        case FieldType ::number7:
            return &Field::number7Texture;
        case FieldType ::number8:
            return &Field::number8Texture;
        case FieldType ::empty:
            return  &Field::emptyTexture;
        default:
            return nullptr;
    }
}

void Field::changeTypeTo(FieldType type) {
    this->type = type;
}

FieldType Field::getType() {
    return this->type;
}
