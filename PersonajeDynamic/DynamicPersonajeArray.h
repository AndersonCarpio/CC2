#ifndef DYNAMICPERSONAJEARRAY_H
#define DYNAMICPERSONAJEARRAY_H

#include "Personaje.h"

class DynamicPersonajeArray{
    private:
        Personaje *data;
        int size;
    public:
        DynamicPersonajeArray(){
            this->size=0;
            data = new Personaje[0];
        }

        DynamicPersonajeArray(Personaje arr[], int size){
            this->size=size;
            data = new Personaje[size];
            for( int i=0; i<size ; i++)
                data[i] = arr[i];
        }

        DynamicPersonajeArray(const DynamicPersonajeArray &o){
            this->size=size;
            data = new Personaje[o.size];
            for (int i = 0; i<size ; i++)
                data[i] = o.data[i];

        }

        void print(){
            for (int i = 0; i<size; i++){
                std::cout << "[ Personaje " << i<< std::endl;
                data[i].mostrarPersonaje();
                std::cout << "]"<< std::endl;
            }
         }

         void insert(Personaje perso, int pos){
            size++;
            Personaje* newData = new Personaje[size];
            for(int i=0; i<pos; i++)
                newData[i]=data[i];
            newData[pos]=perso;
            for(int i=pos+1;i<size;i++)
                newData[i]=data[i-1];
            delete[] data;
            data=newData;

         }

         void pushBack(Personaje perso){
            size++;
            Personaje* newData = new Personaje[size];
            for (int i=0; i<size-1; i++)
                newData[i] = data[i];
            newData[size-1] = perso;
            delete[] data;
            data = newData;

         }

         void remove(int pos){
            size--;
            Personaje* newData = new Personaje[size];
            for(int i = 0; i<pos; i++)
                newData[i] = data[i];
            for(int i = pos;i<size; i++)
                newData[i] = data[i+1];
            delete[] data;
            data=newData;
            
         }



         ~DynamicPersonajeArray(){
            delete[] data;
         }

};

#endif