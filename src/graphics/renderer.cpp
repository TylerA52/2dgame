#include "renderer.hpp"
#include <iostream>

Renderer::Renderer(const char* title, int w, int h)
    :window(NULL), renderer(NULL) {

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h,
            SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Window failed to initialize: " << SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* Renderer::loadTexture(const char* filepath){
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(renderer, filepath);

    if (texture == nullptr){
        std::cout << "Failed to load  texture: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void Renderer::renderEntity(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect){
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}

SDL_Renderer* Renderer::getRenderer(){
    return renderer;
}

void Renderer::clear(){
    SDL_RenderClear(renderer);
}

void Renderer::display(){
    SDL_RenderPresent(renderer);
}

void Renderer::cleanUp(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
