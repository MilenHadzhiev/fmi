#ifndef ARTICLE_H
#define ARTICLE_H
#include <cstdint>
#include "../Author/Author.h"

#include "../DynamicArray/DynamicArray.h"


class Article {
    DynamicArray<Author> m_authors;
    char* m_title;
public:
    Article();
    Article(const DynamicArray<Author>& authors, const char* title);
    Article(const Article& other);
    Article(Article&& other) noexcept;

    virtual ~Article();

    Article& operator=(const Article& other);
    Article& operator=(Article&& other) noexcept;
};

#endif //ARTICLE_H
