#ifndef MAGE_H
#define MAGE_H
#include "../Player/Player.h"


class Mage : public Player {
    char* m_special_skill = nullptr;
    float m_coeff = 0;
public:
    Mage() = default;

    Mage(
        const char* name,
        size_t health,
        Position position,
        Weapon weapon,
        unsigned int attack,
        const char* special_skill,
        float coeff);

    Mage(const Mage& other);
    Mage(Mage&& other) noexcept;

    Mage& operator=(const Mage& other);
    Mage& operator=(Mage&& other) noexcept;

    [[nodiscard]] size_t attack(const Player& enemy) const noexcept override;

    [[nodiscard]] const char* type() const noexcept override;
};



#endif //MAGE_H