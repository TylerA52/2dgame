#include "player.hpp"
#include "graphics/sprite.hpp"


Player::Player(SDL_Renderer* renderer, const char* texturePath)
    : sprite(renderer, texturePath, 16, 16, 3){
    currentFrame = 0;
    animationTimer.start();

    dstRect = {100, 100, 72, 72};
}

void Player::update(const Input& input){
    const int playerSpeed = 5;
    Uint32 passedTime = animationTimer.getTime();

    if (input.isKeyPressed(SDL_SCANCODE_W)){
        sprite.setRow(0);
        sprite.update(passedTime);
        dstRect.y -= playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_A)){
        sprite.setRow(1);
        sprite.update(passedTime);
        dstRect.x -= playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_S)){
        sprite.setRow(2);
        sprite.update(passedTime);
        dstRect.y += playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_D)){
        sprite.setRow(3);
        sprite.update(passedTime);
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
