#include "stdafx.h"
#include "CustomSprite.h"

sf::Texture CustomSprite::m_texture; 

bool CustomSprite::init(std::string const & imageFile) {
	return m_texture.loadFromFile(imageFile);
}

CustomSprite::CustomSprite(sf::Vector2f const & position, sf::Vector2f const & scale, sf::Vector2f const & dirVec) : 
	sf::Sprite(m_texture) {
		this->setScale(scale);
		this->setPosition(position);
	}


void CustomSprite::setDirection( sf::Vector2f const & dirVec ) {
	m_dirVec = dirVec;
}

sf::Vector2f const & CustomSprite::getDirection() const {
	return m_dirVec;
}

void CustomSprite::Update(){
	this->setPosition(this->getPosition() + this->getDirection());
}