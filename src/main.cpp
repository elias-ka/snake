#include "game.h"
#include "window.h"

int main(int argc, char *argv[]) {
    constexpr int windowWidth = 640;
    constexpr int windowHeight = 640;
    constexpr int gridWidth = 16;
    constexpr int gridHeight = 16;

    Window window(windowWidth, windowHeight, gridWidth, gridHeight);
    Game game(gridWidth, gridHeight, window);
    game.run();

    return 0;
}
