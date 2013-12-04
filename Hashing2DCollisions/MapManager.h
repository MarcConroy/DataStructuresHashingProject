#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "DemoConstants.h"
#include "CustomSprite.h"

#include <map>
#include <list>
#include <algorithm> // for STL find()
#include <cmath>

using std::list;
using std::map;

// See MapManager.cpp for instructions on each member function below.

class MapManager {
public:

	MapManager();//constructor

	void clearBucketLists();//to clear the list
	int BucketSize();//to return

	void registerSprite( CustomSprite const & sprite );
	list<CustomSprite const *> getNearbySprites( CustomSprite const & sprite );

private:

	map< int, list< CustomSprite const *> > m_buckets;// the map list of buckets

	list<int> getBucketId( CustomSprite const & sprite );	

	void addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn );

};

#endif