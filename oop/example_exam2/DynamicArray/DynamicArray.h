#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdexcept>

template <typename T>
class DynamicArray {
    T* m_data;
    size_t m_available;
    size_t m_used;

    void allocate_more_memory()
    {
        if (m_available <= 0)
        {
            m_available = 2;
            m_data = new T[2];
            m_used = 0;
            return;
        }
        T* buffer = new T[m_available * 2];

        copy_array(buffer, m_data, m_used);

        delete[] m_data;

        m_available *= 2;
        m_data = buffer;
    }

    static void copy_array(const T* src, T* dest, size_t size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            dest[i] = src[i];
        }
    }
public:
    DynamicArray() : m_data(new T[2]), m_available(2), m_used(0) {}

    DynamicArray(T* data, size_t length) : m_data(new T[length * 2]), m_available(length * 2), m_used(length)
    {
        copy_array(data, m_data, length);
    }

    DynamicArray(const DynamicArray& other) : m_data(new T[other.m_available]), m_available(other.m_available), m_used(other.m_used)
    {
        copy_array(other.m_data, m_data, other.m_used);
    }

    DynamicArray(DynamicArray&& other) noexcept : m_data(other.m_data), m_available(other.m_available), m_used(other.m_used)
    {
        other.m_used = nullptr;
        other.m_available = 0;
        other.m_used = 0;
    }

    ~DynamicArray()
    {
        delete[] m_data;
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other)
        {
            T* buffer = new T[other.m_available];

            copy_array(buffer, other.m_data, other.m_used);

            delete[] m_data;

            m_data = buffer;
            m_available = other.m_available;
            m_used = other.m_used;
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept
    {
        if (this != &other)
        {
            delete[] m_data;

            m_data = other.m_data;
            other.m_data = nullptr;

            m_available = other.m_available;
            other.m_available = 0;

            m_used = other.m_used;
            other.m_used = 0;
        }
        return *this;
    }

    void push_back(const T& element)
    {
        if (m_used + 1 >= m_available) allocate_more_memory();

        m_data[m_used++] = element;
    }

    void pop()
    {
        pop_at(m_used - 1);
    }

    void pop_at(size_t idx)
    {
        if (idx >= m_used) throw std::invalid_argument("Index out of range");

        for (size_t i = idx; i < m_used - 1; ++i)
        {
            m_data[i] = m_data[i + 1];
        }
        m_used--;
    }

    T& operator[](size_t idx)
    {
        if (idx >= m_used) throw std::invalid_argument("Index out of range");

        return m_data[idx];
    }

    [[nodiscard]] size_t size() const noexcept
    {
        return m_used;
    }
};


#endif //DYNAMICARRAY_H
