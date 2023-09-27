#Documentacion .h
```
//si no existe la clase IntCell, la define.
#ifndef INTCELL_H
#define INTCELL_H

class IntCell {
//los elementos  publicos de la clase
public:

	//constructor explicito tipo IntCell que guarda un int
    explicit IntCell(int newValue = 0);

	//constructores implicitos tipo intcell, uno por copia y otro por referencia.
    IntCell(const IntCell &rhs);
    IntCell(IntCell &&rhs) noexcept;

	//destructor default
    ~IntCell() = default;

	//operador de asignacion recibiendo un r valor constante tipo intcell por copia
    IntCell &operator=(const IntCell &rhs);

	//operador de asignacion recibiendo un r valor constante tipo intcell por movimiento
    IntCell &operator=(IntCell &&rhs) noexcept;

    //operador de asignacion recibiendo un entero
    IntCell &operator=(int rhs);

	//Metodo getValue con constante. Obtiene un valor
    int getValue() const;

	//metodo setValue con un entero. Asigna un valor
    void setValue(int newValue);

//elementos privados que solo pueden ser accesados por la misma clase
private:
	//entero storedValue
    int storedValue;
};

#endif  // INTCELL_H

```

#Documentacion .cpp

```
//incluye el .h de intcell
#include "IntCell.h"

// constructor por default
IntCell::IntCell(int newValue) : storedValue(newValue) {}

// constructor por copia. Recibe un r valor tipo intcell por copia y lo guarda en stored value
IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {}

// constructor por movimiento. Recibe un r valor tipo intcell por referencia, lo guarda en storedValue y le da valor 0 a la referencia para liberar memoria.
IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) {
   // rhs.storedValue = 0;
}
// operador de asignacion por copia. Recibe un r valor constante tipo intcell y si el valor en storedValue es diferente al valor recibido, le asigna el valor. Regresa el valor asignado
IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

// Operador de asignacion por movimiento. Recibe un r valor tipo intcell por referencia y si el valor recibido es diferente al storedValue, asigna el valor a storedValue. Le da valor 0 a la referencia.
IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

// Removed overloaded assignment operator to accept any data

// Operador de asignacion para recibir enteros. Recibe un entero, se lo asigna a storedValue y regresa el valor
IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
}

```
