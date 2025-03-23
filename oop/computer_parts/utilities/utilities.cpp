#include <stdexcept>
#include <cstring>

char* copy_string(const char* src)
{
    if (src == nullptr)
    {
        throw std::invalid_argument("Can not copy nullptr!");
    }
    char* dst = new char[strlen(src) + 1];
    strcpy(dst, src);
    dst[strlen(src)] = '\0';
    return dst;
}