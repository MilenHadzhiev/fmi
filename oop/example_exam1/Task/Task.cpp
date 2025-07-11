#include "Task.h"
#include <cstring>

const uint8_t Task::MAX_PRIORITY = 100;

Task::Task() : m_description(nullptr), m_duration(0), m_priority(0), m_is_completed(false) {}

Task::Task(const char* description) : m_duration(0), m_priority(0), m_is_completed(false)
{
    m_description = new char[strlen(description) + 1];
    strcpy(m_description, description);
}

Task::Task(const char* description, uint8_t priority, float duration) : m_duration(duration), m_priority(priority), m_is_completed(false)
{
    if (duration < 0) throw std::invalid_argument("duration must be a positive number");

    m_description = new char[strlen(description) + 1];
    strcpy(m_description, description);
}

Task::Task(std::ifstream& istream)
{
    if (istream.is_open() && istream.good())
    {
        const short buffer_size = 1024;
        char buffer[buffer_size];

        istream.getline(buffer, buffer_size, ',');
        m_description = new char[strlen(buffer) + 1];
        strcpy(m_description, buffer);
        try
        {
            istream.getline(buffer, buffer_size, ',');
            m_duration = std::stof(buffer);

            istream.getline(buffer, buffer_size, ',');
            m_priority = std::stoi(buffer);

            istream.getline(buffer, buffer_size);
            if (buffer[0] != '0' && buffer[0] != '1') throw std::invalid_argument("Value for is_completed must be within {0, 1}");
            m_is_completed = buffer[0] == '1';
        } catch (std::exception& e)
        {
            delete[] m_description;
            throw e;
        }
    }
    throw std::runtime_error("Stream is not open or is in invalid state");
}

Task::Task(const Task& other) : m_duration(other.m_duration), m_priority(other.m_priority), m_is_completed(other.m_is_completed)
{
    m_description = new char[strlen(other.m_description) + 1];
    strcpy(m_description, other.m_description);
}

Task::Task(Task&& other) noexcept : m_description(other.m_description), m_duration(other.m_duration), m_priority(other.m_priority),
m_is_completed(other.m_is_completed)
{
    other.m_description = nullptr;
    other.m_duration = 0;
    other.m_priority = 0;
    other.m_is_completed = false;
}

Task::~Task()
{
    delete[] m_description;
}

Task& Task::operator=(const Task& other)
{
    if (this != &other)
    {
        char* buffer = new char[strlen(other.m_description) + 1];
        strcpy(buffer, other.m_description);
        delete[] m_description;
        m_description = buffer;
        m_duration = other.m_duration;
        m_priority = other.m_priority;
        m_is_completed = other.m_is_completed;
    }
    return *this;
}

Task& Task::operator=(Task&& other) noexcept
{
    if (this != &other)
    {
        delete[] m_description;
        m_description = other.m_description;
        other.m_description = nullptr;

        m_duration = other.m_duration;
        other.m_duration = 0;

        m_priority = other.m_priority;
        other.m_priority = 0;

        m_is_completed = other.m_is_completed;
        other.m_is_completed = false;
    }
    return *this;
}


std::ostream& Task::operator<<(std::ostream& ostream) const
{
    if (ostream.good())
    {
        ostream << m_description << ',' << m_duration << ',' << m_priority << ',' << (m_is_completed ? 1 : 0);
        return ostream;
    }
    throw std::runtime_error("Output stream is not in good state");
}


const char* Task::get_description() const
{
    return m_description;
}

float Task::get_duration() const
{
    return m_duration;
}

uint8_t Task::get_priority() const
{
    return m_priority;
}

bool Task::is_completed() const
{
    return m_is_completed;
}

bool Task::operator>=(const Task& other) const
{
    if (m_priority == other.m_priority) return m_duration >= other.m_duration;
    return m_priority >= other.m_priority;
}

bool Task::operator>(const Task& other) const
{
    if (m_priority == other.m_priority) return m_duration > other.m_duration;
    return m_priority > other.m_priority;
}

bool Task::operator<(const Task& other) const
{
    if (m_priority == other.m_priority) return m_duration < other.m_duration;
    return m_priority < other.m_priority;
}

bool Task::operator<=(const Task& other) const
{
    if (m_priority == other.m_priority) return m_duration <= other.m_duration;
    return m_priority <= other.m_priority;
}

void Task::complete()
{
    m_is_completed = true;
}

void Task::set_duration(float new_duration)
{
    if (new_duration < 0) throw std::invalid_argument("Duration must be a positive number");
    m_duration = new_duration;;
}

void Task::set_priority(uint8_t new_priority)
{
    m_priority = new_priority;
}


