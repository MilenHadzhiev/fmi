#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdexcept>

template <typename T>
class DynamicArray {
    T* m_data = nullptr;
    size_t m_available = 0;
    size_t m_used = 0;

    void allocate_more_memory()
    {
        if (m_data == nullptr)
        {
            m_data = new T[2];
            m_available = 2;
            return;
        }
        T* buffer = new T[m_available * 2];
        copy_array(m_data, buffer, m_used);
        delete[] m_data;
        m_data = buffer;
        m_available *= 2;
    }

    static void copy_array(const char* src, char* dest, size_t n)
    {
        for (size_t i = 0; i < n; ++i)
        {
            dest[i] = src[i];
        }
    }

    void check_index_out_of_range(size_t idx) const
    {
        if (idx >= m_used) throw std::invalid_argument("Index out of range");
    }
public:
    DynamicArray() = default;

    DynamicArray(const T* data, size_t n) : m_data(new T[n * 2]), m_available(n * 2), m_used(n)
    {
        copy_array(data, m_data, n);
    }

    DynamicArray(const DynamicArray& other) : m_data(new T[other.m_available]), m_available(other.m_available), m_used(other.m_used)
    {
        copy_array(other.m_data, m_data, other.m_used);
    }

    DynamicArray(DynamicArray&& other) noexcept : m_data(other.m_data), m_available(other.m_available), m_used(other.m_used)
    {
        other.m_data = nullptr;
        other.m_available = 0;
        other.m_used = 0;
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other)
        {
            T* buffer = new T[other.m_available];
            copy_array(other.m_data, buffer, other.m_used);

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

    virtual ~DynamicArray()
    {
        delete[] m_data;
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
        check_index_out_of_range(idx);

        for (size_t i = idx; i < m_used - 1; ++i)
        {
            m_data[i] = m_data[i + 1];
        }
    }

    const T& operator[](size_t idx)
    {
        check_index_out_of_range(idx);

        return m_data[idx];
    }

    [[nodiscard]] size_t size() const
    {
        return m_used;
    }
};



#endif //DYNAMICARRAY_H
