#include "computer_part/computer_part.h"
#include "string/string.h"

#include <iostream>
#include <fstream>



int main()
{
    // std::ifstream file("file.txt");
    // if (!file.is_open())
    // {
        // std::cerr << "file not opened";
        // return 1;
    // }

    // file.seekg(0, std::ios::end);
    // size_t file_size = file.tellg();

    // char* buffer = new char[file_size + 1];
    // file.seekg(0);

    // file.read(buffer, file_size);

    // buffer[file_size] = '\0';
    // for (size_t i = 0; i < file_size; ++i)
    // {
        // std::cout << buffer[i];
    // }

    // std::cout << buffer;
    // delete[] buffer;

    // file.close();
    String s("make as string");

    // ComputerPart p(s, "model as const char*", 255.99f, 2, monitor);

    return 0;
}
