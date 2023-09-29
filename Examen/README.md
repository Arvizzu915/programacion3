i. ¿Qué es un Rvalor y un Lvalor?
Un Rvalor es un valor que va a la derecha de la asignación y es temporal. No tiene espacio en memoria. Un Lvalor es un valor que puede ir a la izquierda o a la derecha de una asignación; cuando se crea ocupa espacio en memoria.

ii. ¿Porqué es necesario que una clase tenga constructores y operadores por
copia y por referencia?
Para que pueda recibir tanto Rvalores como valores por referencia a otra variable

iii. ¿Qué función desarrollan los :: en la implementación de la clase?
Para especificar que se trata de esa clase

iv. ¿Cómo se le denomina a cuando una clase posee un operador puede
tener múltiples implementaciones dependiendo de los argumentos que
este reciba?
Sobrecarga de funciones

v. ¿Cuál es la función del archivo .h ?
Definir la clase, decirle a la clase todo lo que puede recibir para crear espacio en memoria.


O(n^2)
```c
#include <iostream>
int algoritmo1(int n) {
int resultado = 0;
for (int i = 0; i < n; i++) {
resultado += i; // Operación simple O(1)
}
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
resultado += i * j; // Operación simple O(1)
}
}
return resultado;
}
int main() {
int n;
std::cout << "Ingrese el valor de n: ";
std::cin >> n;
Parte 2

Complejidad Temporal

int resultado = algoritmo1(n);
std::cout << "Resultado: " << resultado << std::endl;
return 0;
}
```
