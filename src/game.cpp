#include "game.h"
#include "controller.h"
#include "window.h"
#include <string>

Game::Game(int grid_w, int grid_h, const Window &window)
        : snake(grid_w, grid_h),
          gen(rd()),
          rand_w(0, grid_w - 1),
          rand_h(0, grid_h - 1),
          window(window) {

    spawnFood();
}


void Game::run() {
    while (running) {
        Controller::handleInput(running, snake);
        window.render(snake, food);
        update();
        SDL_Delay(200);
    }
}

void Game::spawnFood() {
    SDL_Point point;
    while (true) {
        point.x = rand_w(gen);
        point.y = rand_h(gen);

        if (!snake.collidesWith(point)) {
            food.x = point.x;
            food.y = point.y;
            break;
        }
    }

}

void Game::update() {
    updateWindowTitle();
    snake.update();

    if (static_cast<int>(snake.head.x) == food.x && static_cast<int>(snake.head.y) == food.y) {
        spawnFood();
        snake.grow();
    }
}

void Game::updateWindowTitle() {
    auto score = std::to_string(snake.getScore());
    const std::string title{"Snake - Score: " + score};
    const std::string deadTitle{"Snake - Score: " + score + " - Game Over!"};
    if (!snake.alive) {
        SDL_SetWindowTitle(window.getWindow(), deadTitle.c_str());
    } else {
        SDL_SetWindowTitle(window.getWindow(), title.c_str());
    }
}



