#include "Mage.h"


size_t Mage::attack(const Player& enemy) const noexcept
{
    return m_attack + enemy.health() * m_coeff;
}
