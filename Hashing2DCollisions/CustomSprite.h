#ifndef CUSTOMSPRITE_H
#define CUSTOMSPRITE_H

#include <string>
#include <SFML/Graphics.hpp>

class CustomSprite : public sf::Sprite {
public :

    static bool init(std::string const & imageFile);

	CustomSprite(sf::Vector2f const & position = sf::Vector2f(), sf::Vector2f const & scale = sf::Vector2f(1.0f, 1.0f), sf::Vector2f const & dirVec = sf::Vector2f(1.0f, 1.0f) );

	void setDirection( sf::Vector2f const & dirVec );
	sf::Vector2f const & getDirection() const ;

	void Update();

private :

    static sf::Texture m_texture; // Shared by every instance.
	sf::Vector2f m_dirVec;	  // Direction vector.
  
};

#endif