#include "entity.hpp"


Entity::Entity(SDL_Renderer* renderer, const char* texturePath, int srcX, int srcY)
    : sprite(IMG_LoadTexture(renderer, texturePath)){
    if (!sprite) {
        std::cout << "Failed to load sprite: " << SDL_GetError() << std::endl;
    }
    srcRect = {srcX, srcY, 16, 16};
    dstRect = {200, 200, 72, 72};
}

void Entity::update(const Input& input){
    const int playerSpeed = 8;

    if (input.isKeyPressed(SDL_SCANCODE_W)){
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


SDL_Texture* Entity::getSprite(){
    return sprite;
}

SDL_Rect Entity::getSrcRect(){
    return srcRect;
}

SDL_Rect Entity::getDstRect(){
    return dstRect;
}
