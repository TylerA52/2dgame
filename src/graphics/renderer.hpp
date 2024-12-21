#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderer {

public:
    Renderer(const char* title, int w, int h);
    SDL_Texture* loadTexture(const char* filepath);
    SDL_Renderer* getRenderer();
    void renderEntity(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect);
    void clear();
    void cleanUp();
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
