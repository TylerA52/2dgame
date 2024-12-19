#include <iostream>
#include "graphics/renderer.hpp"
#include "game.hpp"

Game::Game()
    : renderer("GAME", 800, 600){

}

bool Game::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL Init Failed..." << std::endl;
        return false;
    }

    Renderer window("GAME", 800, 600);
    //inputManager.init();
    
    isRunning = true;
    return true;
}

void Game::run() {
    while (isRunning) {
        //inputManager.processInput();
        //player.update();
        renderer.clear();
        //map.render(renderer);
        //player.render(renderer);
        renderer.display();

        SDL_Delay(16);
    }
}
