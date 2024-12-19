#include "input.hpp"

Input::Input()
    : quitRequest(false), keyState(nullptr){
    keyState = SDL_GetKeyboardState(nullptr);
}

Input::~Input(){

}
void Input::update(){
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_QUIT:
                quitRequest = true;
                break;
            default:
                break;
        }
    }
}

bool Input::isQuit() const {
    return quitRequest;
}

bool Input::isKeyPressed(SDL_Scancode key) const {
    return keyState[key] != 0;
}


