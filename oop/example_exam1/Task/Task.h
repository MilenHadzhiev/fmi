#ifndef TASK_H
#define TASK_H
#include <cstdint>
#include <fstream>


class Task {
    char* m_description;
    float m_duration; // minutes
    uint8_t m_priority;
    bool m_is_completed;
public:
    static const uint8_t MAX_PRIORITY;

    Task();
    Task(const char* description);
    Task(std::ifstream& istream);
    Task(const char* description, uint8_t priority, float duration);
    Task(const Task& other);
    Task(Task&& other) noexcept;

    ~Task();

    Task& operator=(const Task& other);
    Task& operator=(Task&& other) noexcept;

    std::ostream& operator<<(std::ostream& ostream) const;

    const char* get_description() const;
    uint8_t get_priority() const;
    bool is_completed() const;
    float get_duration() const;

    bool operator>(const Task& other) const;
    bool operator>=(const Task& other) const;
    bool operator<=(const Task& other) const;
    bool operator<(const Task& other) const;

    void complete();
    void set_duration(float new_duration);
    void set_priority(uint8_t new_priority);
};

#endif //TASK_H
