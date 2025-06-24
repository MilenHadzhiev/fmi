#include "Player.h"
#include <cstring>
#include <iostream>

Player::Player(const char* name, size_t health, Position position, Weapon weapon, unsigned int attack)
    : m_name(new char[strlen(name) + 1]), m_health(health), m_position(position), m_weapon(weapon), m_attack(attack)
{
    strcpy(m_name, name);
}

Player::Player(const Player& other)
    : m_name(new char[strlen(other.m_name) + 1]),
      m_health(other.m_health),
      m_position(other.m_position),
      m_weapon(other.m_weapon),
      m_attack(other.m_attack)
{
    strcpy(m_name, other.m_name);
}

Player::Player(Player&& other) noexcept
    : m_name(other.m_name), m_health(other.m_health), m_position(other.m_position), m_weapon(other.m_weapon), m_attack(other.m_attack)
{
    other.m_name = nullptr;
    other.m_health = 0;
    other.m_position = Position();
    other.m_weapon = Sword;
    other.m_attack = 0;
}

Player::~Player()
{
    delete[] m_name;
}


Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        char* buffer = new char[strlen(other.m_name) + 1];
        strcpy(buffer, other.m_name);
        delete[] m_name;
        m_name = buffer;

        m_health = other.m_health;
        m_position = other.m_position;
        m_weapon = other.m_weapon;
        m_attack = other.m_attack;
    }
    return *this;
}

Player& Player::operator=(Player&& other) noexcept
{
    if (this != &other)
    {
        delete[] m_name;
        m_name = other.m_name;
        other.m_name = nullptr;

        m_health = other.m_health;
        other.m_health = 0;

        m_position = other.m_position;
        other.m_position = Position();

        m_weapon = other.m_weapon;
        other.m_weapon = Sword;

        m_attack = other.m_attack;
        other.m_attack = 0;
    }
    return *this;
}

bool Player::operator==(const Player& other) const
{
    return strcmp(other.m_name, m_name) == 0;
}

void Player::handle_attack(size_t damage)
{
    m_health -= damage;
}

void Player::move(Position new_position) noexcept
{
    m_position = new_position;
}

[[nodiscard]] const Position& Player::position() const noexcept
{
    return m_position;
}

const char* Player::name() const noexcept
{
    return m_name;
}

void Player::print()
{
    std::cout << "I am a " << type() << " and my name is " << m_name;
}
