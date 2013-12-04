#include "stdafx.h"
#include "SpriteManager.h"

// Adds DemoConstants::NUM_SPRITES to a container, each sprite has a random screen position
//  and direction vector.
SpriteManager::SpriteManager() {

	for (int i = 0 ; i < DemoConstants::NUM_SPRITES; ++i) {
		CustomSprite sprite;

		sprite.setScale( sf::Vector2f(0.5f, 0.5f) );
		sprite.setPosition( rand() % static_cast<int> ( ( DemoConstants::SCREEN_WIDTH - sprite.getGlobalBounds().width ) ), 
			rand() % static_cast<int> ( ( DemoConstants::SCREEN_HEIGHT - sprite.getGlobalBounds().height ) ) );	   	
		// Give each sprite a random direction vector.
		float randXDir = ( rand() % 10 ) / 100.0f;		// change back to 10
		float randYDir = ( rand() % 10 ) / 100.0f;
		sprite.setDirection( sf::Vector2f( randXDir, randYDir ) );
		m_sprites.push_back( sprite );
	}	
}

vector<CustomSprite> & SpriteManager::getAllSprites() {
	return m_sprites;
}

// Iterate through the sprite container, and make sure each sprite stays within the
//  dimensions of the display (i.e. from 0,0 to DemoConstants::SCREEN_WIDTH, DemoConstants::SCREEN_HEIGHT)
void SpriteManager::keepInBounds() {

	//for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
 
	for(int i = 0; i < m_sprites.size(); ++i){
		if(m_sprites.at(i).getPosition().x <= 0 || m_sprites.at(i).getPosition().x >=DemoConstants::SCREEN_WIDTH) {
			m_sprites.at(i).setDirection( sf::Vector2f( m_sprites.at(i).getDirection().x * -1,m_sprites.at(i).getDirection().y));
		}

		if(m_sprites.at(i).getPosition().y <= 0 ||m_sprites.at(i).getPosition().y >= DemoConstants::SCREEN_HEIGHT) {
			
			m_sprites.at(i).setDirection( sf::Vector2f( m_sprites.at(i).getDirection().x ,m_sprites.at(i).getDirection().y* -1));
		}
		
		m_sprites.at(i).Update();//update the sprite's position
			}
	
}