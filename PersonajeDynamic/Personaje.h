#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <string>

class Personaje{
    private:
        std::string nombre,tipo,especie;
        int vida,nivel;
    public:
        Personaje(){
            this->vida=0;
            this->nivel=0;
            this->nombre=" ";
            this->tipo=" ";
            this->especie=" ";
        }
        Personaje(std::string nombre, std::string tipo, std::string especie, int vida, int nivel){
            this->vida=vida;
            this->nivel=nivel;
            this->nombre=nombre;
            this->tipo=tipo;
            this->especie=especie;
        }
        Personaje(const Personaje &o){
            vida = o.vida;
            nivel = o.nivel;
            nombre = o.nombre;
            tipo = o.tipo;
            especie = o.especie;
        }

        void setVida(int vida){
            this->vida=vida;
        }

        void setNivel(int nivel){
            this->nivel=nivel;
        }

        void setNombre(std::string nombre){
            this->nombre=nombre;
        }

        void setTipo(std::string tipo){
            this->tipo=tipo;
        }
        
        void setEspecie(std::string especie){
            this->especie=especie;
        }

        int getVida()const{
            return vida;
        }

        int getNivel()const{
            return nivel;
        }

        std::string getNombre()const{
            return nombre;
        }

        std::string getTipo()const{
            return tipo;
        }

        std::string getEspecie()const{
            return especie;
        }

        void mostrarPersonaje()const{
            std::cout <<"Nombre: "<<nombre<<" | ";
            std::cout <<" Especie: "<<especie<<" | ";
            std::cout <<" Tipo: "<<tipo<<" | ";
            std::cout <<" Vida: "<<vida<<" | ";
            std::cout <<" Nivel: "<<nivel<<std::endl;
        }
        
};
#endif