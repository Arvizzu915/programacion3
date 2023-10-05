#ifndef SLLLIST_H
#define SLLLIST_H

#include <iostream>
#include <utility>

//Como plantilla para poder recibir cualquier tipo de dato
template <typename Object>
class SLList {
private:
    //Cada nodo
    struct Node  {
        Object data;
        //Puntero a la siguiente posición
        Node *next;

        //Constructor por copia
        Node(const Object &d = Object{}, Node *n = nullptr)
                : data{d}, next{n} {}

        //Constructor por referencia
        Node(Object &&d, Node *n = nullptr)
                : data{std::move(d)}, next{n} {}
    };

public:
    //iterador
    class iterator {
    public:
        //Constructor implicito. current le da valor nullptr
        iterator() : current{nullptr} {}

        //Operador de puntero. Si current es nullptr lanza un mensaje diciendo que se está intentando referenciar a null
        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        //Incremento. Para pasar al siguiente nodo
        iterator &operator++() {
            if(current)
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        //Lleva el conteo de en que nodo va. Guarda el valor viejo y suma al nuevo
        iterator operator++(int) {
            iterator old = *this;
            ++(*this);
            return old;
        }

        //Operador de comparación igual
        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }

        //Operador de comparación diferente
        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

    private:
        //Apuntador al nodo current
        Node *current;
        iterator(Node *p) : current{p} {}
        //A los atributos puede entrar sllist y el iterador
        friend class SLList<Object>;
    };

public:
    //Define el inicio, final y tamaño de la lista
    SLList() : head(new Node()), tail(new Node()), theSize(0) {
        //El nodo head y el siguiente es el nodo tail
        head->next = tail;
    }

    //Destructor. Borra todos los elementos con clear y borra head y tail
    ~SLList() {
        clear();
        delete head;
        delete tail;
    }

    //Getters para sacar el valor del inicio y el final
    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    //Para saber el tamaño de la lista
    int size() const { return theSize; }

    //
    bool empty() const { return size() == 0; }
    //Mientras la lista no esté vacia va borrando el del enfrente
    void clear() { while (!empty()) pop_front(); }

    //Si la lista no está vacia regresa el inicio de la lista. Si no da el mensaje de un error lógico
    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    //agrega al frente. Uno por copia y uno por referencia
    void push_front(const Object &x) { insert(begin(), x); }
    void push_front(Object &&x) { insert(begin(), std::move(x)); }

    //Quita el elemento que está adelante. Manda un mensaje de error lógico si la lista está vacia
    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    //inserta en la posición x por copia
    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    //inserta en la posición x por referencia
    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }

    //Borra en x posición
    iterator erase(iterator itr) {
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }

    //Imprime la lista. Getter
    void printList() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private:
    //Parametros privados

    //head: inicio de la lista
    Node *head;
    //tail: final de la lista
    Node *tail;
    //tamaño de la lista
    int theSize;
    //inicializador
    void init() {
        theSize = 0;
        head->next = tail;
    }
};

#endif