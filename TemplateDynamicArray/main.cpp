#include "DynamicArray.cpp"
#include "Personaje.cpp"

using namespace std;

int main(){
    DynamicArray<int> t1;
    //CREANDO DISTINTOS TIPOS DE ARRAY PARA PROBAR
    //LOS TEMPLATES, INCLUYENDO UNA CLASE "PERSONAJE"

    int arrInt[4]={1,2,3,4};
    float arrFloat[4]={1.1,2.2,3.3,4.4};

    //VAMOS A CREAR 3 OBJETOS PERSONAJE PARA PODER
    //INCLUIRLOS AL ARRAY DE PERSONAJES
    Personaje p1("Andre","magico","humano",10,100);
    Personaje p2("Arturo","fisico","humano",20,200);
    Personaje p3("Daniel","legendario","dios",30,300);
    Personaje p4("Camila","divino","diosa", 20, 20);
    Personaje p5("Ana","distancia","quimera",10,10);
    Personaje arrPersonaje[3]={p1,p2,p3};

    //DECLARACION OBJETO DYNAMICARRAY DE TIPO INT
    //Y COMPROBANDO INSERT,PUSHBACK Y REMOVE

    DynamicArray<int> dynArrInt(arrInt,4);
    cout<<"Imprimiendo DynamicArray de tipo int: "<<endl;
    dynArrInt.print();
    cout<<"Insertando un int=3 en pos=2 e imprimiendo: "<<endl;
    dynArrInt.insert(3,2);
    dynArrInt.print();
    cout<<"Pushback de int=5 e imprimiendo"<<endl;
    dynArrInt.pushBack(5);
    dynArrInt.print();
    cout<<"Removiendo int de la pos=0 e imprimiendo"<<endl;
    dynArrInt.remove(0);
    dynArrInt.print();

    //DECLARACION OBJETO DYNAMICARRAY DE TIPO FLOAT
    //Y COMPROBANDO INSERT,PUSHBACK Y REMOVE

    DynamicArray<float> dynArrFloat(arrFloat,4);
    cout<<"Imprimiendo DynamicArray de tipo float: "<<endl;
    dynArrFloat.print();
    cout<<"Insertando un float=5.5 en pos=2 e imprimiendo: "<<endl;
    dynArrFloat.insert(5.5,2);
    dynArrFloat.print();
    cout<<"Pushback de float=6.6 e imprimiendo"<<endl;
    dynArrFloat.pushBack(6.6);
    dynArrFloat.print();
    cout<<"Removiendo int de la pos=0 e imprimiendo"<<endl;
    dynArrFloat.remove(0);
    dynArrFloat.print();

    //DECLARACION OBJETO DYNAMICARRAY DE TIPO PERSONAJE
    //Y COMPROBANDO INSERT,PUSHBACK Y REMOVE

    DynamicArray<Personaje> dynArrPer(arrPersonaje,3);
    cout<<"Imprimiendo DynamicArray de tipo Personaje: "<<endl;
    dynArrPer.print();
    cout<<"Insertando un Personaje=4 en pos=1 e imprimiendo: "<<endl;
    dynArrPer.insert(p4,1);
    dynArrPer.print();
    cout<<"Pushback de Personaje=p5 e imprimiendo"<<endl;
    dynArrPer.pushBack(p5);
    dynArrPer.print();
    cout<<"Removiendo Personaje de la pos=0 e imprimiendo"<<endl;
    dynArrPer.remove(0);
    dynArrPer.print();


    return 0;



}