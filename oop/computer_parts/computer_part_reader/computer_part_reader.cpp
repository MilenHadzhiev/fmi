#include "computer_part_reader.h"

#include <cstring>
#include <fstream>

ComputerPartReader::ComputerPartReader() : m_filename(nullptr) {}

ComputerPartReader::ComputerPartReader(const char* filename)
{
    validate_file_format(filename);
    m_filename = filename;
}

ComputerPartReader::ComputerPartReader(const String& filename)
{
    validate_file_format(filename.c_str());
    m_filename = filename;
}

ComputerPartReader::ComputerPartReader(const ComputerPartReader& other) : ComputerPartReader(other.m_filename) {}

ComputerPartReader::ComputerPartReader(ComputerPartReader&& other) noexcept : m_filename(std::move(other.m_filename))
{
    other.m_filename = nullptr;
}


void ComputerPartReader::throw_invalid_file_format()
{
    throw std::runtime_error("Invalid file format");
}


ComputerPart ComputerPartReader::read() const
{
    std::ifstream file(m_filename.c_str());

    if (!file) throw std::runtime_error("File not found");

    file.seekg(0, std::ios::end);
    std::streamsize file_size = file.tellg();
    file.seekg(0);
    char* buffer = new char[file_size + 1];
    file.read(buffer, file_size);
    buffer[file_size] = '\0';
    file.close();
    String data(buffer);
    delete[] buffer;

    if (file_size == 0) throw_invalid_file_format();
    if (data[0] != '{' || data[file_size - 1] != '}') throw_invalid_file_format();

    ComputerPart part = build_computer_part(data);
    return part;
}

void ComputerPartReader::validate_file_format(const char* filename)
{
    size_t filename_len = strlen(filename);
    if (filename[filename_len - 1] != 't'
        && filename[filename_len - 2] != 'x'
        && filename[filename_len - 3] != 't'
        && filename[filename_len - 4] != '.')
    {
        throw std::invalid_argument("Can only read txt files.");
    }
}


ComputerPart ComputerPartReader::build_computer_part(const String& data)
{
    const char* start = &data.c_str()[1];
    const char* end = nullptr;

    String part_type = nullptr;
    String make = nullptr;
    String model = nullptr;
    String warranty_s = nullptr;
    String price_s = nullptr;
    for (unsigned short field_count = 0; field_count < 5; field_count++)
    {
        end = strchr(start, '|');
        size_t len = (end != nullptr) ? (end - start) : strlen(start) - 1; //because of the }
        char* current_data = new char[len + 1];
        std::memcpy(current_data, start, len);
        current_data[len] = '\0';

        if (field_count == 0) part_type = current_data;
        else if (field_count == 1) make = current_data;
        else if (field_count == 2) model = current_data;
        else if (field_count == 3) warranty_s = current_data;
        else if (field_count == 4) price_s = current_data;

        delete[] current_data;
        if (end == nullptr) break;

        start = end + 1;
    }

    if (!part_type.c_str() || !make.c_str() || !model.c_str() || !warranty_s.c_str() || !price_s.c_str()) throw_invalid_file_format();

    char* trailing_chars = nullptr;

    float price = std::strtof(price_s.c_str(), &trailing_chars);
    if (*trailing_chars != '\0') throw_invalid_file_format();

    unsigned int warranty = std::strtoul(warranty_s.c_str(), &trailing_chars, 10);
    if (*trailing_chars != '\0')
    {
        delete[] trailing_chars;
        throw_invalid_file_format();
    }

    ComputerPart part(make, model, price, warranty, string_to_part_type(part_type));

    return part;
}