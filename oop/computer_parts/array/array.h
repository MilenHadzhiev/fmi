#ifndef ARRAY_H
#define ARRAY_H
#include <cstring>
#include <initializer_list>
#include <stdexcept>

template <typename T>
class Array
{
    T* m_data;
    size_t m_available;
    size_t m_used;

    void allocate_additional_memory()
    {
        size_t new_capacity = m_available * 2;
        T* buffer = new T[new_capacity];
        
        std::copy(m_data, m_data + m_used, buffer);
        delete[] m_data;
        m_data = buffer;
        m_available = new_capacity;
    }
public:
    Array() : m_data(nullptr), m_available(0), m_used(0) {}

    Array(T* data, size_t data_size)  : m_available(data_size * 2), m_used(data_size)
    {
        if (data == nullptr) throw std::invalid_argument("Cannot instantiate array with nullptr");
        if (data_size <= 0) throw std::invalid_argument("Cannot instantiate an array with non-positive size");
        m_data = new T[m_available];
        std::copy(m_data, data, m_used);
    }

    Array(std::initializer_list<T> data) : m_available(data.size() * 2), m_used(data.size())
    {
        m_data = new T[m_available];
        std::copy(data.begin(), data.end(), data);
    }

    Array(const Array& other) : Array(other.m_data, other.m_used) {}

    Array(Array&& other) noexcept : m_data(other.m_data), m_available(other.m_available), m_used(other.m_used)
    {
        other.m_data = nullptr;
        other.m_available = 0;
        other.m_used = 0;
    }

    ~Array()
    {
        delete[] m_data;
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] m_data;
            m_available = other.m_available;
            m_used = other.m_used;
            m_data = new T[m_available];
            std::copy(m_data, other.m_data, m_used);
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept
    {
        if (this != &other)
        {
            delete[] m_data;
            m_data = other.m_data;
            m_used = other.m_used;
            m_available = other.m_available;
            other.m_data = nullptr;
            other.m_available = 0;
            other.m_used = 0;
        }
        return *this;
    }

    bool operator==(const Array& other) const
    {
        if (m_used != other.m_used) return false;
        if (m_data == nullptr || other.m_data == nullptr) return false;

        for (size_t i = 0; i < m_used; ++i)
        {
            if (m_data[i] != other.m_data[i]) return false;
        }
        return true;
    }

    bool operator!=(const Array& other) const
    {
        return !(*this == other);
    }

    const T& operator[](unsigned long idx) const
    {
        if (!m_data) throw std::runtime_error("Can't index nullptr");

        if (idx >= m_used) throw std::invalid_argument("Index out of range");

        return m_data[idx];
    }

    void push_back(const T& element)
    {
        if (!m_data) throw std::invalid_argument("Can't index nullptr");

        if (m_used + 1 >= m_available) allocate_additional_memory();

        m_data[m_used++] = element;
    }

    const T& pop_back()
    {
        if (!m_data) throw std::invalid_argument("Can't pop from nullptr");

        return m_data[--m_used];
    }
};

#endif //DYNAMICARRAY_H
