#include "player.hpp"


Player::Player(SDL_Renderer* renderer, const char* texturePath)
    : sprite(IMG_LoadTexture(renderer, texturePath)){
    if (!sprite) {
        std::cout << "Failed to load sprite: " << SDL_GetError() << std::endl;
    }
    currentFrame = 0;
    animationTimer.start();

    srcRect = {0, 64, 16, 16};
    dstRect = {100, 100, 150, 150};
}

void Player::update(const Input& input){
    const int playerSpeed = 8;

    if (input.isKeyPressed(SDL_SCANCODE_W)){

        // once a sprite class is implemented I can go through the frames with something like this

        /**if (animationTimer.getPassedTime() >= 100 {
            currentFrame ++;
            if (currentFrame >= sprite.getFrameCount()) {
                currentFrame = 0;
            }
            sprite.setFrame(currentFrame);
            animationTimer.start();
        }**/

        srcRect.x = 16;
        srcRect.y = 112;
        dstRect.y -= playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_A)){
        
        // Sprite changing by if statement  works but far too quickly
        // revist after adding time mechanics in utils dir?

        if (srcRect.x == 16 && srcRect.y == 80){
            srcRect.x = 32;
            srcRect.y = 80;
        } else {
        srcRect.x = 16;
        srcRect.y = 80;
        }
        dstRect.x -= playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_S)){
        srcRect.x = 16;
        srcRect.y = 64;
        dstRect.y += playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_D)){
        srcRect.x = 16;
        srcRect.y = 96;
        dstRect.x += playerSpeed;
    }
}


SDL_Texture* Player::getSprite(){
    return sprite;
}

SDL_Rect Player::getSrcRect(){
    return srcRect;
}

SDL_Rect Player::getDstRect(){
    return dstRect;
}
