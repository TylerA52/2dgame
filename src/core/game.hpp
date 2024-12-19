#pragma once
#include "../graphics/renderer.hpp"

class Game {

public:
    Game();
    bool init();
    void run();
private:
    Renderer renderer;
    //InputManager inputManager;
    //Player player;
    
    bool isRunning;
};
