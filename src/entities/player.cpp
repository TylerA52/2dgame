#include "player.hpp"


Player::Player(SDL_Renderer* renderer, const char* texturePath)
    : sprite(IMG_LoadTexture(renderer, texturePath)){
    if (!sprite) {
        std::cout << "Failed to load sprite: " << SDL_GetError() << std::endl;
    }
    srcRect = {0, 64, 16, 16};
    dstRect = {100, 100, 72, 72};
}

void Player::update(const Input& input){
    const int playerSpeed = 10;

    if (input.isKeyPressed(SDL_SCANCODE_W)){
        dstRect.y -= playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_A)){
        dstRect.x -= playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_S)){
        dstRect.y += playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_D)){
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
