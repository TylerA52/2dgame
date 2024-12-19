#include <iostream>
#include "graphics/renderer.hpp"
#include "input/input.hpp"
#include "game.hpp"

Game::Game()
    : renderer("GAME", 800, 600){

}

bool Game::init() {
    /**if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL Init Failed..." << SDL_GetError() << std::endl;
        return false;
    }**/
    
    isRunning = true;
    return true;
}

void Game::run() {
    Renderer window("GAME", 800, 600);

    Input inputManager;

    while (isRunning) {
        inputManager.update();

        if (inputManager.isQuit()){
            isRunning = false;
        }
        if (inputManager.isKeyPressed(SDL_SCANCODE_W)){
            std::cout << "w" << std::endl;
        }
        //player.update();
        renderer.clear();
        //map.render(renderer);
        //player.render(renderer);
        renderer.display();

        SDL_Delay(16);
    }
    renderer.cleanUp();
    SDL_Quit();
}
