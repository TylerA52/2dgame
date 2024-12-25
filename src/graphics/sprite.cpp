#include "sprite.hpp"
#include <iostream>
#include <SDL2/SDL.h>

Sprite::Sprite(SDL_Renderer* renderer, const char* texturePath, int frameWidth, int frameHeight, int frameCount, int rows)
    : frameWidth(frameWidth), frameHeight(frameHeight), frameCount(frameCount), rows(rows), currentFrame(0), currentRow(0) {

    texture = IMG_LoadTexture(renderer, texturePath);
    if (!texture) {
        std::cout << "Failed to load sprite texture: " << SDL_GetError() << std::endl;
    }

    srcRect {0, 0, frameWidth, frameHeight};
}

Sprite::~Sprite() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

std::vector<SDL_Rect> leftWalk = {
// fill each vector with the three walking frames
}

std::vector<SDL_Rect> rightWalk = {

}

std::vector<SDL_Rect> upWalk = {

}

std::vector<SDL_Rect> downWalk = {

}

void Sprite::update(Uint32 passedTime) {
    if (passedTime >= frameTime) {
        currentFrame = (currentFrame + 1) % frameCount;

        srcRect = frames[currentFrame];
        //animationTimer.reset();
    }
}

void Sprite::setRow(int row) {
    currentRow = row;
}

SDL_Texture* Sprite::getTexture() const {
    return texture;
}

SDL_Rect Sprite::getSrcRect() const {
    return srcRect;
}

int Sprite::getFrameCount() const {
    return frameCount;
}

}
