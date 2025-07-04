#include "Report.h"

Report::Report() : Article(), m_reporter(Author()), m_id{}, m_duration(0) {}

Report::Report(const DynamicArray<Author>& authors, const char* title, const Author& reporter, const char id[5], uint8_t duration)
    : Article(authors, title), m_reporter(reporter), m_id{},  m_duration(duration)
{
    strcpy(m_id, id);
}

Report::Report(const Report& other) : Article(other), m_reporter(other.m_reporter), m_id{}, m_duration(other.m_duration)
{
    strcpy(m_id, other.m_id);
}

Report::Report(Report&& other) noexcept : Article(std::move(other)), m_reporter(other.m_reporter), m_id{}, m_duration(other.m_duration)
{
    strcpy(m_id, other.m_id);
    other.m_id = {};

    other.m_duration = 0;
}

Report& Report::operator=(const Report& other)
{
    if (this != &other)
    {

    }
}
