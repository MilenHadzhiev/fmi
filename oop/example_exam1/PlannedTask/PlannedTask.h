#ifndef PLANNEDTASK_H
#define PLANNEDTASK_H
#include "../Task/Task.h"

class PlannedTask {
    Task m_task;
    uint8_t start_hour;
    uint8_t start_minutes;
public:

    PlannedTask();
    PlannedTask(const Task& task, uint8_t start_hour, uint8_t start_minutes);
    PlannedTask(const PlannedTask& other);
    PlannedTask(PlannedTask&& other) noexcept;
    ~PlannedTask() = default;

    inline const char* get_description() const;
    inline uint8_t get_priority() const;
    inline bool is_completed() const;
    inline float get_duration() const;

    PlannedTask& operator=(const PlannedTask& other);
    PlannedTask& operator=(PlannedTask&& other) noexcept;
};



#endif //PLANNEDTASK_H
