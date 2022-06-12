#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H


#include "snake.h"

class Controller {
public:
    static void handleInput(bool &running, Snake &snake);

private:
    static void turnSnake(Snake &snake, Snake::Direction direction, Snake::Direction opposite);
};


#endif //SNAKE_CONTROLLER_H
