#include "computer_part_writer.h"

#include <fstream>
#include <cstring>
#include <utility>

#include "../computer_part_type/computer_part_type.h"

ComputerPartWriter::ComputerPartWriter(const ComputerPart& part) : m_part(part) {}

ComputerPartWriter::ComputerPartWriter(const ComputerPartWriter& other) : ComputerPartWriter(other.m_part) {}

ComputerPartWriter::ComputerPartWriter(ComputerPartWriter&& other) noexcept : m_part(std::move(other.m_part)) {}

ComputerPartWriter& ComputerPartWriter::operator=(const ComputerPartWriter& other)
{
    if (this != &other)
    {
        m_part = other.m_part;
    }
    return *this;
}

ComputerPartWriter& ComputerPartWriter::operator=(ComputerPartWriter&& other) noexcept
{
    if (this != &other)
    {
        m_part = other.m_part;

        other.m_part = ComputerPart();
    }
    return *this;
}

void ComputerPartWriter::write(const char* filename) const
{
    std::ofstream file(filename);
    if (!file.is_open()) throw std::runtime_error("File not found");

    file << '{';
    write_str(file, part_type_to_str(m_part.part_type()));

    file << '|';
    write_str(file, m_part.make().c_str());

    file << '|';
    write_str(file, m_part.model().c_str());

    file << '|';
    file << m_part.warranty();

    file << '|';
    file << m_part.price();

    file << '}';
    file.close();
}

void ComputerPartWriter::write_str(std::ofstream& output, const char* str)
{
    for (size_t i = 0; i < strlen(str); ++i)
    {
        output << str[i];
    }
}

