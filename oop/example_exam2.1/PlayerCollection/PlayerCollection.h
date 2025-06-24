#ifndef PLAYERCOLLECTION_H
#define PLAYERCOLLECTION_H
#include "../DynamicArray/DynamicArray.h"
#include "../Player/Player.h"
#include <cstring>

class PlayerCollection {
    DynamicArray<Player> m_players;
    void check_unique_player(const Player& other)
    {
        for (size_t i = 0; i < m_players.size(); ++i)
        {
            if (other == m_players[i])
                throw std::invalid_argument("Cannot have more than 1 player with the same name");
        }
    }
    size_t get_player_idx_by_name(const char* name)
    {
        for (size_t i = 0; i < m_players.size(); ++i)
        {
            if (strcmp(name, m_players[i].name()) == 0) return i;
        }
        throw std::invalid_argument("Player not found");
    }

public:
    PlayerCollection() = default;
    explicit PlayerCollection(const DynamicArray<Player>& other);
    PlayerCollection(const PlayerCollection& other);
    PlayerCollection(PlayerCollection&& other) noexcept;

    PlayerCollection& operator=(const PlayerCollection& other);
    PlayerCollection& operator=(PlayerCollection&& other) noexcept;

    void add_player(const Player& player)
    {
        check_unique_player(player);
        m_players.push_back(player);
    }

    [[nodiscard]] const Player& operator[](size_t idx)
    {
        return m_players[idx];
    }

    [[nodiscard]] size_t size() const noexcept
    {
        return m_players.size();
    }

    void remove_player_by_name(const char* player_to_remove)
    {
        m_players.pop_at(get_player_idx_by_name(player_to_remove));
    }
};



#endif //PLAYERCOLLECTION_H
