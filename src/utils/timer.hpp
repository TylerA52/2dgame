#pragma once
#include <SDL2/SDL.h>

class Timer {

public:
    Timer();
    void start();
    void pause();
    void resume();
    void stop();
    Uint32 getTime() const;
    bool isRunning() const;
    bool isPaused() const;

private:
    Uint32 startTime;
    Uint32 pausedTime;
    Uint32 totalPassed;

    bool running;
    bool paused;
};
