#pragma once
#include <SDL2/SDL.h>

class Input {

public:
    Input();
    ~Input();
    
    void update();
    bool isQuit() const;
    bool isKeyPressed(SDL_Scancode key) const;
private:
    bool quitRequest;
    const Uint8* keyState;
};
