#ifndef WARRIOR_H
#define WARRIOR_H
#include "../Player/Player.h"

class Warrior : public Player {
    unsigned int m_armor = 0;
public:
    Warrior() = default;

    Warrior(const char* name, size_t health, Position position, Weapon weapon, unsigned int attack, unsigned int armor);

    Warrior(const Warrior& other) = default;

    Warrior(Warrior&& other) = default;

    Warrior& operator=(const Warrior& other) = default;
    Warrior& operator=(Warrior&& other) noexcept = default;

    size_t attack(const Player& enemy) const override;
    void handle_attack(size_t damage) override;

    [[nodiscard]] virtual const char* type() const noexcept override;
};



#endif //WARRIOR_H
