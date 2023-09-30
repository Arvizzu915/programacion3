#include "FloatCell.h"

//Guarda un float en storedValue
FloatCell::FloatCell(float newValue) : storedValue(newValue){}

//Por copia recibiendo otro floatcell, lo guarda en storedValue
FloatCell::FloatCell(const FloatCell &rhs) : storedValue(rhs.storedValue){}

//Por movimiento recibiendo otro floatcell, lo guarda en storedValue y le asigna 0 al otro.
FloatCell::FloatCell(FloatCell &&rhs) noexcept : storedValue(rhs.storedValue){
    rhs.storedValue = 0;
}

//Operador de asignación por copia, compara y si no son iguales, lo guarda en storedValue. Regresa this
FloatCell &FloatCell::operator=(const FloatCell &rhs)  {
    if (this != &rhs){
        storedValue = rhs.storedValue;
    }
    return *this;
}

//Operador de asignación por movimiento, compara y si no son iguales, lo guarda en storedValue y de da valor 0 al original para ahorrar memoria
FloatCell &FloatCell::operator=(FloatCell &&rhs) noexcept {
    if (this != &rhs){
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

//Operador de asignación recibiendo un float, lo guarda en storedValue
FloatCell &FloatCell::operator=(float rhs){
    storedValue = rhs;
    return *this;
}

//Método getValue lo guarda en storedValue
float FloatCell::getValue() const {
    return storedValue;
}

//Método setValue le da un valor en storedValue
void FloatCell::setValue(float newValue) {
    storedValue = newValue;
}
```