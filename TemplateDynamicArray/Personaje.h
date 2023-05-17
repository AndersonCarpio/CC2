#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

class Personaje {
friend std::ostream& operator<<(std::ostream&, const Personaje&);

private:
    std::string nombre, tipo, especie;
    int vida, nivel;

public:
    Personaje();
    Personaje(std::string nombre, std::string tipo, std::string especie, int vida, int nivel);
    Personaje(const Personaje& o);

    void setVida(int vida);
    void setNivel(int nivel);
    void setNombre(std::string nombre);
    void setTipo(std::string tipo);
    void setEspecie(std::string especie);

    int getVida() const;
    int getNivel() const;
    std::string getNombre() const;
    std::string getTipo() const;
    std::string getEspecie() const;

    void mostrarPersonaje() const;
};

#endif
