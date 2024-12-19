#pragma once
#include <SDL2/SDL.h>

class Renderer {

public:
    Renderer(const char* title, int w, int h);
    void clear();
    void cleanUp();
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
