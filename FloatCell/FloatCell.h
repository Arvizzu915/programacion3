//Si no existe la clase FloatCell, define FloatCell
#ifndef FLOATCELL_H
#define FLOATCELL_H


class FloatCell {
//Elementos publicos de la clase
public:
    //Flotante tipo FloatCell que se guarda en newValue
    FloatCell(float newValue = 0);
    //Constructor por copia con constante tipo FloatCell
    explicit FloatCell(const FloatCell &rhs);
    //Constructor por movimiento tipo FloatCell
    explicit FloatCell(FloatCell &&rhs) noexcept;
    //Destructor por default
    ~FloatCell() = default;

    //Operador de asignación con constante por copia
    FloatCell &operator=(const FloatCell &rhs);
    //Operador de asignación por movimiento
    FloatCell &operator=(FloatCell &&rhs) noexcept;

    //Operador de asignación con flotante
    FloatCell &operator=(float rhs);

    //Método getValue
    float getValue() const;
    //Método setValue
    void setValue(float newValue);

//Elementos privados, solo puede acceder la misma clase
private:
    //storedValue con flotante
    float storedValue;

};

//termina de definir
#endif FLOATCELL_H