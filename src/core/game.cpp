#include <iostream>
#include "graphics/renderer.hpp"
#include "graphics/textbox.hpp"
#include "entities/player.hpp"
#include "entities/entity.hpp"
#include "input/input.hpp"
#include "utils/timer.hpp"
#include "game.hpp"

Game::Game()
    : renderer("GAME", 800, 600){

}

bool Game::init() {
    isRunning = true;
    return true;
}

void Game::run() {
    Player player(renderer.getRenderer(), "/home/tyler/Desktop/2dgame/assets/images/characters.png");
    Input input;

    while (isRunning) {
        input.update();

        if (input.isQuit()){
            isRunning = false;
        }
        player.update(input);
        renderer.clear();
        renderer.renderEntity(player.getSprite(), player.getSrcRect(), player.getDstRect());
        renderer.display();

        SDL_Delay(16);
    }
    
    renderer.cleanUp();
    SDL_Quit();
}
