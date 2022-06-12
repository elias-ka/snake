#include "window.h"
#include <iostream>


Window::Window(int window_w, int window_h, int grid_w, int grid_h)
        : windowWidth(window_w),
          windowHeight(window_h),
          gridWidth(grid_w),
          gridHeight(grid_h) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL\n" << "SDL_Error: " << SDL_GetError() << '\n';
    }

    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight,
                              SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        std::cerr << "Could not create window\n" << "SDL_Error: " << SDL_GetError() << '\n';
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Could not create renderer\n" << "SDL_Error: " << SDL_GetError() << '\n';
    }

}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::render(const Snake &snake, const SDL_Point &food) const {
    SDL_Rect tile;
    tile.w = windowWidth / gridWidth;
    tile.h = windowHeight / gridHeight;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    tile.x = food.x * tile.w;
    tile.y = food.y * tile.h;
    SDL_RenderFillRect(renderer, &tile);

    tile.x = static_cast<int>(snake.head.x) * tile.w;
    tile.y = static_cast<int>(snake.head.y) * tile.h;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &tile);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (const auto &bodyTile: snake.body) {
        tile.x = bodyTile.x * tile.w;
        tile.y = bodyTile.y * tile.h;
        SDL_RenderFillRect(renderer, &tile);
    }

    SDL_RenderPresent(renderer);
}