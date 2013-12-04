#include "stdafx.h"
#include "MapManager.h"

// Constructor method for the MapManager (see step 2 in the assignment)
MapManager::MapManager() {
	for(int i= 0;i<(DemoConstants::COLUMNS* DemoConstants::ROWS); ++i){ //for loop counts through the cells
		//m_buckets[i] = list<CustomSprite const*>();

		//fill the List with a placeholder sprite
		list<CustomSprite const *> placeholder;
		m_buckets[i] = placeholder;
		
	}

}

// Clear each entry in the map (step 3 in the assignment)
void MapManager::clearBucketLists() {	
	
	for(int i= 0;i<(DemoConstants::COLUMNS* DemoConstants::ROWS); ++i){
		// TODO: Implement logic here...
		m_buckets[i].clear();
			/*for(std::list<int>::iterator it = cellIds.begin(); it != cellIds.end(); ++it){
				m_buckets[*it].push_back(&sprite);
			}*/

	}
}

//int BucketSize();
int MapManager::BucketSize(){
	return m_buckets.size();
}

// Register the given sprite in the map (step 5 in the assignment)
void MapManager::registerSprite( CustomSprite const & sprite ) {
	list<int> cellIds = getBucketId( sprite );

		//if one of the hash id's matches the cell number i, add it to m_buckets[i]
	//for(int i= 0;i<(DemoConstants::COLUMNS* DemoConstants::ROWS); ++i){
		// TODO: Implement logic here...
		for(std::list<int>::iterator it = cellIds.begin(); it != cellIds.end(); ++it){
				m_buckets[*it].push_back(&sprite);
			}
		

	//}
}


/*
list<int> myList;
myList.push_back(1);
myList.push_back(1);
myList.push_back(2);	// 1, 1, 2
myList.unique();		// 1, 2
*/


// For each sprite corner, call the AddSpriteToBucket member function below. 
// See step 4 in the assignment for further details.
list<int> MapManager::getBucketId(CustomSprite const & sprite) {
	// A list of bucket id's that the given sprite is in.
	list<int> bucketsSpriteIsIn;

	// TODO: Implement logic here...
	float cellWidth = DemoConstants::SCREEN_WIDTH / DemoConstants::COLUMNS;
	float cellHeight = DemoConstants::SCREEN_HEIGHT / DemoConstants::ROWS;

	//floor( spriteX / cell width ) + ( floor( spriteY / cell width ) * Number of Columns )

	//top 
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;
	float width = sprite.getTextureRect().width;
	float height = sprite.getTextureRect().height;

	//floor( spriteX / cell width ) + ( floor( spriteY / cell width ) * Number of Columns )
	// TL -- 0 + 0
	bucketsSpriteIsIn.push_back( floor(x/ cellWidth) + (floor(y/ cellHeight)* DemoConstants::COLUMNS) );
	
	// TR -- width + 0
	// sprite.getTextureRect().width();
	bucketsSpriteIsIn.push_back( floor((x + width)/ cellWidth) + (floor(y/ cellHeight)* DemoConstants::COLUMNS) );
	
	//floor( spriteX / cell width ) + ( floor( spriteY / cell width ) * Number of Columns )
	//BR -- width + height
	bucketsSpriteIsIn.push_back( floor( (x+ width)/ cellWidth) + (floor((y + height)/ cellHeight)* DemoConstants::COLUMNS) );
	//BL -- 0 + height
	bucketsSpriteIsIn.push_back( floor(x/ cellWidth) + (floor((y +height) / cellHeight)* DemoConstants::COLUMNS) );
	bucketsSpriteIsIn.unique();//remove duplicates

	return bucketsSpriteIsIn;
}

// For the given sprite corner, work out which bucket the sprite should be added to, then
//  add it's bucketid to the list.
void MapManager::addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn ) {
	// TODO: Implement logic here...

}

// Returns a list of nearby sprites for the given sprite (step 6 in the assignment).
list<CustomSprite const *> MapManager::getNearbySprites( CustomSprite const & sprite ) {
	// The list of nearby sprites to return.
	list<CustomSprite const *> nearbySprites;

	// TODO: Implement logic here...
	//get all of sprite's hash ids
		list<int> cellIds = getBucketId( sprite );

		

		//cellIds.unique();//remove duplicates
		for(std::list<int>::iterator it = cellIds.begin(); it != cellIds.end(); ++it){
			//compair m_buckets int id to sprites hash ID and add all the list items in m_bucket's matching id
			int bucketId = *it;
			list<CustomSprite const *> temp = m_buckets[bucketId];
			nearbySprites.splice( nearbySprites.begin(), temp, temp.begin() );
			/*if(m_buckets[*it]== *cellIds[it] ){//??? how to compair
			//place any sprite in m_buckets thats id matchs the ids in cellId into nearbySprites;
				nearbySprites.push_back(m_buckets[*it]);
			}*/
		}
	return nearbySprites;
}
