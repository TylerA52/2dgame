#pragma once
#include "input/input.hpp"
#include "utils/timer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Player {
    
public:
    Player(SDL_Renderer* renderer, const char* texturePath);
    void update(const Input& input);
    SDL_Texture* getSprite();
    SDL_Rect getSrcRect();
    SDL_Rect getDstRect();
private:
    SDL_Texture* sprite;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    Timer animationTimer;
    int currentFrame;
};
