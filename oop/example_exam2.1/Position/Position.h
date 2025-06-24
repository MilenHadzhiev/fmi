#ifndef STRUCT_H
#define STRUCT_H

struct Position
{
    float x = 0;
    float y = 0;

    Position() = default;
    Position(const int x_, const int y_) : x(x_), y(y_) {}
    Position(const Position& other) = default;
    Position(Position&& other) = default;

    Position& operator=(const Position& other) = default;
    Position& operator=(Position&& other) = default;

    bool operator==(const Position&) const = default;
};
#endif //STRUCT_H
