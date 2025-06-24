#include "Warrior.h"

Warrior::Warrior(const char* name, size_t health, Position position, Weapon weapon, unsigned int attack, unsigned int armor)
    : Player(name, health, position, weapon, attack), m_armor(armor) {}

size_t Warrior::attack(const Player& enemy) const
{
    return m_attack;
}

void Warrior::handle_attack(size_t damage)
{
    if (m_armor - damage < 0)
    {
        m_health -= (damage - m_armor);
        m_armor = 0;
        return;
    }
    m_armor -= damage;
}

const char* Warrior::type() const noexcept
{
    return "Warrior";
}
