#include "../Data_structures_h/ArbolDecision.hpp"

#include <iostream>

using namespace std;

ArbolDecision::ArbolDecision() {
    raiz = nullptr;
    construir();
}

ArbolDecision::~ArbolDecision() {
    clear();
}

void ArbolDecision::construir() {
    raiz = new NodoDecision(CriterioDecision::TRAUMA);

    NodoDecision* cirugia = new NodoDecision(CriterioDecision::REQUIERE_CIRUGIA);

    raiz->setIzquierdo(cirugia);

    cirugia->setIzquierdo(new NodoDecision("Cirugía"));

    cirugia->setDerecho(new NodoDecision("Traumatología"));

    NodoDecision* edad = new NodoDecision(CriterioDecision::EDAD_MENOR_14);

    raiz->setDerecho(edad);

    edad->setIzquierdo(new NodoDecision("Pediatría"));

    NodoDecision* neurologia = new NodoDecision(CriterioDecision::SINTOMAS_NEUROLOGICOS);

    edad->setDerecho(neurologia);

    neurologia->setIzquierdo(new NodoDecision("Neurología"));

    NodoDecision* cardiologia = new NodoDecision(CriterioDecision::RIESGO_CARDIOLOGICO);

    neurologia->setDerecho(cardiologia);

    cardiologia->setIzquierdo(new NodoDecision("Cardiología"));

    NodoDecision* urgencia = new NodoDecision(CriterioDecision::URGENCIA);

    cardiologia->setDerecho(urgencia);

    urgencia->setIzquierdo(new NodoDecision("Urgencias"));

    NodoDecision* hospitalizacion = new NodoDecision(CriterioDecision::HOSPITALIZACION);

    urgencia->setDerecho(hospitalizacion);

    hospitalizacion->setIzquierdo(new NodoDecision("Hospitalización"));

    hospitalizacion->setDerecho(new NodoDecision("Medicina General"));
}

string ArbolDecision::evaluarPaciente(const Paciente& paciente,string& ruta) const {
    ruta.clear();

    return evaluar(raiz,paciente,ruta);
}

string ArbolDecision::evaluarPaciente(const Paciente& paciente) const {
    string ruta;

    return evaluarPaciente(paciente, ruta);
}

string ArbolDecision::evaluar(NodoDecision* nodo,const Paciente& paciente,string& ruta) const {
    if (nodo == nullptr) {
        return "";
    }

    if (nodo->esHoja()) {
        return nodo->getServicio();
    }

    bool resultado = nodo->evaluarCondicion(paciente);

    string descripcion;

    switch (nodo->getCriterio()) {
        case CriterioDecision::TRAUMA:
            descripcion = resultado ? "Trauma == 1" : "Trauma == 0";

            break;

        case CriterioDecision::REQUIERE_CIRUGIA:
            descripcion = resultado ? "RequiereCirugia == 1" : "RequiereCirugia == 0";

            break;

        case CriterioDecision::EDAD_MENOR_14:
            descripcion = resultado ? "Edad < 14" : "Edad >= 14";
            break;


        case CriterioDecision::SINTOMAS_NEUROLOGICOS:
            descripcion = resultado ? "SintomasNeurologicos == 1" : "SintomasNeurologicos == 0";

            break;


        case CriterioDecision::RIESGO_CARDIOLOGICO:
            descripcion = resultado ? "Dolor de pecho o PresionArterial >= 140" : "Sin riesgo cardiologico";

            break;


        case CriterioDecision::URGENCIA:
            descripcion = resultado ? "Temperatura >= 38.5 o Dolor >= 8" : "Temperatura < 38.5 y Dolor < 8";

            break;


        case CriterioDecision::HOSPITALIZACION:
            descripcion = resultado ? "DiasHospitalizacion >= 2" : "DiasHospitalizacion < 2";

            break;


        case CriterioDecision::HOJA:
            break;
    }


    if (!ruta.empty()) {
        ruta += " -> ";
    }

    ruta += descripcion;

    if (resultado) {
        return evaluar(nodo->getIzquierdo(), paciente, ruta);
    }

    return evaluar(nodo->getDerecho(), paciente, ruta);
}

void ArbolDecision::inorden() const {
    inorden(raiz);
}

void ArbolDecision::inorden(NodoDecision* nodo) const {
    if (nodo == nullptr) {
        return;
    }

    inorden(nodo->getIzquierdo());

    cout << nodo->getDescripcion() << endl;

    inorden(nodo->getDerecho());
}

void ArbolDecision::preorden() const {
    preorden(raiz);
}

void ArbolDecision::preorden(NodoDecision* nodo) const {
    if (nodo == nullptr) {
        return;
    }

    cout << nodo->getDescripcion() << endl;

    preorden(nodo->getIzquierdo());

    preorden(nodo->getDerecho());
}

void ArbolDecision::postorden() const {
    postorden(raiz);
}

void ArbolDecision::postorden(NodoDecision* nodo) const {
    if (nodo == nullptr) {
        return;
    }

    postorden(nodo->getIzquierdo());

    postorden(nodo->getDerecho());

    cout << nodo->getDescripcion() << endl;
}

void ArbolDecision::liberar(NodoDecision* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberar(nodo->getIzquierdo());

    liberar(nodo->getDerecho());

    delete nodo;
}

void ArbolDecision::clear() {
    liberar(raiz);
    raiz = nullptr;
}