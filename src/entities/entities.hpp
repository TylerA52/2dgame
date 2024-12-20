#pragma once

class Player {
    
public:
    Player(SDL_Texture* texture);
    void update;
    SDL_Texture* getSprite();
    SDL_Rect getSrcRect();
    SDL_Rect getDstRect();
private:
    SDL_Texture* sprite;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
};
