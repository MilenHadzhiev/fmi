#ifndef AUTHOR_H
#define AUTHOR_H
#include <cstring>
#include <stdexcept>

struct Author
{
    char name[11];

    Author()
    {
        name[0] = '\0';
    }

    Author(const char* str)
    {
        if (!check_name_len(str)) throw std::invalid_argument("Author name cannot exceed 10 characters");

        strcpy(name, str);
    }

    Author(const Author& other) = default;

    Author(Author&& other) = default;

    ~Author() = default;

    Author& operator=(const Author& other) = default;
    Author& operator=(Author&& other) = default;

private:
    static bool check_name_len(const char* str)
    {
        return strlen(str) <= 10;
    }
};

#endif //AUTHOR_H
