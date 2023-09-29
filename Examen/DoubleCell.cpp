#include "DoubleCell.h"
#include <stdexcept>

// Default constructor
DoubleCell::DoubleCell() : storedValue(0) {}

// Constructor with value
DoubleCell::DoubleCell(double value): storedValue(value){}

// Copy constructor
DoubleCell::DoubleCell(const DoubleCell &rhs) : storedValue(rhs.storedValue){}

//Reference  constructor
DoubleCell::DoubleCell(DoubleCell &&rhs) noexcept : storedValue(rhs.storedValue){
    rhs.storedValue = 0;
}


// Assignment operator by copy
DoubleCell &DoubleCell::operator=(const DoubleCell &rhs)  {
    if (this != &rhs){
        storedValue = rhs.storedValue;
    }
    return *this;
}

// Assignment operator by reference
DoubleCell &DoubleCell::operator=(DoubleCell &&rhs) noexcept {
    if (this != &rhs){
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

// Assignment operator for double
DoubleCell& DoubleCell::operator=(double rhs){
    storedValue = rhs;
    return *this;
}


// Arithmetic operators
//DoubleCell adding
DoubleCell DoubleCell::operator +(const DoubleCell& other) const{
    return DoubleCell(storedValue + other.storedValue);
}
//primitive double adding
DoubleCell DoubleCell::operator+(const double other) const {
    return DoubleCell(storedValue + other);
}


//DoubleCell substracting
DoubleCell DoubleCell::operator-(const DoubleCell& other) const {
    return DoubleCell(storedValue - other.storedValue);
}

//primitive double substracting
DoubleCell DoubleCell::operator -(double value) const{
    return DoubleCell(storedValue - value);
}

//DoubleCell multiplication
DoubleCell DoubleCell::operator *(const DoubleCell& other) const{
    return DoubleCell(storedValue * other.storedValue);
}
//primitive double multiplication
DoubleCell DoubleCell::operator*(const double other) const {
    return DoubleCell(storedValue * other);
}

//DoubleCell division
DoubleCell DoubleCell::operator /(const DoubleCell& other) const{
    if(other.storedValue == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(storedValue / other.storedValue);
}

//Primitive double division
DoubleCell DoubleCell::operator /(const double other) const{
    if(other == 0){
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(storedValue / other);
}

// Setters
void DoubleCell::setValue(double value){
    storedValue = value;
}

// Getters
double DoubleCell::getValue() const {
    return storedValue;
}
