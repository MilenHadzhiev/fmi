#include "computer_part.h"

#include <stdexcept>

void ComputerPart::throw_invalid_argument_for_negative_price()
{
    throw std::invalid_argument("Price must be a non-negative floating point number.");
}

void ComputerPart::clean_moved_object(ComputerPart&& other)
{
    other.m_part_type = nothing;
    other.m_warranty_years = 0;
    other.m_price = 0;
    other.m_make = nullptr;
    other.m_model = nullptr;
}

ComputerPart::ComputerPart() : m_make(nullptr), m_model(nullptr), m_price(0), m_warranty_years(0),  m_part_type(nothing) {}

ComputerPart::ComputerPart(const String& make, const String& model, float price, unsigned int warranty, ComputerPartType part_type)
    : m_make(make), m_model(model), m_price(price), m_warranty_years(warranty), m_part_type(part_type) {}

ComputerPart::ComputerPart(const char* make,
    const char* model,
    float price,
    unsigned int warranty,
    ComputerPartType part_type)
: m_make(make), m_model(model), m_warranty_years(warranty), m_part_type(part_type)
{
    if (price < 0)
    {
        throw_invalid_argument_for_negative_price();
    }
    m_price = price;
}

ComputerPart::ComputerPart(const ComputerPart& other)
: ComputerPart(other.m_make, other.m_model, other.m_price, other.m_warranty_years, other.m_part_type)
{}

ComputerPart::ComputerPart(ComputerPart&& other) noexcept
: m_make(std::move(other.m_make)),
  m_model(std::move(other.m_model)),
  m_price(other.m_price),
  m_warranty_years(other.m_warranty_years),
  m_part_type(other.m_part_type)
{
    clean_moved_object(std::move(other));
}

ComputerPart& ComputerPart::operator=(const ComputerPart& other)
{
    if (this != &other)
    {
        m_make = other.m_make;
        m_model = other.m_model;
        m_price = other.m_price;
        m_warranty_years = other.m_warranty_years;
        m_part_type = other.m_part_type;
    }
    return *this;
}

ComputerPart& ComputerPart::operator=(ComputerPart&& other) noexcept
{
    if (this != &other)
    {
        m_make = std::move(other.m_make);
        m_model = std::move(other.m_model);
        m_price = other.m_price;
        m_warranty_years = other.m_warranty_years;
        m_part_type = other.m_part_type;
        other.m_price = 0;
        other.m_warranty_years = 0;
        other.m_part_type = nothing;

        clean_moved_object(std::move(other));
    }
    return *this;
}

bool ComputerPart::operator==(const ComputerPart& other) const
{
    return m_make == other.m_make
        && m_model == other.m_model
        && m_price == other.m_price
        && m_warranty_years == other.m_warranty_years
        && m_part_type == other.m_part_type;
}

ComputerPartType ComputerPart::part_type() const noexcept
{
    return m_part_type;
}

unsigned int ComputerPart::warranty() const noexcept
{
    return m_warranty_years;
}

float ComputerPart::price() const noexcept
{
    return m_price;
}

const String& ComputerPart::make() const noexcept
{
    return m_make;
}

const String& ComputerPart::model() const noexcept
{
    return m_model;
}

void ComputerPart::set_price(float new_price)
{
    if (new_price < 0) throw_invalid_argument_for_negative_price();

    m_price = new_price;
}