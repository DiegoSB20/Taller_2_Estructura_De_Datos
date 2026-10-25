#include "../Data_structures_h//List.hpp"

template <typename T>
List<T>::List() {
    this->start = nullptr;
}


template <typename T>
List<T>::List(const List<T>& otra) {
    this->start = nullptr;

    Node<T>* cursor = otra.start;

    try {
        while (cursor != nullptr) {
            this->insertLast(cursor->getValue());
            cursor = cursor->getNext();
        }
    }
    catch (...) {
        clear();
        throw;
    }
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& otra) {
    if (this != &otra) {
        List<T> copia(otra);

        Node<T>* temporal = this->start;
        this->start = copia.start;
        copia.start = temporal;
    }

    return *this;
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
bool List<T>::empty() const {
    return this->start == nullptr;
}

template <typename T>
int List<T>::size() const {
    int cantidad = 0;
    Node<T>* cursor = this->start;

    while (cursor != nullptr) {
        cantidad++;
        cursor = cursor->getNext();
    }

    return cantidad;
}

template <typename T>
void List<T>::insert(T value, int index) {
    if (index < 0 || index > size()) {
        throw 0;
    }

    if (index == 0) {
        insertFirst(value);
        return;
    }

    Node<T>* cursor = this->start;

    for (int i = 0; i < index - 1; i++) {
        cursor = cursor->getNext();
    }

    Node<T>* nuevo = new Node<T>(value);

    nuevo->setNext(cursor->getNext());
    cursor->setNext(nuevo);
}

template <typename T>
void List<T>::insertFirst(T value) {
    Node<T>* nuevo = new Node<T>(value);

    nuevo->setNext(this->start);
    this->start = nuevo;
}

template <typename T>
void List<T>::insertLast(T value) {
    Node<T>* nuevo = new Node<T>(value);

    if (this->start == nullptr) {
        this->start = nuevo;
        return;
    }

    Node<T>* cursor = this->start;

    while (cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }

    cursor->setNext(nuevo);
}

template <typename T>
T List<T>::get(int index) const {
    if (index < 0 || this->start == nullptr) {
        throw 0;
    }

    Node<T>* cursor = this->start;

    for (int i = 0; i < index; i++) {
        cursor = cursor->getNext();

        if (cursor == nullptr) {
            throw 0;
        }
    }

    return cursor->getValue();
}

template <typename T>
T& List<T>::getReferencia(int index) {
    if (index < 0 || this->start == nullptr) {
        throw 0;
    }

    Node<T>* cursor = this->start;

    for (int i = 0; i < index; i++) {
        cursor = cursor->getNext();

        if (cursor == nullptr) {
            throw 0;
        }
    }

    return cursor->getValueReferencia();
}

template <typename T>
T List<T>::getFirst() const {
    if (this->start == nullptr) {
        throw 0;
    }

    return this->start->getValue();
}

template <typename T>
T List<T>::getLast() const {
    if (this->start == nullptr) {
        throw 0;
    }

    Node<T>* cursor = this->start;

    while (cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }

    return cursor->getValue();
}


template <typename T>
void List<T>::remove(int index) {
    if (index < 0 || this->start == nullptr) {
        throw 0;
    }

    if (index == 0) {
        Node<T>* eliminar = this->start;

        this->start = this->start->getNext();

        delete eliminar;
        return;
    }

    Node<T>* cursor = this->start;

    for (int i = 0; i < index - 1; i++) {
        cursor = cursor->getNext();

        if (cursor == nullptr) {
            throw 0;
        }
    }

    Node<T>* eliminar = cursor->getNext();

    if (eliminar == nullptr) {
        throw 0;
    }

    cursor->setNext(eliminar->getNext());

    delete eliminar;
}

template <typename T>
void List<T>::clear() {
    while (this->start != nullptr) {
        Node<T>* temporal = this->start;

        this->start = this->start->getNext();

        delete temporal;
    }
}