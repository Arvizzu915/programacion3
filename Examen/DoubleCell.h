#ifndef DOUBLE_CELL_H
#define DOUBLE_CELL_H

class DoubleCell {
public:

    explicit DoubleCell();

    // Constructor with value
    DoubleCell(double value = 0);

    // Copy constructor
    DoubleCell(const DoubleCell& rhs);

    //Reference constructor
    DoubleCell(DoubleCell &&rhs) noexcept;

    // Destructor
    ~DoubleCell() = default;

    // Assignment operator by copy
    DoubleCell &operator=(const DoubleCell &rhs);

    // Assignment operator by reference
    DoubleCell &operator=(DoubleCell &&rhs) noexcept;

    // Assignment operator for double
    DoubleCell &operator=(double rhs);

    // Arithmetic operators
    DoubleCell operator +(const DoubleCell& other) const;
    DoubleCell operator +(const double other) const;
    DoubleCell operator -(const DoubleCell& other) const;
    DoubleCell operator -(const double other) const;
    DoubleCell operator *(const DoubleCell& other) const;
    DoubleCell operator *(const double other) const;
    DoubleCell operator /(const DoubleCell& other) const;
    DoubleCell operator /(const double other) const;

    // Setters
    double getValue() const;

    // Getters
    void setValue(double Value);


private:
    double storedValue;
};

#endif  // DOUBLE_CEL