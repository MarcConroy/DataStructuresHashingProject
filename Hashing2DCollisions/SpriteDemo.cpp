#include "stdafx.h"
//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>

#include "MapManager.h"
#include "SpriteManager.h"
#include <iostream>
using namespace std;

// Sample program to demonstrate basic usage of SFML library. Can also be used as a starting
//  point for the spatial hashing assignment.

int main() {
	 
	sf::RenderWindow window(sf::VideoMode(DemoConstants::SCREEN_WIDTH, DemoConstants::SCREEN_HEIGHT), "SFML Window");


	
	sf::Vertex line[DemoConstants::ROWS*DemoConstants::COLUMNS] ;

	int LineNumber = 0;
		/////////////////////////horizontal lines
	
		for(int i =DemoConstants::CELLSIZE; i<DemoConstants::SCREEN_HEIGHT; i+= DemoConstants::CELLSIZE){
		line[LineNumber] = sf::Vertex(sf::Vector2f(0, i));
		++LineNumber;
		line[LineNumber] =sf::Vertex(sf::Vector2f(DemoConstants::SCREEN_WIDTH,i) );
		++LineNumber;
		}



		/////////////////////////////
		////vertical lines

		for(int i =DemoConstants::CELLSIZE; i<DemoConstants::SCREEN_WIDTH; i+= DemoConstants::CELLSIZE){
		line[LineNumber] = sf::Vertex(sf::Vector2f(i,0 ));
		++LineNumber;
		line[LineNumber] =sf::Vertex(sf::Vector2f(i,DemoConstants::SCREEN_HEIGHT) );
		++LineNumber;
		}
	
	
	
	// How to load an image
	sf::Image image;
    

	// How to create a sprite from that image.
	CustomSprite::init("chromatic_circle.png");

	// Make an instance of our sprite manager.
	SpriteManager spriteManager;

	vector<CustomSprite> & allSprites = spriteManager.getAllSprites();
	MapManager manager;
    // Start game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
	
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

		
        // Clear the screen (fill it with black color)
		window.clear(sf::Color::Black);
		
		
		// How to draw a line.		
	    window.draw(line, LineNumber, sf::Lines);	
			
		CustomSprite  first = allSprites.at(0);
		float x = first.getPosition().x;
		float y = first.getPosition().y;


		for ( int i = 0; i < allSprites.size(); ++i ) {							
			manager.registerSprite(allSprites.at(i));
		}

		// How to draw a container of sprites.
		for ( int i = 0; i < allSprites.size(); ++i ) {							
			window.draw( allSprites.at(i) );	

			
		}
		
		//make every frame in the same as the first cell green
		list<CustomSprite const *> neighbours = manager.getNearbySprites( allSprites.at(0));
		for(std::list<CustomSprite const *>::iterator it = neighbours.begin(); it != neighbours.end(); ++it){
			CustomSprite * temp = const_cast<CustomSprite *> (*it);
		
			if( &first == (*it) ){
			
			temp->setColor(sf::Color(0, 0,167));
			}
			else{
			temp->setColor(sf::Color(0, 167, 0));
			}
		}

		//TODO add update Logic here
		spriteManager.keepInBounds();
		

		//clear the sprite list at the end of each frame
			manager.clearBucketLists();

        // Display window contents on screen
        window.display();
    }
	

    return EXIT_SUCCESS;
}
