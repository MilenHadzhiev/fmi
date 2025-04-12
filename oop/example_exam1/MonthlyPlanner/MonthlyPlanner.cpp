#include "MonthlyPlanner.h"

void MonthlyPlanner::allocate_more_memory()
{
    PlannedTask* buffer = new PlannedTask[m_available_space * 2];
    for (size_t i = 0; i < m_tasks_count; ++i) buffer[i] = m_tasks[i];

    delete[] m_tasks;
    m_tasks = buffer;
    m_available_space *= 2;
}

bool MonthlyPlanner::is_valid_day(Month month, uint8_t day)
{
    if ((month == Jan || month == Mar || month == May || month == July || month == Aug || month == Oct || month == Dec) && day > 31)
        return false;

    if (month == Feb && day > 28) return false; // for the purposes of the test no leap years

    if ((month == Apr || month == June || month == Sep || month == Nov) && day > 30) return false;

    return true;
}

bool MonthlyPlanner::task_overlaps_with_more_important_one(const PlannedTask& task) const
{
    //
    return false;
}


bool MonthlyPlanner::can_add_task(const PlannedTask& task, uint8_t day, uint8_t hour, uint8_t minutes) const
{
    if (!is_valid_day(m_month, day)) return false;

    if (hour > 23 || minutes > 59) return false;
    uint8_t available_time_in_the_day = (24 - hour) * 60 + (60 - minutes);
    if (task.get_duration() > available_time_in_the_day) return false;

    return !task_overlaps_with_more_important_one(task);
}

MonthlyPlanner::MonthlyPlanner() : m_tasks_count(0), m_available_space(2), m_month(Jan)
{
    m_tasks = new PlannedTask[m_available_space];
}

MonthlyPlanner::MonthlyPlanner(const MonthlyPlanner& other) : m_tasks_count(other.m_tasks_count), m_available_space(other.m_available_space),
m_month(other.m_month)
{
    m_tasks = new PlannedTask[other.m_available_space];
    for (size_t i = 0; i < other.m_tasks_count; ++i)
    {
        m_tasks[i] = other.m_tasks[i];
    }
}

MonthlyPlanner::MonthlyPlanner(MonthlyPlanner&& other) noexcept :
    m_tasks(other.m_tasks),
    m_tasks_count(other.m_tasks_count),
    m_available_space(other.m_available_space),
    m_month(other.m_month)
{
    other.m_tasks = nullptr;
    other.m_tasks_count = 0;
    other.m_available_space = 1;
    other.m_month = Jan;
}

MonthlyPlanner::~MonthlyPlanner()
{
    delete[] m_tasks;
}

MonthlyPlanner& MonthlyPlanner::operator=(const MonthlyPlanner& other)
{
    if (this != &other)
    {
        PlannedTask* buffer = new PlannedTask[other.m_available_space];
        for (size_t i = 0; i < other.m_tasks_count; ++i)
        {
            buffer[i] = other.m_tasks[i];
        }
        delete[] m_tasks;
        m_tasks = buffer;
        m_available_space = other.m_available_space;
        m_tasks = other.m_tasks;
        m_month = other.m_month;
    }
    return *this;
}

MonthlyPlanner& MonthlyPlanner::operator=(MonthlyPlanner&& other)
{
    if (this != &other)
    {
        delete[] m_tasks;
        m_tasks = other.m_tasks;
        other.m_tasks = nullptr;

        m_available_space = other.m_available_space;
        other.m_available_space = 1;

        m_tasks_count = other.m_tasks_count;
        other.m_tasks_count = 0;

        m_month = other.m_month;
        other.m_month = Jan;
    }
    return *this;
}

void MonthlyPlanner::add_task(const PlannedTask& task, uint8_t day, uint8_t start_hour, uint8_t start_minutes)
{
    if (!can_add_task(task, day, start_hour, start_minutes)) throw std::invalid_argument("Task must be finishable within the day of start.");

    if (m_tasks_count + 1 >= m_available_space)
    {
        allocate_more_memory();
    }
    m_tasks[m_tasks_count++] = task;
}

void MonthlyPlanner::complete_task(uint8_t day, uint8_t hour)
{
    if (!is_valid_day(m_month, day) || hour >= 24) throw std::invalid_argument("Invalid day/hour");

    for (size_t i = 0; i < m_tasks_count; ++i)
    {
        if (m_tasks[i].get_day() == day && m_tasks[i].get_start_hour() == hour)
        {
            m_tasks[i].complete();
            return;
        }
    }
    throw std::invalid_argument("No task scheduled");
}

