#ifndef STRING_H
#define STRING_H

class String
{
    char * m_data;
    unsigned int m_size;
public:
    String();
    String(const char* str);
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    String& operator=(const String& other);
    String& operator=(const char* other);
    String& operator=(String&& other) noexcept;

    bool operator==(const String& other) const noexcept;
    bool operator==(const char* other) const noexcept;
    bool operator!=(const String& other) const noexcept;
    bool operator!=(const char* other) const noexcept;
    char operator[](unsigned int idx) const;

    const char* c_str() const noexcept;
};
#endif //STRING_H
