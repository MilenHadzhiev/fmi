#include "Article.h"

#include <cstdint>

Article::Article() : m_authors(DynamicArray<Author>()), m_title(nullptr) {}

Article::Article(const DynamicArray<Author>& authors, const char* title) : m_authors(authors), m_title(new char[strlen(title) + 1])
{
    strcpy(m_title, title);
}

Article::Article(const Article& other) : m_authors(other.m_authors), m_title(new char[strlen(other.m_title) + 1])
{
    strcpy(m_title, other.m_title);
}

Article::Article(Article&& other) noexcept : m_authors(std::move(other.m_authors)), m_title(other.m_title)
{
    other.m_title = nullptr;
}

Article::~Article()
{
    delete[] m_title;
}


Article& Article::operator=(const Article& other)
{
    if (this != &other)
    {
        m_authors = other.m_authors;
        char* buffer = new char[strlen(other.m_title) + 1];
        strcpy(buffer, other.m_title);
        delete[] m_title;
        m_title = buffer;
    }
    return *this;
}

Article& Article::operator=(Article&& other) noexcept
{
    if (this != &other)
    {
        m_authors = std::move(other.m_authors);
        delete[] m_title;
        m_title = other.m_title;
        other.m_title = nullptr;
    }
    return *this;
}
