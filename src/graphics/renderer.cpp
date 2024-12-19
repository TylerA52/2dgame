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



