#include <SDL.h>

#include "controller.h"
#include "snake.h"

void Controller::handleInput(bool &running, Snake &snake) {
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            running = false;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                case SDLK_UP:
                    turnSnake(snake, Snake::Direction::UP, Snake::Direction::DOWN);
                    break;
                case SDLK_DOWN:
                    turnSnake(snake, Snake::Direction::DOWN, Snake::Direction::UP);
                    break;
                case SDLK_LEFT:
                    turnSnake(snake, Snake::Direction::LEFT, Snake::Direction::RIGHT);
                    break;
                case SDLK_RIGHT:
                    turnSnake(snake, Snake::Direction::RIGHT, Snake::Direction::LEFT);
                    break;
            }
        }
    }
}

void Controller::turnSnake(Snake &snake, Snake::Direction direction, Snake::Direction opposite) {
    if (snake.direction != opposite || snake.size == 1) {
        snake.direction = direction;
    }
}
