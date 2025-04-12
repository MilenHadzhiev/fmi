#include "computer_part_type.h"
#include "../string/string.h"
#include <stdexcept>

const char* part_type_to_str(ComputerPartType part_type)
{
    switch (part_type)
    {
        case nothing: return "";
        case monitor: return "monitor";
        case laptop: return "laptop";
        case mouse: return "mouse";
        case keyboard: return "keyboard";
        case headphones: return "headphones";
        case camera: return "camera";
        default: throw std::invalid_argument("unknown computer part");
    }
}

ComputerPartType string_to_part_type(const String& str)
{
    if (str == "monitor") return monitor;
    if (str == "laptop") return laptop;
    if (str == "mouse") return mouse;
    if (str == "keyboard") return keyboard;
    if (str == "headphones") return headphones;
    if (str == "camera") return camera;

    throw std::invalid_argument("unknown computer part");
}
