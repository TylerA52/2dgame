/*
#include "tilemap.hpp"


Tilemap::Tilemap(int width, int height, int tileWidth, int tileHeight, Renderer* renderer)
    : mapWidth(width), mapHeight(height), tileWidth(tileWidth), tileHeight(tileHeight), renderer(renderer) {
    tiles.resize(mapHeight, std::vector<int>(mapWidth, 0)); // init with 0 (empty)
    tileAtlasTexture = nullptr; // texture will be loaded later
    }


void Tilemap::loadTilemap(const std::string& textureFile, const std::string& layoutFile){
    tileAtlasTexture = renderer->loadTexture(textureFile);


    std::ifstream file(layoutFile);
    std::string line;
    int y = 0;
    
    while (std::getline(file, line) && y < mapHeight){
        std::istringstream ss(line);
        std::string tileIndexStr;
        int x = 0;

        while (std::getline(ss, tileIndexStr, ',') && x < mapWidth) {
            tiles[y][x] = std::stoi(tileIndexStr);
            x++;
        }
        y++;
    }
}

SDL_Texture* Renderer::loadTexture(const std::string& filename){
    SDL_Texture* newTexture = nullptr;
    newTexture = IMG_LoadTexture(renderer, filename.c_str());
    if (!newTexture){
        std::cerr << "Failed to load:: " << IMG_GetError() << std::endl;
    }
    return newTexture;
}


void Tilemap::renderTilemap() {
    


}

void Tilemap::setTile(int x, int y, int tileIndex) {
    if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
        tiles[y][x] = tileIndex;
    }
}
*/


