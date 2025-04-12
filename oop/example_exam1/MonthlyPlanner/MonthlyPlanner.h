#ifndef MONTHLYPLANNER_H
#define MONTHLYPLANNER_H
#include "../PlannedTask/PlannedTask.h"

enum Month
{
    Jan, Feb, Mar, Apr, May, June, July, Aug, Sep, Oct, Nov, Dec
};

class MonthlyPlanner {
    PlannedTask* m_tasks;
    size_t m_tasks_count;
    size_t m_available_space;
    Month m_month;
    bool can_add_task(const PlannedTask& task, uint8_t day, uint8_t hour, uint8_t minutes) const;
    bool task_overlaps_with_more_important_one(const PlannedTask& task) const;

public:
    static bool is_valid_day(Month month, uint8_t day);

    MonthlyPlanner();
    MonthlyPlanner(const MonthlyPlanner& other);
    MonthlyPlanner(MonthlyPlanner&& other) noexcept;
    MonthlyPlanner(std::istream& stream);
    ~MonthlyPlanner();

    MonthlyPlanner& operator=(const MonthlyPlanner& other);
    MonthlyPlanner& operator=(MonthlyPlanner&& other);

    void add_task(const PlannedTask& task, uint8_t day, uint8_t start_hour, uint8_t start_minutes);

    void complete_task(uint8_t hour, uint8_t minutes);

    void save_to_stream(std::ostream& os);
};

#endif //MONTHLYPLANNER_H
