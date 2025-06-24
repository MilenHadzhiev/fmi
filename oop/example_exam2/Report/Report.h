#ifndef REPORT_H
#define REPORT_H
#include <cstdint>

#include "../Article/Article.h"
#include "../Author/Author.h"
#include "../DynamicArray/DynamicArray.h"

class Report : protected Article {
    Author m_reporter;
    char m_id[5];
    uint8_t m_duration;

public:
    Report();
    Report(const DynamicArray<Author>& authors, const char* title, const Author& reporter, const char id[5], uint8_t duration);
    Report(const Report& other);
    Report(Report&& other) noexcept;

    ~Report() override = default;

    Report& operator=(const Report& other);
    Report& operator=(Report&& other) noexcept;
};



#endif //REPORT_H
