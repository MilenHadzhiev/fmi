#ifndef COMPUTER_PART_READER_H
#define COMPUTER_PART_READER_H
#include "../computer_part/computer_part.h"

class ComputerPartReader
{
    String m_filename;
    static void throw_invalid_file_format();
    static ComputerPart build_computer_part(const String& data);

    static void validate_file_format(const char* filename);
public:
    ComputerPartReader();
    ComputerPartReader(const char* filename);
    ComputerPartReader(const String& filename);
    ComputerPartReader(const ComputerPartReader& other);
    ComputerPartReader(ComputerPartReader&& other) noexcept;
    ~ComputerPartReader();

    void set_file_to_read(const char* filename);
    ComputerPart read() const;
};
#endif //COMPUTER_PART_READER_H
