#pragma once
#include "../graphics/renderer.hpp"
#include "../entities/player.hpp"
#include "../input/input.hpp"

class Game {

public:
    Game();
    bool init();
    void run();
private:
    Renderer renderer;
    //Input input;
    //Player player;
    
    bool isRunning;
};
