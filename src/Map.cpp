#include "libtcod.hpp"
#include "Map.hpp"

Map::Map(int width, int height) : width(width),height(height) {
    tiles=new Tile[width*height];
    setWall(30,22);
    setWall(50,22);
}

Map::~Map() {
    delete [] tiles;
}

bool Map::isWall(int x, int y) const {
    return !tiles[x+y*width].canWalk;
}

void Map::dig(int x1, int y1, int x2, int y3) {
	if (x2 < x1) {
		int tmp=x2;
		x2=x1;
		x1=tmp;
	}
	if ( y2 < y1) {
		int tmp= y2;
		y2=y1;
		y1=tmp;
	}
	for (int tilex=x1; tilex <= x2; tilex++) {
		for (int tiley=y1; tiley <= y2; tiley++) {
			tiles[tilex+tiley*width].canWalk=true;
		}
	}
}
 
void Map::setWall(int x, int y) {
    tiles[x+y*width].canWalk=false;
}

void Map::render() const {
    static const TCODColor darkWall(0,0,100);
    static const TCODColor darkGround(50,50,150);

	for (int x=0; x < width; x++) {
	    for (int y=0; y < height; y++) {
	        TCODConsole::root->setCharBackground( x,y,
	            isWall(x,y) ? darkWall : darkGround );
	    }
	}
}
