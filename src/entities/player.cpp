#include "player.hpp"


Player::Player(SDL_Renderer* renderer, const char* texturePath)
    : sprite(IMG_LoadTexture(renderer, texturePath)){
    if (!sprite) {
        std::cout << "Failed to load sprite: " << SDL_GetError() << std::endl;
    }
    currentFrame = 0;
    animationTimer.start();

    srcRect = {64, 16, 16, 16};
    dstRect = {600, 100, 72, 72};
}

void Player::update(const Input& input){
    const int playerSpeed = 5;

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

        srcRect.x = 48;
        srcRect.y = 48;
        dstRect.y -= playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_A)){
        
        if (animationTimer.getTime() >= 125) {
            if (srcRect.x == 64 && srcRect.y == 16){
                srcRect.x = 80;
                srcRect.y = 16;
            } else if (srcRect.x == 80 && srcRect.y == 16){
                srcRect.x = 48;
                srcRect.y = 16;
            } else {
                srcRect.x = 64;
                srcRect.y = 16;
            }   
            //dstRect.x -= playerSpeed; -FOR TESTING
            animationTimer.start();
        }
        dstRect.x -= playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_S)){
        srcRect.x = 48;
        srcRect.y = 0;
        dstRect.y += playerSpeed;
    }
    if (input.isKeyPressed(SDL_SCANCODE_D)){
        srcRect.x = 48;
        srcRect.y = 32;
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
