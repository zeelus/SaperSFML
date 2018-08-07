#pragma once
#include <SFML/Graphics.hpp>

enum class FieldType {
	hide = 0,
	mine,
	flag,
    empty,
    number1,
    number2,
    number3,
    number4,
    number5,
    number6,
    number7,
    number8
};

class Field {
    
private:

    FieldType type = FieldType::hide;

	
public:

	static sf::Texture hideTexture;
    static sf::Texture mineTexture;
    static sf::Texture number1Texture;
    static sf::Texture number2Texture;
    static sf::Texture number3Texture;
    static sf::Texture number4Texture;
    static sf::Texture number5Texture;
    static sf::Texture number6Texture;
    static sf::Texture number7Texture;
    static sf::Texture number8Texture;
    static sf::Texture emptyTexture;
    
	static void loadTextures();
    bool isMine = false;

	Field(void);
	~Field(void);

    void changeTypeTo(FieldType type);
    FieldType getType();
    
	sf::Texture* getTexture();

};

