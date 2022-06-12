#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <vector>

class Snake {
public:
    Snake(int grid_w, int grid_h)
            : gridWidth(grid_w),
              gridHeight(grid_h),
              head{static_cast<float>(grid_w / 2.0), static_cast<float>(grid_h / 2.0)} {}

    void update();

    void updateHeadPos();

    void updateBodyPos(SDL_Point &currHeadTile, SDL_Point &prevHeadTile);

    [[nodiscard]] bool collidesWith(const SDL_Point &point) const;

    void grow();

    [[nodiscard]] int getScore() const { return score; }

    enum class Direction {
        UP, DOWN, LEFT, RIGHT
    };

    bool alive{true};
    int size{1};
    float speed{1.0f};
    Direction direction = Direction::UP;
    struct Head {
        float x;
        float y;
    } head;

    std::vector<SDL_Point> body;

private:
    int gridWidth;
    int gridHeight;
    bool growing{false};
    int score{0};
};


#endif //SNAKE_SNAKE_H
