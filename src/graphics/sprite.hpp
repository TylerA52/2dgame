#pragma once

class Sprite {

public:
    Sprite(SDL_Renderer* renderer, const char* texturePath, int frameWidth, int frameHeight, int frameCount, int rows);
    ~Sprite();
    void update(Uint32 passedTime);
    SDL_Texture* getTexture() const;
    SDL_Rect getSrcRect() const;
    int getFrameCount() const;

private:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    int frameWidth, frameHeight, frameCount, rows, currentFrame, currentRow;
    const Uint 32 frameTime = 125;
};
