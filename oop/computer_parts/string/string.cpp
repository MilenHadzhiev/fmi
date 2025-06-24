#include "string.h"

#include <cstring>
#include <stdexcept>

#include "../utilities/utilities.h"

String::String() : m_data(nullptr), m_size(0) {}

String::String(const char* str) : m_data(copy_string(str)), m_size(strlen(str))
{
    m_data[m_size] = '\0';
}

String::String(const String& other) : m_data(copy_string(other.m_data)), m_size(other.m_size) {}

String::String(String&& other) noexcept : m_data(other.m_data), m_size(other.m_size)
{
    other.m_data = nullptr;
    other.m_size = 0;
}

String::~String()
{
    delete[] m_data;
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        char* copy = copy_string(other.m_data);
        delete[] m_data;
        m_data = copy;
        m_size = other.m_size;
    }
    return *this;
}

String& String::operator=(const char* other)
{
    if (strcmp(m_data, other) != 0)
    {
        char* copy = copy_string(other);
        delete[] m_data;
        m_size = strlen(other);
        m_data = copy;
    }
    return *this;
}


String& String::operator=(String&& other) noexcept
{
    if (this != &other)
    {
        delete[] m_data;
        m_data = other.m_data;
        m_size = other.m_size;
        other.m_data = nullptr;
        other.m_size = 0;
    }
    return *this;
}

bool String::operator==(const String& other) const noexcept
{
    return m_size == other.m_size && strcmp(m_data, other.m_data) == 0;
}

bool String::operator==(const char* other) const noexcept
{
    return strcmp(m_data, other) == 0;
}

bool String::operator!=(const char* other) const noexcept
{
    return !(*this == other);
}


bool String::operator!=(const String& other) const noexcept
{
    return !(*this == other);
}

char String::operator[](unsigned int idx) const
{
    if (idx >= m_size) throw std::invalid_argument("Index out of range");
    return m_data[idx];
}


const char* String::c_str() const noexcept
{
    return m_data;
}
