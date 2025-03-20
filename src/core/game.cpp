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
    Entity entity1(renderer.getRenderer(), "/home/tyler/Desktop/2dgame/assets/images/characters.png", 16, 64, 200, 200);
    Entity entity2(renderer.getRenderer(), "/home/tyler/Desktop/2dgame/assets/images/characters.png", 16, 64, 300, 200);

    Input input;

    while (isRunning) {
        input.update();

        if (input.isQuit()){
            isRunning = false;
        }
        player.update(input);
        renderer.clear();
        renderer.renderEntity(player.getSprite(), player.getSrcRect(), player.getDstRect());
        renderer.renderEntity(entity1.getSprite(), entity1.getSrcRect(), entity1.getDstRect());
        renderer.renderEntity(entity2.getSprite(), entity2.getSrcRect(), entity2.getDstRect());
        renderer.display();

        SDL_Delay(16);
    }
    
    renderer.cleanUp();
    SDL_Quit();
}
