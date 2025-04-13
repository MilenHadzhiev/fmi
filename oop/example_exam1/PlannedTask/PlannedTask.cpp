#include "PlannedTask.h"
#include "../Task/Task.h"

PlannedTask::PlannedTask(const Task& task, uint8_t day, uint8_t start_hour, uint8_t start_minutes) :
    m_task(task),
    m_day(day),
    m_start_hour(start_hour),
    m_start_minutes(start_minutes)
{
    if (day > 31 || m_start_hour >= 24 || start_minutes >= 60) throw std::invalid_argument("Hour must be within range 0-23 and minutes must be within range 0-59");
}

PlannedTask::PlannedTask(const PlannedTask& other) = default;

PlannedTask::PlannedTask(PlannedTask&& other) noexcept = default;

PlannedTask& PlannedTask::operator=(const PlannedTask& other)
{
    if (this != &other)
    {
        m_task = other.m_task;
        m_start_hour = other.m_start_hour;
        m_start_minutes = other.m_start_minutes;
    }
    return *this;
}

PlannedTask& PlannedTask::operator=(PlannedTask&& other) noexcept
{
    if (this != &other)
    {
        m_task = other.m_task;

        m_start_hour = other.m_start_hour;
        other.m_start_hour = 0;

        m_start_minutes = other.m_start_minutes;
        other.m_start_minutes = 0;
    }
    return *this;
}

const Task& PlannedTask::get_task() const
{
    return m_task;
}

const char* PlannedTask::get_description() const
{
    return m_task.get_description();
}

float PlannedTask::get_duration() const
{
    return m_task.get_duration();
}

uint8_t PlannedTask::get_priority() const
{
    return m_task.get_priority();
}

uint8_t PlannedTask::get_start_hour() const
{
    return m_start_hour;
}

uint8_t PlannedTask::get_day() const
{
    return m_day;
}

uint8_t PlannedTask::get_start_minutes() const
{
    return m_start_minutes;
}

bool PlannedTask::is_completed() const
{
    return m_task.is_completed();
}

void PlannedTask::complete()
{
    m_task.complete();
}
