#include "Personaje.h"
#include <iostream>
using namespace std;

//Sobrecarga del operador "<<" para poder utilizar cout
ostream& operator<<(ostream& output, const Personaje& arr) {
    output<<arr.getNombre();
    return output;
}

Personaje::Personaje() {
    this->vida = 0;
    this->nivel = 0;
    this->nombre = " ";
    this->tipo = " ";
    this->especie = " ";
}

Personaje::Personaje(std::string nombre, std::string tipo, std::string especie, int vida, int nivel) {
    this->vida = vida;
    this->nivel = nivel;
    this->nombre = nombre;
    this->tipo = tipo;
    this->especie = especie;
}

Personaje::Personaje(const Personaje& o) {
    vida = o.vida;
    nivel = o.nivel;
    nombre = o.nombre;
    tipo = o.tipo;
    especie = o.especie;
}

void Personaje::setVida(int vida) {
    this->vida = vida;
}

void Personaje::setNivel(int nivel) {
    this->nivel = nivel;
}

void Personaje::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Personaje::setTipo(std::string tipo) {
    this->tipo = tipo;
}

void Personaje::setEspecie(std::string especie) {
    this->especie = especie;
}

int Personaje::getVida() const {
    return vida;
}

int Personaje::getNivel() const {
    return nivel;
}

std::string Personaje::getNombre() const {
    return nombre;
}

std::string Personaje::getTipo() const {
    return tipo;
}

std::string Personaje::getEspecie() const {
    return especie;
}

void Personaje::mostrarPersonaje() const {
    std::cout << "Nombre: " << nombre << " | ";
    std::cout << "Especie: " << especie << " | ";
    std::cout << "Tipo: " << tipo << " | ";
    std::cout << "Vida: " << vida << " | ";
    std::cout << "Nivel: " << nivel << std::endl;
}
