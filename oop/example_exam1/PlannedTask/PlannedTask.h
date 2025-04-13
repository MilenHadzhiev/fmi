#ifndef PLANNEDTASK_H
#define PLANNEDTASK_H
#include "../Task/Task.h"

class PlannedTask {
    Task m_task;
    uint8_t m_day;
    uint8_t m_start_hour;
    uint8_t m_start_minutes;
public:

    PlannedTask() = default;
    PlannedTask(const Task& task, uint8_t day, uint8_t start_hour, uint8_t start_minutes);
    PlannedTask(const PlannedTask& other);
    PlannedTask(PlannedTask&& other) noexcept;
    ~PlannedTask() = default;

    PlannedTask& operator=(const PlannedTask& other);
    PlannedTask& operator=(PlannedTask&& other) noexcept;

    const char* get_description() const;
    uint8_t get_priority() const;
    bool is_completed() const;
    float get_duration() const;
    uint8_t get_day() const;
    uint8_t get_start_hour() const;
    uint8_t get_start_minutes() const;
    const Task& get_task() const;

    void complete();
};



#endif //PLANNEDTASK_H
