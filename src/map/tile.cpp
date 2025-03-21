#include "tile.hpp"
#include <iostream>

// Taken from earlier game - re-do functions to match current project

Tilemap::Tilemap(int mapWidth, int mapHeight, SDL_Texture* tileSet)
    : mapWidth(mapWidth), mapHeight(mapHeight), tileSet(tileSet) {

    map.resize(mapHeight, std::vector<int>(mapWidth, 0));

    map = {
        {64, 11, 11, 11, 11, 64, 11, 11, 11, 64, 11, 11, 11, 11, 64, 64},
        {11, 1, 1, 1, 1, 1, 1, 11, 11, 11, 65, 64, 11, 11, 11, 65},
        {11, 1, 17, 9, 9, 17, 1, 64, 65, 64, 11, 12, 12, 11, 11, 64},
        {11, 1, 9, 9, 9, 9, 1, 11, 64, 64, 11, 12, 12, 12, 11, 11},
        {64, 1, 17, 9, 9, 17, 1, 11, 11, 64, 12, 12, 12, 11, 64, 11},
        {64, 1, 1, 9, 9, 1, 1, 11, 11, 12, 12, 12, 64, 11, 11, 11},
        {65, 64, 65, 12, 12, 64, 11, 11, 12, 12, 12, 11, 11, 11, 11, 11},
        {64, 65, 65, 12, 12, 65, 64, 12, 12, 12, 65, 65, 11, 64, 11, 64},
        {11, 11, 11, 12, 12, 11, 12, 12, 12, 11, 64, 64, 11, 11, 65, 64},
        {12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 64, 65, 11, 64, 64, 64},
        {12, 12, 12, 12, 12, 12, 12, 64, 64, 11, 11, 11, 11, 11, 11, 65},
        {11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 64, 64, 11, 64, 64}
    };
}

// Add a second map

void Tilemap::renderMap(RenderWindow& window) {
const int tilesPerRow = 8;

    for (int y = 0; y < mapHeight; y++){
        for (int x = 0; x < mapWidth; x++) {
            int tileIndex = map[y][x];

            if (tileIndex == 0) continue;

            int s_x = tileIndex % tilesPerRow;
            int s_y = tileIndex / tilesPerRow;

            Entity tileEntity(tileset, s_x, s_y, x, y);
            window.render(tileEntity);
        }
    }
}
