#ifndef SNAKE_WINDOW_H
#define SNAKE_WINDOW_H

#include <memory>
#include <SDL.h>
#include "snake.h"


class Window {
public:
    Window(int window_w, int window_h, int grid_w, int grid_h);

    ~Window();

    void render(const Snake &snake, const SDL_Point &food) const;

    SDL_Window *getWindow() { return window; }

private:
    SDL_Window *window{nullptr};
    SDL_Renderer *renderer{nullptr};

    int windowWidth;
    int windowHeight;
    int gridWidth;
    int gridHeight;
};


#endif //SNAKE_WINDOW_H
