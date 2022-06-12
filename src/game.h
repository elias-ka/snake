#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <memory>
#include <random>
#include "window.h"
#include "snake.h"

class Game {
public:
    Game(int grid_w, int grid_h, const Window &window);

    void run();
    void spawnFood();
    void update();
    void updateWindowTitle();

private:
    Snake snake;
    Window window;
    SDL_Point food{};
    bool running{true};

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> rand_w;
    std::uniform_int_distribution<int> rand_h;

};


#endif //SNAKE_GAME_H
