#include <algorithm>
#include <SDL.h>
#include "snake.h"

void Snake::update() {
    SDL_Point prevTile{static_cast<int>(head.x), static_cast<int>(head.y)};
    updateHeadPos();
    SDL_Point currTile{static_cast<int>(head.x), static_cast<int>(head.y)};

    if (currTile.x != prevTile.x || currTile.y != prevTile.y) {
        updateBodyPos(currTile, prevTile);
    }
}

void Snake::updateHeadPos() {
    switch (direction) {
        case Direction::UP:
            head.y -= speed;
            break;
        case Direction::DOWN:
            head.y += speed;
            break;
        case Direction::LEFT:
            head.x -= speed;
            break;
        case Direction::RIGHT:
            head.x += speed;
            break;
    }
}

void Snake::updateBodyPos(SDL_Point &currHeadTile, SDL_Point &prevHeadTile) {
    body.push_back(prevHeadTile);

    if (growing) {
        growing = false;
        size++;
        score += 10;
    } else {
        body.erase(body.begin());
    }

    if (std::any_of(body.begin(), body.end(),
                    [&](SDL_Point bodyTile) { return currHeadTile.x == bodyTile.x && currHeadTile.y == bodyTile.y; })) {
        alive = false;
    }
}

bool Snake::collidesWith(const SDL_Point &point) const {
    if (point.x == static_cast<int>(head.x) && point.y == static_cast<int>(head.y)) {
        return true;
    }

    if (std::any_of(body.begin(), body.end(),
                    [&](SDL_Point bodyTile) { return point.x == bodyTile.x && point.y == bodyTile.y; })) {
        return true;
    }

    return false;
}

void Snake::grow() {
    growing = true;
}

