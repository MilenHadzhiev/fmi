#ifndef PLAYER_H
#define PLAYER_H
#include "../Position/Position.h"
#include <cstdint>

enum Weapon
{
    Sword,
    Wand,
    Staff,
    Axe
};

class Player {
protected:
    char* m_name = nullptr;
    size_t m_health = 0;
    Position m_position;
    Weapon m_weapon = Sword;
    unsigned int m_attack = 0;
public:
    Player() = default;
    Player(const char* name, size_t health, Position position, Weapon weapon, unsigned int attack);
    Player(const Player& other);
    Player(Player&& other) noexcept;

    virtual ~Player();

    Player& operator=(const Player& other);
    Player& operator=(Player&& other) noexcept;

    bool operator==(const Player& other) const;

    size_t health() const noexcept { return m_health; }
    virtual void handle_attack(size_t damage);
    [[nodiscard]] virtual size_t attack(const Player& enemy) const noexcept = 0;

    virtual void move(Position new_position) noexcept;
    [[nodiscard]] const Position& position() const noexcept;

    [[nodiscard]] const char* name() const noexcept;


    [[nodiscard]] virtual const char* type() const noexcept = 0;
    virtual void print();
};

#endif //PLAYER_H
