#ifndef COMPUTER_PART_WRITER_H
#define COMPUTER_PART_WRITER_H
#include <fstream>

#include "../computer_part/computer_part.h"

class ComputerPartWriter
{
    ComputerPart m_part;
    static void write_str(std::ofstream& output, const char* str);
public:
    ComputerPartWriter() = default;
    ComputerPartWriter(const ComputerPart& part);
    ComputerPartWriter(const ComputerPartWriter& other);
    ComputerPartWriter(ComputerPartWriter&& other) noexcept;
    ~ComputerPartWriter() = default;

    ComputerPartWriter& operator=(const ComputerPartWriter& other);
    ComputerPartWriter& operator=(ComputerPartWriter&& other) noexcept;

    void write(const char* filename) const;
};
#endif //COMPUTER_PART_WRITER_H