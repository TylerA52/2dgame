#include "timer.hpp"
#include <iostream>
#include <SDL2/SDL.h>

Timer::Timer()
    : startTime(0), pausedTime(0), totalPassed(0), running(false), paused(false) {}

void Timer::start() {
    running = true;
    paused = false;
    totalPassed = 0;
    startTime = SDL_GetTicks();
}

void Timer::pause(){
    if (running && !paused) {
        paused = true;
        pausedTime = SDL_GetTicks();
    }
}

void Timer::resume() {
    if (paused) {
        paused = false;
        totalPassed += SDL_GetTicks() - pausedTime;
    }
}

void Timer::stop() {
    running = false;
    paused = false;
    totalPassed = 0;
}

Uint32 Timer::getTime() const {
    if (running){
        if (paused) {
            return pausedTime - startTime;
        } else {
            return SDL_GetTicks() - startTime + totalPassed;
        }
    }
    return 0;
}

bool Timer::isRunning() const {
    return running;
}
bool Timer::isPaused() const {
    return paused;
}
