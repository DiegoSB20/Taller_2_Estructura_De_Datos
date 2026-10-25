#pragma once

#include "NodoAVL.hpp"
#include <string>

class AVL {
private:
    NodoAVL* raiz;

    int altura(NodoAVL* nodo) const;
    int factorBalance(NodoAVL* nodo) const;

    NodoAVL* rotacionDerecha(NodoAVL* nodo);
    NodoAVL* rotacionIzquierda(NodoAVL* nodo);

    NodoAVL* balancear(NodoAVL* nodo);
    NodoAVL* insertar(NodoAVL* nodo, const Paciente& paciente, bool& insertado);
    NodoAVL* eliminar(NodoAVL* nodo, const std::string& id, bool& eliminado);
    NodoAVL* minimo(NodoAVL* nodo) const;

    void mostrarResumen(NodoAVL* nodo, bool& primero) const;

    const Paciente* buscarPorId(NodoAVL* nodo, const std::string& id) const;
    const Paciente* buscarPorNombre(NodoAVL* nodo, const std::string& nombre) const;

    void inorden(NodoAVL* nodo) const;
    void preorden(NodoAVL* nodo) const;
    void postorden(NodoAVL* nodo) const;
    void mostrarFactoresBalance(NodoAVL* nodo) const;

    NodoAVL* copiar(NodoAVL* nodo) const;
    void liberar(NodoAVL* nodo) const;

public:
    AVL();
    AVL(const AVL& otro);
    AVL& operator=(const AVL& otro);
    ~AVL();

    bool insertar(const Paciente& paciente);

    void mostrarResumen() const;

    std::string rutaBusquedaPorId(const std::string& id) const;

    const Paciente* buscarPorId(const std::string& id) const;
    const Paciente* buscarPorNombre(const std::string& nombre) const;

    bool eliminarPorId(const std::string& id);
    bool empty() const;

    int altura() const;
    int factorBalance() const;

    void inorden() const;
    void preorden() const;
    void postorden() const;

    void mostrarFactoresBalance() const;

    void clear();

};