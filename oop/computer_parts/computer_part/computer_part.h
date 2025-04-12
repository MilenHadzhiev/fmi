#ifndef COMPUTER_PART_H
#define COMPUTER_PART_H

#include "../computer_part_type/computer_part_type.h"
#include "../string/string.h"

class ComputerPart
{
    String m_make;
    String m_model;
    float m_price;
    unsigned int m_warranty_years;
    ComputerPartType m_part_type;

    static void throw_invalid_argument_for_negative_price();

    static void clean_moved_object(ComputerPart&& other);
public:
    ComputerPart();
    ComputerPart(const String& make, const String& model, float price, unsigned int warranty, ComputerPartType part_type);
    ComputerPart(const char* make, const char* model, float price, unsigned int warranty, ComputerPartType part_type);
    ComputerPart(const ComputerPart& other);
    ComputerPart(ComputerPart&& other) noexcept;
    ~ComputerPart() = default;

    ComputerPart& operator=(const ComputerPart& other);
    ComputerPart& operator=(ComputerPart&& other) noexcept;

    bool operator==(const ComputerPart& other) const;

    ComputerPartType part_type() const noexcept;
    unsigned int warranty() const noexcept;
    float price() const noexcept;
    const String& make() const noexcept;
    const String& model() const noexcept;

    void set_price(float new_price);
};

#endif //COMPUTER_PART_H
