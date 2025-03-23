#ifndef COMPUTER_TYPE_H
#define COMPUTER_TYPE_H
#include "../string/string.h"

enum ComputerPartType
{
    nothing,
    monitor,
    computer,
    laptop,
    mouse,
    keyboard,
    headphones,
    camera
};

const char* part_type_to_str(ComputerPartType part_type);

ComputerPartType string_to_part_type(const String& str);

#endif //COMPUTER_TYPE_H
