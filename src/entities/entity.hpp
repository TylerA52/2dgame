#pragma once
#include "input/input.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Entity {
    
public:
    Entity(SDL_Renderer* renderer, const char* texturePath, int srcX, int srcY);
    void update(const Input& input);
    SDL_Texture* getSprite();
    SDL_Rect getSrcRect();
    SDL_Rect getDstRect();
private:
    SDL_Texture* sprite;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
};
