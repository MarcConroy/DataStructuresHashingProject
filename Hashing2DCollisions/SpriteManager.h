#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "CustomSprite.h"
#include "DemoConstants.h"
#include <vector>

using std::vector;
using namespace std;

class SpriteManager {
public:
	SpriteManager();

	vector<CustomSprite> & getAllSprites();
	void keepInBounds();

private:
	vector<CustomSprite> m_sprites;
};

#endif